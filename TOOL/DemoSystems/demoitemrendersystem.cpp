#include "demoitemrendersystem.h"

DemoItemRenderSystem::DemoItemRenderSystem(QObject *parent)
    : DemoSystemObject{parent}
{

}

void DemoItemRenderSystem::update(GameObject &obj)
{
    Model2DItem * characterItem=obj.getComponent<Model2DItem>();
    if(characterItem->item()->drawState())
    {
#ifdef QDEBUGCHECK
        //qDebug()<<"DemoItemRenderSystem::update | "<<obj.name()<<" 需要蓝光~";
#endif
    }

}
