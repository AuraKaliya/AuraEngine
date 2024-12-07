#pragma once
#include <QWidget>

#include "UIHeader.h"

#include "baseswitchwidget.h"

namespace AuraUI {
class ClickLabel ;
class ComponentClickLabel;
class AuraLibrary_DECL SwitchWidget : public BaseSwitchWidget
{
    Q_OBJECT
public:
    explicit SwitchWidget(QWidget *parent = nullptr);
    void addLabel(ComponentClickLabel* label)override;
    void updateLabelState()override;

protected:
    static void labelPaint(QPainter* p,ClickLabel *w);

signals:
};

}// namespace AuraUI

