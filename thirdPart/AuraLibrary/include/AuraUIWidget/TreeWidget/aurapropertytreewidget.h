#pragma once

#include <QWidget>
#include <QTreeWidget>
#include <QMap>
#include <QString>
#include "../UIHeader.h"

namespace AuraUI {

/*
    特化的TreeWidget
    仅两列， 第一列为参数树，第二列为【属性设置Box】（PropertyBox）
    提供添加Root Branch和PropertyBox的接口。
    在添加PropertyBox时，propertyValueBox添加到第二列中。
*/
class AuraLibrary_DECL AuraPropertyTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit AuraPropertyTreeWidget(QWidget *parent = nullptr);
    void addRoot(const QString & rootName); // 添加根节点
    void addBranch(const QString & parentNodeName,const QString & branchName); // 添加子节点
    void addPropertyBox(const QString & parentNodeName,const QString & propertyName,QWidget* propertyValueBox); // 添加属性设置框

private:
    void addItemToTree(const QString& prefex,const QString itemName,QTreeWidgetItem* item); // 向树中添加项

    QMap<QString,QTreeWidgetItem*> m_modelTree; // 存储节点映射

signals:
};

} // namespace AuraUI
