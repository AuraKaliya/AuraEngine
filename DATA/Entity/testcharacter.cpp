#include "testcharacter.h"


TestCharacter::TestCharacter(/*bool initByJsonFlag,*/ QObject *parent)
    : GameObject{/*initByJsonFlag,*/parent}
{
    /*可优化*/
    //对类的处理可放在静态处理中，进行一次性的处理
    //设置有item
    m_itemFlag=true;
    /*可优化*/

    setObjClass("TestCharacter");


}

void TestCharacter::initObject(const QJsonObject &objData)
{
    GameObject::initObject(objData);
}

void TestCharacter::initObject()
{
#ifdef QDEBUGCHECK
    qDebug()<<"TestCharacter::initObject( )| obj:"<<this;
#endif

    addComponent(new Model2DItem("",this));

    addComponent(new ModelBattleBase(this));
    addComponent(new Model2DHPBar(100,100,this));

    addComponent(new ModelScript("",this,this));

    addComponent(new Model2DMove(this));
    addComponent(new Model2DCollision(Model2DCollision::TriggerGetter, this));
}

QJsonObject TestCharacter::getMetaData() const
{
    return GameObject::getMetaData();
}

QVector<ObjectItem *> TestCharacter::items()
{
    return QVector<ObjectItem *>{
        getComponent<Model2DItem>()->item(),
        getComponent<Model2DHPBar>()->item()
    };
}

void TestCharacter::initModel2DItem(const QJsonObject &objData)
{

}
