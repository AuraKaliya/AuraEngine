#pragma once

#include <QWidget>

#include "../UIHeader.h"
#include "../uiwidget.h"

#include "AuraTemplate/Property.hpp"
namespace AuraUI {


enum class Direction{
    Left,Right
};

enum class HeaderBarStyle:int{
    Default,
    Classify,
    OnlyClose,
    OnlyMinium,
};

class AURAUI_LIB_DECL AuraHeadBar : public UIWidget
{
    Q_OBJECT
    //Q_IMPL_H(AuraHeadBar)
    friend class UIFunction;
public:
    explicit AuraHeadBar(QWidget *parent = nullptr);
    virtual ~AuraHeadBar();
    void initWidget()override;
    void initWidgetStyle()override;
    void applyWidgetStyle()override;

    void initWidget(HeaderBarStyle style);

    QString title()const;
    void setTitle(const QString& text);
    void setIcon(const QPixmap& ico);
    void setTextAlignment(Qt::Alignment alignment);

    void linkToWidget(QWidget * w);
    void addComponentWidget(QWidget* widget);

    //=========================================================
   // void changeLeftDirection(bool flag = false);
protected:

private:
    void mouseReleaseEvent(QMouseEvent* e)override;
    void mousePressEvent(QMouseEvent* e)override;
    void mouseMoveEvent(QMouseEvent* e)override;
    void paintEvent(QPaintEvent*e)override;
    void resizeEvent(QResizeEvent* e)override;
private:
    class AuraHeadBarPrivate;
    friend class AuraHeadBarPrivate;
    QScopedPointer<AuraHeadBarPrivate> m_d;
signals:

};

} // namespace AuraUI

