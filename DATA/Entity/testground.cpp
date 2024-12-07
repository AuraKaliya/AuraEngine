#include "testground.h"

TestGround::TestGround(QObject *parent)
    : GameObject{parent}
{
    //设置有item
    m_itemFlag=true;
    setObjClass("TestGround");
}

void TestGround::initObject(const QJsonObject &objData)
{
    GameObject::initObject(objData);

}

void TestGround::initObject()
{
#ifdef QDEBUGCHECK
    qDebug()<<"TestGround::initObject( )| obj:"<<this;
#endif

    addComponent(new Model2DItem("",this));
    addComponent(new Model2DCollision(Model2DCollision::Getter, this));
}

QJsonObject TestGround::getMetaData() const
{
    return GameObject::getMetaData();
}

QVector<ObjectItem *> TestGround::items()
{
    return QVector<ObjectItem *>{
        getComponent<Model2DItem>()->item()
    };
}
