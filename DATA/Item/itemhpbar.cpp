#include "itemhpbar.h"

ItemHPBar::ItemHPBar(int nowHP, int maxHP, const QPixmap &pix, QObject *parent, QGraphicsItem *itemParent)
    : ObjectItem{pix,parent,itemParent},m_maxHP(maxHP),m_nowHP(nowHP),m_hpColor(Qt::red)
{
    if(m_nowHP>=0 && m_maxHP>=0 && m_nowHP<=m_maxHP)
    {

    }
    else
    {
        m_maxHP = 100;
        m_nowHP = 100;
    }

    //需要实时刷新 所以不做缓存
    setCacheMode(NoCache);
}

int ItemHPBar::nowHP() const
{
    return m_nowHP;
}

void ItemHPBar::setNowHP(int newNowHP)
{
    if(newNowHP<0) newNowHP=0;
    if(newNowHP>=m_maxHP) newNowHP=m_maxHP;
    m_nowHP = newNowHP;
}

int ItemHPBar::maxHP() const
{
    return m_maxHP;
}

void ItemHPBar::setMaxHP(int newMaxHP)
{
    if(newMaxHP<=0) newMaxHP=1;
    m_maxHP = newMaxHP;
}

void ItemHPBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(m_drawState)
    {
        double ratio=(m_nowHP*1.0)/m_maxHP;
#ifdef QDEBUGCHECK
        //qDebug()<<"ItemHPBar::paint | ratio:"<<ratio << "m_nowHP : "<<m_nowHP <<"m_maxHP :"<< m_maxHP;
#endif
        QRectF maxHPBorderRect=QRectF(1,1,qMax(0.0,m_itemRect.width()-2),qMax(0.0,m_itemRect.height()-2));
        QRectF nowHPBorderRect=QRectF(1,1,qMax(0.0,ratio*m_itemRect.width()-2),qMax(0.0,m_itemRect.height()-2));
        painter->setPen(QPen(Qt::black));
        painter->drawRect(maxHPBorderRect);
        painter->setBrush(QBrush(m_hpColor));
        painter->drawRect(nowHPBorderRect);
        QGraphicsItem::updateMicroFocus();
    }
}

QColor ItemHPBar::hpColor() const
{
    return m_hpColor;
}

void ItemHPBar::setHpColor(const QColor &newHpColor)
{
    m_hpColor = newHpColor;
}

