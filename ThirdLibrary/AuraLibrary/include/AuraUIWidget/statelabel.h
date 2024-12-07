#pragma once

#include <QWidget>
#include "UIHeader.h"
#include "uiwidget.h"
#include "clicklabel.h"

namespace AuraUI {

class StateLabel : public ClickLabel
{
    Q_OBJECT
public:
    explicit StateLabel(QWidget *parent = nullptr);

signals:

};

} // namespace AuraUI

