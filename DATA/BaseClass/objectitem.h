#ifndef OBJECTITEM_H
#define OBJECTITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "../constvalue.h"

//=========================加入反射
#include "../../TOOL/Template/Registor.hpp"
//===============================

class GameObject;

class ObjectItem : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit ObjectItem(const QPixmap& pix, QObject *parent = nullptr,QGraphicsItem* itemParent=nullptr);
    QRectF  boundingRect() const override;    //QRect绘制时除了topleft 都会往内部偏移1像素点，而QRectF是用浮点数表示区域，不会出现这个问题
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget ) override;

    QPixmap pix() const;
    void setPix(const QPixmap &newPix);

    QRectF itemRect() const;

    void setItemRect(const QRectF &newItemRect);

    int sceneIdx() const;
    void setSceneIdx(int newSceneIdx);

    bool drawState() const;

    void setLinkObj(GameObject* obj);
    GameObject *linkObj() const;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e)override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e)override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e)override;
private:
    void updatePos();
protected:
    QRectF m_itemRect;
    QPixmap m_pix;

    //默认的关卡Id为0，需要在初始化时设置
    int m_sceneIdx;
    //绘制状态 可以用enum来统筹，是paint绘制策略的指导  这里仅使用bool 来描述是否对其进行绘制。
    bool m_drawState;

    GameObject* m_linkObj=nullptr;

private:
    float m_nowX;
    float m_nowY;
signals:
    void nowXChanged(qreal);
    void nowYChanged(qreal);
};

#endif // OBJECTITEM_H
