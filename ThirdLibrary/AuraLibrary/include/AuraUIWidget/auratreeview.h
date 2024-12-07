#pragma once

#include <QWidget>
#include <QTreeView>

#include "UIHeader.h"

#include "aurawidgetdelegate.h"

namespace AuraUI {
class AuraLibrary_DECL AuraTreeView : public QTreeView
{
    Q_OBJECT
public:
    explicit AuraTreeView(QWidget *parent = nullptr);

signals:

};

}// namespace AuraUI
