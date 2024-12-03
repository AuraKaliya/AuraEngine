#pragma once

#include <QWidget>
#include<QMetaProperty>
#include <QLineEdit>
#include <QHBoxLayout>

#include "UIHeader.h"
#include "uiwidget.h"
namespace AuraUI {

class AURAUI_LIB_DECL AuraPropertyEditBox : public UIWidget
{
    Q_OBJECT
public:
    explicit AuraPropertyEditBox(QWidget *parent = nullptr);
    void initWidget()override;

    void submitValue();
    void updateValue();

    void setLinkObj(QObject* obj,QMetaProperty property);
    QLineEdit *valueBox() const;


protected:
    void resizeEvent(QResizeEvent *e)override;
private:
    QLineEdit* m_valueBox;
    QHBoxLayout* m_mainLayout;
    QMetaProperty m_linkProperty;
    QObject* m_linkObj = nullptr;
signals:
    void valueSubmitSig();
};
}// namespace AuraUI
