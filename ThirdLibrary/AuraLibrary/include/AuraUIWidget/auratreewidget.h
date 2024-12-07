#pragma once

#include <QWidget>
#include <QTreeWidget>

#include "UIHeader.h"

namespace AuraUI {
class LabelBoxWidget;

class AuraLibrary_DECL AuraTreeWidget : public QTreeWidget
{
    /*考虑是否可以用模板来写一个自定义列数并提供自适应函数的类*/
    Q_OBJECT
public:
    explicit AuraTreeWidget(QWidget *parent = nullptr);
    //void setFirstHeaderItem(QTreeWidgetItem* item,const QString& headerTitle);
    void addWidgetItem(QTreeWidgetItem* parent , const QString& PropertyTex,QWidget* widget);
    //void addLabelBoxWidgetItem(QTreeWidgetItem* parent,LabelBoxWidget* widget);
signals:

};


}// namespace AuraUI
