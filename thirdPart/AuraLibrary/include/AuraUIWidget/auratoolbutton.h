#pragma once

#include <QWidget>
#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QIcon>

#include "UIHeader.h"
#include "uiwidget.h"

namespace AuraUI {

enum class AuraToolButtonType:int{
    Close,
    Minium,
    Custom
};

enum class AuraToolButtonState:int{
    Normal,
    Hover
};

class AuraLibrary_DECL AuraToolButton : public UIWidget
{
    Q_OBJECT
public:
    explicit AuraToolButton(QWidget *parent = nullptr);
    void initWidget()override;
    void initWidget(AuraToolButtonType btnType);

    void setBtnType(AuraToolButtonType btnType);
    void setNormalIcon(const QIcon& icon);
    void setHoverIcon(const QIcon& icon);

protected:
    void paintEvent(QPaintEvent*e)override;
    void mousePressEvent(QMouseEvent* e)override;
#ifndef USE_QT6
    void enterEvent(QEvent*e)override;
#else
    void enterEvent(QEnterEvent*e)override;
#endif

    void leaveEvent(QEvent*e)override;

private:
    QColor m_backgroundColor;
    AuraToolButtonType m_buttonType;
    AuraToolButtonState m_buttonState;


    QIcon m_normalIcon;
    QIcon m_hoverIcon;
signals:
    void clicked();
};

} // namespace AuraUI
