#include "model2dcollision.h"


Model2DCollision::Model2DCollision(CollisionType type, QObject *parent)
    : ComponentObject{parent},m_checkDictionary{
          {CollisionType::Trigger,{}},{CollisionType::Getter,{}}
      },
    m_collisionType(type),m_collisionState(Model2DCollision::CollisionState::NoCollision),m_collisionStratagy(Model2DCollision::CollisionStratagy::Rigid)
{
    REGISTER_TYPEID
    setObjectName("Model2DCollision");
}

//Model2DCollision::Model2DCollision(Model2DCollision &other)
//{
//    //copy property
//    const QMetaObject *metaObj = other.metaObject();
//    int count =metaObj -> propertyCount();
//    for(int i=0;i<count;++i)
//    {
//        QMetaProperty metaProperty=metaObj->property(i);
//        if(metaProperty.isReadable() && metaProperty.isWritable())
//        {
//            QVariant value =other.property(metaProperty.name());
//            this->setProperty(metaProperty.name(),value);
//        }
//    }

//    //m_initFlag= false;
//    m_linkObj =nullptr;
//}

QJsonObject Model2DCollision::getMetaData() const
{
    return QJsonObject();
}

void Model2DCollision::initComponent(const QJsonObject &obj)
{
    ComponentObject::initComponent(obj);

    //get Value
    auto collitionTypeValue  = obj.value("CollisionType").toString();
    auto getterFunctionValue = obj.value("GetterFunction").toString();

    QVector<unsigned int> getterIdList ;
    if(obj.contains("GetterIdList"))
    {
        auto list = obj.value("GetterIdList").toArray();
        for(auto it:list)
        {
            getterIdList.append(it.toInt());
        }
    }

    //set Value
    if(collitionTypeValue == "G")
    {
        setCollisionType(Getter);
    }
    else if (collitionTypeValue == "S")
    {
        setCollisionType(Trigger);
    }

    //other
    if(m_linkFlag)
    {
        setDelayInitFlag(true);

        m_delayPropertyMap["CollisionType"]=collitionTypeValue;
        m_delayPropertyMap["GetterFunction"]=getterFunctionValue;

        QStringList getterIdListStrList;
        for(auto it :getterIdList)
        {
            getterIdListStrList.append(QString::number(it));
        }
        QString getterIdListStr=getterIdListStrList.join(",");

        m_delayPropertyMap["GetterIdList"]=getterIdListStr;
    }
    else
    {
#ifdef QDEBUGCHECK
        qDebug()<<"Model2DCollision::initComponent | warning: "<<this<<" no have link obj.";
#endif
    }
}

QVector<GameObject *> Model2DCollision::getTriggers()
{
    return m_checkDictionary[CollisionType::Trigger];
}

QVector<GameObject *> Model2DCollision::getGetters()
{
    return m_checkDictionary[CollisionType::Getter];
}

void Model2DCollision::addTrigger(GameObject *obj)
{
    m_checkDictionary[CollisionType::Trigger].append(obj);
}

void Model2DCollision::addGetter(GameObject *obj)
{
    m_checkDictionary[CollisionType::Getter].append(obj);
}

void Model2DCollision::removeTrigger(GameObject *obj)
{
    m_checkDictionary[CollisionType::Trigger].removeOne(obj);
}

void Model2DCollision::removeGetter(GameObject *obj)
{
    m_checkDictionary[CollisionType::Getter].removeOne(obj);
}

void Model2DCollision::setTriggerFunction(CollisionFunction func)
{
    m_collisionFunctionDictionary[CollisionType::Trigger]=func;
}

void Model2DCollision::setGetterFunction(CollisionFunction func)
{
    m_collisionFunctionDictionary[CollisionType::Getter]=func;
}

void Model2DCollision::doTriggerFunction(GameObject *trigger, GameObject *getter, Model2DMove::Direction direction)
{
    if(!m_collisionFunctionDictionary[CollisionType::Trigger]) return;
    m_collisionFunctionDictionary[CollisionType::Trigger](trigger,getter,direction);
}

void Model2DCollision::doGetterFunction(GameObject *trigger, GameObject *getter, Model2DMove::Direction direction)
{
    if(!m_collisionFunctionDictionary[CollisionType::Getter]) return;
    m_collisionFunctionDictionary[CollisionType::Getter](trigger,getter,direction);
}

Model2DCollision::CollisionType Model2DCollision::collisionType() const
{
    return m_collisionType;
}

void Model2DCollision::setCollisionType(Model2DCollision::CollisionType newCollisionType)
{
    if (m_collisionType == newCollisionType)
        return;
    m_collisionType = newCollisionType;
    emit collisionTypeChanged();
}

Model2DCollision::CollisionState Model2DCollision::collisionState() const
{
    return m_collisionState;
}

void Model2DCollision::setCollisionState(Model2DCollision::CollisionState newCollisionState)
{
    if (m_collisionState == newCollisionState)
        return;
    m_collisionState = newCollisionState;
    emit collisionStateChanged();
}

QVector<QPair<GameObject *, Model2DMove::Direction> > Model2DCollision::collidingObjectList() const
{
    return m_collidingObjectList;
}

void Model2DCollision::resetCollidingList()
{
    m_collidingObjectList.clear();
}

void Model2DCollision::addCollidingObject(GameObject *obj, Model2DMove::Direction direction)
{
    m_collidingObjectList.append(QPair<GameObject*,Model2DMove::Direction>{obj,direction});
}

Model2DCollision::CollisionStratagy Model2DCollision::collisionStratagy() const
{
    return m_collisionStratagy;
}

void Model2DCollision::setCollisionStratagy(Model2DCollision::CollisionStratagy newCollisionStratagy)
{
    m_collisionStratagy = newCollisionStratagy;
}
