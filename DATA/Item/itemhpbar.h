#ifndef ITEMHPBAR_H
#define ITEMHPBAR_H

#include <QObject>
#include "../BaseClass/objectitem.h"


class ItemHPBar : public ObjectItem
{
    Q_OBJECT
public:
    explicit ItemHPBar(int nowHP=100,int maxHP=100,const QPixmap& pix=QPixmap(),QObject *parent = nullptr,QGraphicsItem* itemParent=nullptr);

    int nowHP() const;
    void setNowHP(int newNowHP);

    int maxHP() const;
    void setMaxHP(int newMaxHP);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget ) override;

    QColor hpColor() const;
    void setHpColor(const QColor &newHpColor);

protected:
    int m_maxHP;
    int m_nowHP;

    QColor m_hpColor;

signals:

};

#endif // ITEMHPBAR_H
