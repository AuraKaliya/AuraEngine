#pragma once

#include <QWidget>

#include "UIHeader.h"

#include <AuraTemplate/Entity.hpp>

#include "clicklabel.h"

namespace AuraUI {

class AURAUI_LIB_DECL ComponentClickLabel : public ClickLabel ,public Entity
{
    Q_OBJECT
public:
    explicit ComponentClickLabel(QWidget *parent = nullptr);
    explicit ComponentClickLabel(const QString &text, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
signals:

};
}// namespace AuraUI

