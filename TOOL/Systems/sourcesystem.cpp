#include "sourcesystem.h"
#include "../EngineTool/enginechecktool.h"


unsigned int SourceSystem::m_globalId=1;
SourceSystem* SourceSystem::m_instance=nullptr;
GameDemo * SourceSystem::m_nowDemo=nullptr;
QMap<unsigned int,GameObject* > SourceSystem::m_gameObjectDictionary{};
QMap<QString,GameObject*> SourceSystem::m_gameObjectSampleDictionary{};
QSet<QString> SourceSystem::m_gameObjectClassSet{};
QSet<QString> SourceSystem::m_componentClassSet{};
SourceSystem *SourceSystem::getInstance(QObject *parent )
{
    if(m_instance==nullptr)
    {
        m_instance=new SourceSystem(parent);
    }
    return m_instance;
}

bool SourceSystem::systemStart()
{
#ifdef QDEBUGCHECK
    qDebug()<<"SourceSystem::systemStart | √ ";
#endif
    return true;
}

bool SourceSystem::systemInit()
{
#ifdef QDEBUGCHECK
    qDebug()<<"SourceSystem::systemInit | √ ";
#endif


    connect(this,&SourceSystem::sourceLoadDemo,this,[](GameDemo* demo){
        setNowDemo(demo);
    });

    return true;
}

bool SourceSystem::systemClose()
{
    return true;
}

int SourceSystem::loadProjectFile(QString projectFilePath)
{
    //判断格式
    auto pathList = projectFilePath.split(".");
    if(pathList[pathList.size()-1]!="auraproj")
    {
        //格式错误
        return -1;
    }
    /*
     * 项目文件信息
    x1.项目创建日期
    2.项目名
    3.项目使用模板
    4.项目数据文件位置
    x5.校验许可-MD5值（用于验证工程是否被篡改）
    */

    QFile file(projectFilePath);
    if(!file.open(QIODevice::Text | QIODevice::ReadOnly))
    {
        //读取失败
        return -1;
    }
    QTextStream in(&file);
    QString projectName, projectTemplate, projectDataFile;
    if (!in.atEnd()) {
        projectName = in.readLine();
        projectTemplate = in.readLine();
        projectDataFile = in.readLine();
    }
    // 打印读取的内容
    qDebug() << "项目名: " << projectName;
    qDebug() << "项目模板: " << projectTemplate;
    qDebug() << "项目数据文件位置: " << projectDataFile;

    file.close();
    return 0;
}

int SourceSystem::loadDemoConfigFile(QString configFilePath)
{
    //判断格式
    auto pathList = configFilePath.split(".");
    if(pathList[pathList.size()-1]!="json")
    {
        //格式错误
        return -1;
    }

    QFile file(configFilePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        //读取失败
        return -1;
    }

    QByteArray data =file.readAll();
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data,&parseError);
    if(parseError.error!=QJsonParseError::NoError || doc.isNull()||!doc.isObject())
    {
        //json文件格式不对
        return -1;
    }
    QJsonObject root =doc.object();

    QString demoClass = root.value("Class").toString();

    auto demo = Factory<GameDemo,QObject*>::GetInstance()->CreateClass(demoClass.toStdString(),getInstance()->parent());

    if(!demo)
    {
        //引擎未搭载该demo
        return -1;
    }


    QJsonObject  dataObj = root.value("Data").toObject();
    GameDemo::setNowDemo(m_nowDemo);
    demo->initDemo(dataObj);

    //可以不在这里进行释放 而是通过下面的信号进行响应式处理
    if(m_nowDemo)
    {
        //释放原先的
        delete m_nowDemo;
        m_nowDemo =nullptr;
    }

    getInstance()->emit sourceLoadDemo(demo);
}

bool SourceSystem::registGameObjectClass(QString objClassName)
{
    bool res =m_gameObjectClassSet.contains(objClassName);

    if(!res)
    {
        m_gameObjectClassSet.insert(objClassName);
        GameObject* sampleObj = Factory<GameObject,QObject*>::GetInstance()->CreateClass(objClassName.toStdString(),nullptr);
        sampleObj->initObject();
        m_gameObjectSampleDictionary.insert(objClassName,sampleObj);
    }

    return res;
}

bool SourceSystem::registComponentClass(QString componentClassName)
{
    bool res =m_componentClassSet.contains(componentClassName);

    if(!res)
    {
        m_componentClassSet.insert(componentClassName);
    }
    return res;
}

bool SourceSystem::registDemoClass(QString demoClassName)
{
    bool res = true;
    return res;
}

QSet<QString> SourceSystem::componentClassSet()
{
    return m_componentClassSet;
}

GameObject *SourceSystem::getGameObjectSample(QString className)
{
    return m_gameObjectSampleDictionary[className];
}

GameObject *SourceSystem::createGameObjectSample(QString className)
{
    bool res =m_gameObjectClassSet.contains(className);
    if(!res)
    {
        m_gameObjectClassSet.insert(className);

        GameObject* obj=Factory<GameObject,QObject*>::GetInstance()->CreateClass("GameObject",nullptr);
        obj->initObject();

        m_gameObjectSampleDictionary.insert(className,obj);
        return obj;
    }
    return nullptr;
}

void SourceSystem::cleanNowDemo()
{

}

QSet<QString> SourceSystem::gameObjectClassSet()
{
    return m_gameObjectClassSet;
}

unsigned int SourceSystem::globalId()
{
    return m_globalId;
}

bool SourceSystem::registDemo(GameDemo *demo)
{
    bool res = true;

    //当前处理该demo
    //setNowDemo(demo);

    // 1. 类注册   --反射信息注册
    // 注册Demo
    registDemoClass(demo->objectName());

    // 注册GameObject
    for(auto it: demo->objectClassList())
    {
        registGameObjectClass(it);
    }

    // 注册Component
    for(auto it: demo->componentClassList())
    {
        registComponentClass(it);
    }

    //2. 资产注册
    for(auto it:demo->objectList())
    {
        registerGameObject(it);
    }

    emit m_instance->sourceReflexUpdated();
    return res;
}

bool SourceSystem::registerGameObject(GameObject *obj)
{
    bool res=true;

    unsigned int id=obj->id();

    if(id==0)
    //代表未注册/未初始化 =========》进行注册（仅针对GO来说的注册）
    {
        registerGameObjectId(obj);
        m_nowDemo->updateGameObjectDictionary(0,obj);
    }
    else
    {
        updateSourceId(id);
    }
    res = addGameObject(obj);

    return res;
}

void SourceSystem::initGameObjectList(GameDemo *demo)
{

    /*+++++++Demo 中有含对GO的管理模块， 尝试不用对引擎的资源系统进行注册+++++++*/
    // 但是编辑区需要拿到加载的Demo 所以还是需要注册
    //  暂不用该函数
    Q_UNUSED(demo)
    /*+++++++Demo 中有含对GO的管理模块， 尝试不用对引擎的资源系统进行注册+++++++*/
}

void SourceSystem::setNowDemo(GameDemo *demo)
{

    if(demo)
    {
        if(m_nowDemo && !(demo == m_nowDemo) )
        {
            cleanNowDemo();
        }
        m_nowDemo = demo;
        //切换demo后，将清空 demo资源相关文件 ，以便重新注册
        m_gameObjectDictionary.clear();

        registDemo(demo);
    }

}

bool SourceSystem::addGameObject(GameObject *obj)
{
    /*
    添加管理的GameObject
    1. 将obj添加进字典中
    */
    bool res=false;

    //1. 将obj添加进字典中
    auto objId=obj->id();
    if(m_gameObjectDictionary.contains(objId))
    {
#ifdef QDEBUGCHECK
        qDebug()<<"SourceSystem::addGameObject | have this id:"<<objId<<" by "<<obj->name();
#endif
        return res;
    }
    m_gameObjectDictionary.insert(objId,obj);
    res=true;

    emit m_instance->sourceGameObjectUpdated();
    return res;
}

void SourceSystem::addGameObjectFromSample(QString className)
{
    GameObject* objSample = getGameObjectSample(className);
    if(objSample)
    {
        EngineCheckTool::checkGameObject(objSample);
        GameObject* newObj =Factory<GameObject,QObject*>::GetInstance()->CreateClassByCopy(className.toStdString(),*objSample);
        registerGameObjectId(newObj);
        addGameObject(newObj);
        EngineCheckTool::checkGameObject(newObj);
        if(m_nowDemo)
        {
            m_nowDemo->addGameObject(newObj);
            m_nowDemo->updateItem(newObj);
            emit m_instance->sourceGameObjectUpdated();
            emit m_instance->sourceNeedUpdateView();
        }
    }
#ifdef QDEBUGCHECK
    qDebug()<<"SourceSystem::addGameObjectFromSample | end. checkNow Dictionary:"<<m_gameObjectDictionary;
#endif
}

GameObject *SourceSystem::getGameObjectById(unsigned int id)
{
    GameObject* obj=nullptr;
    auto it=m_gameObjectDictionary.find(id);
    if(it != m_gameObjectDictionary.end())
    {
        obj=it.value();
    }
    else
    {
#ifdef QDEBUGCHECK
        qDebug()<<"SourceSystem::getGameObjectById | no have this obj:"<<id;
        qDebug()<<"SourceSystem::getGameObjectById | now Dictionary:"<<m_gameObjectDictionary;
#endif
    }
    return obj;
}

QMetaProperty SourceSystem::getComponentMetaProperty(QString componentName,QString propertyName)
{
    const QMetaObject * metaObj=Factory<ComponentObject>::GetInstance()
                                     ->CreateClass(componentName.toStdString())
                                     ->metaObject();
    int index=metaObj->indexOfProperty(propertyName.toStdString().c_str());
    if(index!=-1)
        return metaObj->property(metaObj->indexOfProperty(propertyName.toStdString().c_str()));
    else
    {
#ifdef QDEBUGCHECK
        qDebug()<<"SourceSystem::getComponentMetaProperty | "<<componentName<< " no have this property:"<<propertyName;
#endif
        return metaObj->property(0);
    }
}

QVector<GameObject *> SourceSystem::gameObjectList()
{
    return m_gameObjectDictionary.values();
}

void SourceSystem::updateSourceId(unsigned int registerId)
{
    m_globalId=qMax(registerId+1,m_globalId);
}

void SourceSystem::registerGameObjectId(GameObject *obj)
{
    obj->setId(m_globalId);
    updateSourceId(obj->id());
}

SourceSystem::SourceSystem(QObject *parent)
    : SystemObject{parent}
{
    setObjectName("SourceSystem");
}
