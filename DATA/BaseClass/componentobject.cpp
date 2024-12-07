#include "componentobject.h"
#include "gameobject.h"

ComponentObject::ComponentObject(QObject *parent)
    : QObject{parent}
    ,m_initFlag(false)
    ,m_linkFlag(false)
    ,m_delayInitFlag(false)
    ,m_delayPropertyMap{}
    ,m_linkObj(static_cast<GameObject*>(parent))
    ,m_typeId(typeid(decltype(*this)).name())
{
    //qDebug()<<"check m_typeid :"<<m_typeId <<" |typeid:"<< typeid(ComponentObject).name();
    //qDebug()<<"check typeid == m_typeid:"<<(m_typeId == typeid(ComponentObject).name());

    setObjectName("Default");
    if(parent)
    {
        m_linkFlag =true;
    }
}

ComponentObject::ComponentObject(ComponentObject &other)
{
    qDebug()<<"ComponentObject | copy~ "<<this;
    //setObjectName(obj.objectName());
    //copy property
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

    //m_initFlag= false;
    m_linkObj =nullptr;
}

ComponentObject::~ComponentObject()
{

}

QJsonObject ComponentObject::getMetaData() const
{
    QJsonObject obj;
    return obj;
}

void ComponentObject::setLinkObj(GameObject *obj)
{
    m_linkObj=obj;

    if(obj!= nullptr)
    {
        m_linkFlag =true;
    }
    else
    {
        m_linkFlag=false;
    }

}

void ComponentObject::initComponent(const QJsonObject &obj)
{

#ifdef QDEBUGCHECK
    qDebug()<<"ComponentObject::initComponent| obj:"<<this <<"ComponentName:"<<objectName();
#endif

}

GameObject *ComponentObject::getLinkObj()
{
    return m_linkObj;
}

bool ComponentObject::initFlag() const
{
    return m_initFlag;
}

void ComponentObject::setInitFlag(bool newInitFlag)
{
    m_initFlag = newInitFlag;
}

QString ComponentObject::typeId() const
{
    return m_typeId;
}

QString ComponentObject::className() const
{
    return m_className;
}

void ComponentObject::setClassName(const QString &newClassName)
{
    if (m_className == newClassName)
        return;
    m_className = newClassName;
    emit classNameChanged();
}

bool ComponentObject::delayInitFlag() const
{
    return m_delayInitFlag;
}

void ComponentObject::setDelayInitFlag(bool newDelayInitFlag)
{
    m_delayInitFlag = newDelayInitFlag;
}

QVector<QString> ComponentObject::getDelayPropertyList()
{
    return m_delayPropertyMap.keys();
}

QString ComponentObject::getDelayPropertyValue(const QString &key) const
{
    return m_delayPropertyMap[key];
}


