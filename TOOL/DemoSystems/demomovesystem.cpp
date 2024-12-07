#include "demomovesystem.h"


DemoMoveSystem::DemoMoveSystem(QObject *parent)
    : DemoSystemObject{parent}
{

}

void DemoMoveSystem::update(GameObject &obj)
{
    Model2DMove * moveModel=obj.getComponent<Model2DMove>();
    if(!moveModel)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"DemoMoveSystem::update | "<<obj.objClass()<<" no have component Model2DMove.";
#endif
        return;
    }

    GlobalKeyValue keyValue;
    if(keyValue.getKeyPressedState("s"))
    {
        moveModel->setYSpeed(10);
    }

    if(keyValue.getKeyPressedState("a"))
    {
        moveModel->setXSpeed(-10);
    }
    if(keyValue.getKeyPressedState("w"))
    {
        moveModel->setYSpeed(-10);
    }
    if(keyValue.getKeyPressedState("d"))
    {
        moveModel->setXSpeed(10);
    }
}
