#include "gameobject.h"
#include "objectitem.h"
#include <QMetaProperty>

bool GameObject::m_registFlag=false;
bool GameObject::m_itemFlag=false;
GameObject::GameObject(/*bool initByJsonFlag,*/ QObject *parent)
    : QObject{parent},m_id(0),m_objClass("GameObject"),m_name("Default")
    ,m_componentAutoDictionary{}/*,m_initByJsonFlag(initByJsonFlag)*/
    ,m_delayInitFlag(false)
{

}

GameObject::GameObject(GameObject &other)
{
    //copy property
    // GO 和 component的这个属性的拷贝过程貌似可以提出来到TOOL中
    const QMetaObject *metaObj = other.metaObject();
    int count =metaObj -> propertyCount();
    for(int i=0;i<count;++i)
    {
        QMetaProperty metaProperty=metaObj->property(i);
        if(metaProperty.isReadable() && metaProperty.isWritable())
        {
            QVariant value =other.property(metaProperty.name());
            this->setProperty(metaProperty.name(),value);
        }
    }

    //copy dictionary
    for(auto it=other.m_componentAutoDictionary.begin();it!=other.m_componentAutoDictionary.end();++it)
    {
        ComponentObject* component =Factory<ComponentObject>::GetInstance()->CreateClassByCopy(it.value()->objectName().toStdString(),*it.value());
        component->setLinkObj(this);
        component->setParent(this);
        m_componentAutoDictionary.insert(it.key(),component);
    }

}

void GameObject::initObject(const QJsonObject &objData)
{

//GameObject 基础属性 ： name id class

#ifdef QDEBUGCHECK
    qDebug()<<"GameObject::initObject(objData)| obj:"<<this;
#endif
    QString objClass =  objData.value("Class").toString();
    QString name = objData.value("Name").toString();
    unsigned int id = objData.value("Id").toInt();
    setObjClass(objClass);
    setId(id);
    setName(name);

    //Component
    auto componentDataArray = objData.value("Component").toArray();
    for(auto comIter:componentDataArray)
    {
        QJsonObject comData =comIter.toObject();
        QString className = comData.value("Class").toString();

        auto* component = Factory<ComponentObject>::GetInstance()->CreateClass(className.toStdString());
        if(!component)
        {
#ifdef QDEBUGCHECK
            qDebug()<<"GameObject::initObject(objData)| no have this component:"<<className;
#endif
            continue;
        }
        component->setLinkObj(this);
        component->initComponent(comData);

        //若包含有需要延迟处理的组件，则该GameObject也应设为延迟处理。
        if(component->delayInitFlag())
        {
            setDelayInitFlag(true);
        }
#ifdef QDEBUGCHECK
        qDebug()<<"GameObject::initObject(objData)| check### typeid:"<<component->typeId();
#endif
        addComponent(component->typeId(),component);
    }



}

void GameObject::initObject()
{
#ifdef QDEBUGCHECK
    qDebug()<<"GameObject::initObject( )| obj:"<<this;
#endif

}

QJsonObject GameObject::getMetaData() const
{
    QJsonObject obj;
    return obj;
}

QVector<ObjectItem *> GameObject::items()
{
    return {};
}

int GameObject::id() const
{
    return m_id;
}

void GameObject::setId(int newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    emit idChanged();
}

QString GameObject::objClass() const
{
    return m_objClass;
}

void GameObject::setObjClass(const QString &newObjClass)
{
    if (m_objClass == newObjClass)
        return;
    m_objClass = newObjClass;
    emit objClassChanged();
}

QString GameObject::name() const
{
    return m_name;
}

void GameObject::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

void GameObject::addComponent(QString comTypeId, ComponentObject *component)
{
    m_componentAutoDictionary[comTypeId]=component;
}

ComponentObject *GameObject::getComponent(QString commponentClass)
{
    return m_componentAutoDictionary[commponentClass];
}

QVector<ComponentObject *> GameObject::getComponetList()
{
    return m_componentAutoDictionary.values();
}

bool GameObject::delayInitFlag() const
{
    return m_delayInitFlag;
}

void GameObject::setDelayInitFlag(bool newDelayInitFlag)
{
    m_delayInitFlag = newDelayInitFlag;
}

bool GameObject::itemFlag()
{
    return m_itemFlag;
}
