#ifndef MODEL2DCOLLISION_H
#define MODEL2DCOLLISION_H

#include <QObject>
#include <QMap>
#include "../BaseClass/componentobject.h"

#include "model2dmove.h"


using CollisionFunction=void(*)(GameObject*,GameObject*,Model2DMove::Direction);
class Model2DCollision : public ComponentObject
{
public:
    enum CollisionType{
        NoType=0,Trigger=1,Getter=2,TriggerGetter=3
    };
    enum CollisionState{
        NoCollision=0,Collision=1
    };
    enum CollisionStratagy{
        Rigid , Overlap
    };
private:
    Q_OBJECT

    Q_PROPERTY(CollisionType collisionType READ collisionType WRITE setCollisionType NOTIFY collisionTypeChanged)
    Q_PROPERTY(CollisionState collisionState READ collisionState WRITE setCollisionState NOTIFY collisionStateChanged)

public:
    explicit Model2DCollision(Model2DCollision::CollisionType type = NoType,QObject *parent = nullptr);
    //explicit Model2DCollision(Model2DCollision & other);
    QJsonObject getMetaData()const override;
    void initComponent(const QJsonObject& obj)override;
    QVector<GameObject*> getTriggers();
    QVector<GameObject*> getGetters();
    void addTrigger(GameObject* obj);
    void addGetter(GameObject* obj);

    void initGetter(GameObject*obj,CollisionFunction func);

    void removeTrigger(GameObject* obj);
    void removeGetter(GameObject* obj);

    void setTriggerFunction(CollisionFunction func);
    void setGetterFunction(CollisionFunction func);

    void doTriggerFunction(GameObject* trigger,GameObject* getter,Model2DMove::Direction direction);
    void doGetterFunction(GameObject* trigger,GameObject* getter,Model2DMove::Direction direction);

    Model2DCollision::CollisionType collisionType() const;
    void setCollisionType(Model2DCollision::CollisionType newCollisionType);

    Model2DCollision::CollisionState collisionState() const;
    void setCollisionState(Model2DCollision::CollisionState newCollisionState);


    QVector<QPair<GameObject* ,Model2DMove::Direction> > collidingObjectList() const;
    void resetCollidingList();
    void addCollidingObject(GameObject* obj, Model2DMove::Direction direction);

    Model2DCollision::CollisionStratagy collisionStratagy() const;
    void setCollisionStratagy(Model2DCollision::CollisionStratagy newCollisionStratagy);

private:
    QMap<Model2DCollision::CollisionType,QVector<GameObject*> > m_checkDictionary;
    QMap<Model2DCollision::CollisionType,CollisionFunction >    m_collisionFunctionDictionary;
    QVector<QPair<GameObject* ,Model2DMove::Direction> >        m_collidingObjectList;
    Model2DCollision::CollisionType m_collisionType;

    CollisionState m_collisionState;
    Model2DCollision::CollisionStratagy m_collisionStratagy;


signals:

    void collisionTypeChanged();
    void collisionStateChanged();
};
REGISTER_CLASS( Model2DCollision , ComponentObject )
REGISTER_COPY_CLASS(Model2DCollision , ComponentObject )

#endif // MODEL2DCOLLISION_H
