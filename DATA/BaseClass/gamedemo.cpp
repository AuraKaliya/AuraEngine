#include "gamedemo.h"

GameDemo* GameDemo::m_nowDemo=nullptr;
GameDemo::GameDemo(QObject *parent)
    : QObject{parent},m_sceneCount(1),m_initFlag(false),m_quitFlag(false),m_exitFunctionFlag(false)
{

}

GameDemo::~GameDemo()
{

}

void GameDemo::setNowDemo(GameDemo *demo)
{
    m_nowDemo=demo;
}

GameDemo *GameDemo::nowDemo()
{
    return m_nowDemo;
}

void GameDemo::initDemo(const QJsonObject &obj)
{

////====================================================
    QString demoName = obj.value("DemoName").toString();

    setObjectName(demoName);
////####################################################
////====================================================
    QStringList demoSystemList;
    auto demoSystemDataArray =obj.value("DemoSystems").toArray();
    for(auto it: demoSystemDataArray)
    {
        demoSystemList.append(it.toString());
    }
////####################################################
////====================================================
    QStringList demoInsFunctionList;
    auto demoInsFunctionDataArray =obj.value("DemoInsFunctions").toArray();
    for(auto it: demoInsFunctionDataArray)
    {
        demoInsFunctionList.append(it.toString());
    }
////####################################################
////====================================================
    QStringList gameObjectTypeList;
    auto gameObjectTypeDataArray =obj.value("GameObjectTypes").toArray();
    for(auto it : gameObjectTypeDataArray)
    {
        gameObjectTypeList.append(it.toString());
    }
////####################################################
////====================================================
    QStringList componentTypeList;
    auto componentTypeDataArray =obj.value("ComponentTypes").toArray();
    for(auto it : componentTypeDataArray)
    {
        componentTypeList.append(it.toString());
    }
////####################################################
////====================================================
    auto gameObjectDataArray = obj.value("GameObjectList").toArray();
    //GameObject列表
    for(auto objIter : gameObjectDataArray)
    {
        QJsonObject objData = objIter.toObject();
        QString className = objData.value("Class").toString();

        //构建GameObject对象
        auto gameObj = Factory<GameObject,QObject*>::GetInstance()->CreateClass(className.toStdString(),this);
        if(!gameObj)
        {
#ifdef QDEBUGCHECK
            qDebug()<<"TestDemo::initDemo | no have this obj:"<<className;
#endif
            continue;
        }
        gameObj->initObject(objData);
        addGameObject(gameObj);
        for(auto it : gameObj->items())
        {
            m_itemList.append(it);
        }
    }
////####################################################
    auto sceneDataArray =obj.value("SceneList").toArray();
    for(auto it :sceneDataArray)
    {
        QJsonObject sceneObjData =it.toObject();
        auto RectArray =sceneObjData.value("Rect").toArray();
        if(RectArray.size()==4)
        {
            m_sceneRectList.append({RectArray[0].toDouble(),RectArray[1].toDouble(),
                                    RectArray[2].toDouble(),RectArray[3].toDouble()});
        }
    }

#ifdef QDEBUGCHECK
    qDebug()<<"TestDemo::initDemo | check 0====================";

    qDebug()<<"demoName |"<<demoName;
    qDebug()<<"demoSystemList | "<<demoSystemList;
    qDebug()<<"demoInsFunctionList | "<<demoInsFunctionList;
    qDebug()<<"gameObjectTypeList | "<<gameObjectTypeList;
    qDebug()<<"componentTypeList | "<<componentTypeList;
    qDebug()<<"init end | gameObj List:"<<m_gameObjectDictionary;
    qDebug()<<"init end | demoFunction List:"<<m_insFunctionList;
    qDebug()<<"TestDemo::initDemo | check 0====================end";
#endif

}

QJsonObject GameDemo::getDemoSource() const
{
    QJsonObject obj;
    return obj;
}

void GameDemo::updateDemo()
{
    //双缓冲   读取的始终是preInfoPool通过每次update进行  切换
    m_preInfoPool=m_infoPool;
    // 重置消息池
    m_infoPool.clear();

    //读取消息池的内容
    if(!m_preInfoPool.isEmpty())
    {
        //这里是按照map的自有顺序进行的tick/update  可通过sortList来改变
        for(auto it=m_preInfoPool.begin();it!=m_preInfoPool.end();++it)
        {
            for(auto obj:it.value())
            {
                m_demoSystemDictionary[it.key()]->update(*obj);
            }
        }
    }
    else
    {
#ifdef QDEBUGCHECK
        qDebug()<<"TestDemo::updateDemo | Now no have info.";
#endif
    }


    if(m_exitFunctionFlag && m_exitFunction())
    {
        m_quitFlag=true;
    }

}

void GameDemo::updateRender()
{

}

void GameDemo::updateItem(GameObject *newGameObject)
{

}

void GameDemo::initDemoClassInfo(QVector<QString> objClassList, QVector<QString> componentClassList)
{
    m_objectClassList=objClassList;
    m_componentClassList=componentClassList;
}

void GameDemo::addObjClass(QString objClass)
{
    m_objectClassList.append(objClass);
}

void GameDemo::addComponentClass(QString componentClass)
{
    m_componentClassList.append(componentClass);
}

void GameDemo::addInsFunction(QString insName, InsFunction insFunc)
{
    m_insFunctionList.append(QPair<QString,InsFunction>(insName,insFunc));
    InstructionFunctionInfomation insFuncInfo(insName,"Function");
    m_insFunctionInfoList.append(insFuncInfo);
}

void GameDemo::addInsFunction(QString insName,InsFunction insFunc,const QVector<QString>&argTip)
{
    m_insFunctionList.append(QPair<QString,InsFunction>(insName,insFunc));

    InstructionFunctionInfomation insFuncInfo(insName,"Function",argTip.size());
    insFuncInfo.setTips(argTip);

    m_insFunctionInfoList.append(insFuncInfo);
}

void GameDemo::linkObjectToSystem(GameObject *obj, QString systemClass, QString otherInfo)
{

}

void GameDemo::linkView(QVector<QGraphicsScene*> sceneList)
{
#ifdef QDEBUGCHECK
    qDebug()<<"GameDemo::linkView | sceneList size:"<<sceneList.size() <<" m_itemList size"<<m_itemList.size();
#endif
    for(auto it:m_itemList)
    {
        int index=it->sceneIdx();
#ifdef QDEBUGCHECK
        qDebug()<<"GameDemo::linkView | index:"<< index;
#endif
        QGraphicsScene* scene =sceneList[index];
        QRectF sceneRect=m_sceneRectList[index];
        scene->setSceneRect(sceneRect);
        scene->addItem(it);
    }
    //view->update();
}

void GameDemo::updateView(QVector<QGraphicsScene*> sceneList)
{
#ifdef QDEBUGCHECK
    qDebug()<<"GameDemo::updateView | check 0:";
    for(auto it: sceneList[0]->items())
    {
        qDebug()<<" it : "<<it << it->isVisible() << " | " << it->boundingRect();
    }
#endif

    for(auto it: m_newItemList)
    {
        int index=it->sceneIdx();
#ifdef QDEBUGCHECK
        qDebug()<<"GameDemo::updateView | index:"<< index;
#endif
        QGraphicsScene* scene =sceneList[index];
        QRectF sceneRect=m_sceneRectList[index];
        scene->setSceneRect(sceneRect);
        scene->addItem(it);
        m_itemList.append(it);
    }
#ifdef QDEBUGCHECK
    qDebug()<<"GameDemo::updateView | check 1:";
    for(auto it: sceneList[0]->items())
    {
        qDebug()<<" it : "<<it << it->isVisible() << " | " << it->boundingRect();
    }
#endif
    m_newItemList.clear();
}

bool GameDemo::initFlag() const
{
    return m_initFlag;
}

bool GameDemo::quitFlag() const
{
    return m_quitFlag;
}

int GameDemo::sceneCount() const
{
    return m_sceneCount;
}

void GameDemo::setSceneCount(int newSceneCount)
{
    if (m_sceneCount == newSceneCount)
        return;
    m_sceneCount = newSceneCount;
    emit sceneCountChanged();
}

QVector<ScriptObjectLua *> GameDemo::scriptsList() const
{
    return m_scriptsList;
}

void GameDemo::addScript(ScriptObjectLua *script)
{
    m_scriptsList.append(script);
}

QVector<QString> GameDemo::objectClassList() const
{
    return m_objectClassList;
}

QVector<QString> GameDemo::componentClassList() const
{
    return m_componentClassList;
}

QVector<QPair<QString, InsFunction> > GameDemo::insFunctionList() const
{
    return m_insFunctionList;
}

QVector<GameObject *> GameDemo::objectList()
{
    return m_gameObjectDictionary.values();
}

QMultiMap<unsigned int, GameObject *> GameDemo::gameObjectDictionary() const
{
    return m_gameObjectDictionary;
}

void GameDemo::updateGameObjectDictionary(unsigned int oldId, GameObject *obj)
{
    m_gameObjectDictionary.remove(oldId,obj);
    m_gameObjectDictionary.insert(obj->id(),obj);
}

void GameDemo::resetGameObjectDictionary()
{
    auto list=m_gameObjectDictionary.values();
    m_gameObjectDictionary.clear();

    for(int i=0;i<list.size();++i)
    {
        list[i]->setId(i);
        m_gameObjectDictionary.insert(i,list[i]);
    }
}

QVector<InstructionFunctionInfomation> GameDemo::insFunctionInfoList() const
{
    return m_insFunctionInfoList;
}

void GameDemo::setExitFunction(DemoExitFunction& newExitFunction)
{
    m_exitFunction = newExitFunction;
    m_exitFunctionFlag=true;
}

bool GameDemo::exitFunctionFlag() const
{
    return m_exitFunctionFlag;
}
