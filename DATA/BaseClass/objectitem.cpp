#include "objectitem.h"
#include "gameobject.h"

ObjectItem::ObjectItem(const QPixmap &pix, QObject *parent, QGraphicsItem *itemParent)
    : QObject{parent},QGraphicsItem{itemParent},m_itemRect(QRectF(0,0,0,0)),m_pix(pix),m_sceneIdx(0),m_drawState(true)
{
    setFlags(ItemIsMovable | ItemClipsToShape | ItemIsSelectable);

    //默认是做设备缓存  实时刷新需要设置为NoCache
    setCacheMode(DeviceCoordinateCache);
}

QRectF ObjectItem::boundingRect() const
{
    return QRectF(0,0,m_itemRect.width(),m_itemRect.height());
}

void ObjectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(m_drawState)
    {
        painter->drawPixmap(0,0,m_pix.scaled(m_itemRect.width(),m_itemRect.height(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
    }
}

QPixmap ObjectItem::pix() const
{
    return m_pix;
}

void ObjectItem::setPix(const QPixmap &newPix)
{
    m_pix = newPix;
}

QRectF ObjectItem::itemRect() const
{
    return m_itemRect;
}

void ObjectItem::setItemRect(const QRectF &newItemRect)
{
    m_itemRect = newItemRect;
}

int ObjectItem::sceneIdx() const
{
    return m_sceneIdx;
}

void ObjectItem::setSceneIdx(int newSceneIdx)
{
    m_sceneIdx = newSceneIdx;
}

bool ObjectItem::drawState() const
{
    return m_drawState;
}

void ObjectItem::setLinkObj(GameObject *obj)
{
    m_linkObj=obj;
}

GameObject *ObjectItem::linkObj() const
{
    return m_linkObj;
}

void ObjectItem::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsItem::mousePressEvent(e);

    updatePos();
}

void ObjectItem::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsItem::mouseMoveEvent(e);
    updatePos();
}

void ObjectItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsItem::mouseReleaseEvent(e);
    updatePos();
    if(isSelected())
    {
        emit nowXChanged(m_nowX);
        emit nowYChanged(m_nowY);
    }

}

void ObjectItem::updatePos()
{
    m_nowX=x();
    m_nowY=y();
    QGraphicsItem::update () ;
}
