#pragma once

#include <QWidget>

#include "UIHeader.h"
#include "uiwidget.h"

#include "clicklabel.h"


namespace AuraUI {

class AURAUI_LIB_DECL AuraHeadBarNormal : public UIWidget
{
    Q_OBJECT
public:
    explicit AuraHeadBarNormal(QWidget *parent = nullptr);
    void initWidget()override;
    void initWidgetStyle()override;
    void applyWidgetStyle()override;

protected:
    void mouseReleaseEvent(QMouseEvent* e)override;
    void mousePressEvent(QMouseEvent* e)override;
    void mouseMoveEvent(QMouseEvent* e)override;
    void paintEvent(QPaintEvent*e)override;
    void resizeEvent(QResizeEvent* e)override;

    void paintCloseBtn(QPainter*p,ClickLabel*w);
private:

    ClickLabel *m_closeLabel =nullptr;

    bool m_isPressed;
    bool m_testFlag;

    QPointF m_starPoint;
    QPointF m_distancePoint;

    QColor m_backgroundColor;
    unsigned int m_radius;

    unsigned int m_maxHight;
    unsigned int m_minHight;
    unsigned int m_minWidth;

    unsigned int m_btnSize;

signals:

};

} // namespace AuraUI
