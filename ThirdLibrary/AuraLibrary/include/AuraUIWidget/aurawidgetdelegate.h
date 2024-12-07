#pragma once

#include <QObject>
#include <QStyledItemDelegate>
#include <QCheckBox>

#include "../AuraGlobal.h"
namespace AuraUI {
class AuraLibrary_DECL AuraWidgetDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit AuraWidgetDelegate(QObject *parent = nullptr);
    // 创建自定义的 QWidget 编辑器
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override ;
    // 设置编辑器中的数据
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    // 将编辑器中的数据保存回模型
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    // 更新编辑器的尺寸
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override ;
    // 重写 paint 方法来完全自定义项的显示
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    // 阻止文本显示，确保只显示自定义的 QWidget
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

private:

    mutable QCheckBox* m_checkBox=nullptr ;

signals:

};


}// namespace AuraUI
