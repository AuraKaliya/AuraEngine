#include "rendersystem.h"

RenderSystem* RenderSystem::m_instance=nullptr;
RenderSystem *RenderSystem::getInstance(QObject *parent )
{
    if(m_instance==nullptr)
    {
        m_instance=new RenderSystem(parent);
    }
    return m_instance;
}

RenderSystem::RenderSystem(QObject *parent)
    : SystemObject{parent}
{
    setObjectName("RenderSystem");
}

bool RenderSystem::systemStart()
{
#ifdef QDEBUGCHECK
    qDebug()<<"RenderSystem::systemStart | √ ";
#endif
    return true;
}

bool RenderSystem::systemInit()
{
#ifdef QDEBUGCHECK
    qDebug()<<"RenderSystem::systemInit | √ ";
#endif





    return true;
}

bool RenderSystem::systemClose()
{
#ifdef QDEBUGCHECK
    qDebug()<<"RenderSystem::systemClose | √ ";
#endif
    return true;
}

void RenderSystem::updateRender()
{

}


