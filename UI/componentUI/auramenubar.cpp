#include "auramenubar.h"

AuraMenuBar::AuraMenuBar(QWidget *parent)
    : UIWidget{parent}
{
    m_bar =new QMenuBar();
}

void AuraMenuBar::initWidget()
{
    //检查数据完整
    if(!m_bar)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"AuraMenuBar::initWidget | no have bar.";
#endif

    }
}

QMenuBar *AuraMenuBar::bar() const
{
    return m_bar;
}
