#pragma once

#include <QWidget>

#include <QColor>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsDropShadowEffect>
#include "../UIHeader.h"
#include "../uiwidget.h"

namespace AuraUI {
/*
 * 暂时废弃该基类 仅通过CardWidget 使用
    Base
    卡片样式的Widget的基类 有圆角、阴影、默认为纯白色背景
    有是否浮动、嵌入时是否可拖拽
*/
class AURAUI_LIB_DECL AuraCardBaseWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit AuraCardBaseWidget(QWidget *parent = nullptr);
    ~AuraCardBaseWidget();
    void initWidget()override;
    void initWidgetStyle()override;
    void applyWidgetStyle()override;

    int shadowSize()const;
    void setShadowSize(int value);

    int shadowOffsetX()const;
    int shadowOffsetY()const;
    void setShadowOffsetX(int value);
    void setShadowOffsetY(int value);

    unsigned int radius() const;
    void setRadius(unsigned int newRadius);

    QColor backgroundColor()const;
    void setBackgroundColor(const QColor & color);

    QColor shadowColor() const ;
    void setShadowColor (const QColor & color );

    void updateShadow();
protected:
    void paintEvent(QPaintEvent *e)override;
private:
    class AuraCardBaseWidgetPrivate;
    friend class AuraCardBaseWidgetPrivate;
    QScopedPointer<AuraCardBaseWidgetPrivate> m_d;

signals:
    void mouseHoveredSig();
    void mouseEnteredSig();
    void mousePressedSig();
    void mouseDoublePressedSig();

};

} // namespace AuraUI

