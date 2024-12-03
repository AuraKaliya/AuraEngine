#pragma once
#include<QGraphicsItem>
#include<QGraphicsObject>
#include <QPainter>
#include "../AuraGlobal.h"

namespace AuraUI {
class AURAUI_LIB_DECL AuraOpenGLGraphicsItem: public QGraphicsObject
{
public:
    AuraOpenGLGraphicsItem();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr)override;
};

}//AuraUI
