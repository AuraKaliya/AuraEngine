#pragma once
#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QRadialGradient>

#include "UIHeader.h"
#include "uiwidget.h"

namespace AuraUI {
class AuraLibrary_DECL HoverLightBtn : public UIWidget
{
    Q_OBJECT
public:
    explicit HoverLightBtn(QWidget *parent = nullptr);
    explicit HoverLightBtn(const QString &text, QWidget *parent = nullptr);
    void initWidget()override;
    void initColor(QColor lightColor=QColor(Qt::red),QColor outerBackgroundColor=QColor(70,70,70,240),QColor innerbackgroundColor=QColor(70,70,70,250),QColor borderColor=QColor(40,40,40,250),QColor textNormalColor=QColor(Qt::white));
    void paint(QPainter* p,QWidget* w);
    void setText(const QString& text);

protected:
    void paintEvent(QPaintEvent*e)override;
    void resizeEvent(QResizeEvent*e)override;
    void mouseMoveEvent(QMouseEvent*e)override;

#ifndef USE_QT6
    void enterEvent(QEvent*e)override;
#else
    void enterEvent(QEnterEvent*e)override;
#endif

    void leaveEvent(QEvent*e)override;

private:
   // MaskWidget* m_maskWidget;
    QPoint m_mousePos;

    int m_margin;
    int m_border;

    QColor m_lightColor;
    QColor m_outerBackgroundColor;
    QColor m_innerBackgroundColor;
    QColor m_borderColor;
    QColor m_textNormalColor;

    QString m_text;

    bool m_drawPixFlag;
signals:

};

}//AuraUI



