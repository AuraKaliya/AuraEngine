#pragma once

#include <QWidget>
#include <QMetaProperty>
#include <QComboBox>
#include <QHBoxLayout>

#include "UIHeader.h"
#include "uiwidget.h"

namespace AuraUI {
class AuraLibrary_DECL AuraPropertySelectBox : public UIWidget
{
    Q_OBJECT
public:
    explicit AuraPropertySelectBox(QWidget *parent = nullptr);
    void initWidget()override;

    void submitValue();
    void updateValue();

    void setLinkObj(QObject* obj,QMetaProperty property);
    QComboBox *valueBox() const;

protected:
    void resizeEvent(QResizeEvent *e)override;
private:
    QComboBox* m_valueBox;
    QHBoxLayout* m_mainLayout;
    QMetaProperty m_linkProperty;
    QObject* m_linkObj = nullptr;
signals:
};

}// namespace AuraUI
