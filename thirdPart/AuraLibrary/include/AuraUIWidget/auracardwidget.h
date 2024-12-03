#pragma once

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsDropShadowEffect>


#include "UIHeader.h"
#include "uiwidget.h"

namespace AuraUI {
/*
    卡片样式的Widget 有圆角、阴影、默认为纯白色背景
    有是否浮动、嵌入时是否可拖拽
*/
class AURAUI_LIB_DECL AuraCardWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit AuraCardWidget(QWidget *parent = nullptr);
    void initWidget()override;

    unsigned int shadowSize() const;
    void setShadowSize(unsigned int newShadowSize);

    unsigned int radius() const;
    void setRadius(unsigned int newRadius);

    void paintEvent(QPaintEvent *e)override;

private:

    WidgetDragStratagy m_dragStratagy;
    QColor m_backgroundColor;
    unsigned int  m_shadowSize;
    unsigned int m_radius;

signals:

};

}//AuraUI
