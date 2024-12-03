#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMetaProperty>
#include <QHBoxLayout>

#include "UIHeader.h"
#include "uiwidget.h"
namespace AuraUI {

class AURAUI_LIB_DECL AuraMultiPropertyEditBox : public UIWidget
{
    Q_OBJECT
public:
    explicit AuraMultiPropertyEditBox(QWidget *parent = nullptr);
    void initWidget()override;

    void submitValue();
    void updateValue();

    void setLinkObj(QObject* obj,QMetaProperty property);
    QLineEdit *valueBox() const;
protected:
    void resizeEvent(QResizeEvent *e)override;
private:
    QLineEdit* m_valueBox;
    QPushButton* m_argsBtn;
    QHBoxLayout* m_mainLayout;

    QMetaProperty m_linkProperty;
    QObject* m_linkObj = nullptr;
signals:
    void valueChangedSig();
    void btnPressedSig();
};

}// namespace AuraUI
