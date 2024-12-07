#pragma once

#include <QWidget>
#include <QMetaProperty>

#include "../UIHeader.h"
#include "../uiwidget.h"

namespace AuraUI {


enum class PropertyBoxStyle:int{
    EditBox,
    SelectBox,

};


class AuraLibrary_DECL AuraPropertyBox : public UIWidget
{
    Q_OBJECT
public:
    explicit AuraPropertyBox(QWidget *parent = nullptr);
    ~AuraPropertyBox();

    void initWidget()override;
    void initWidgetStyle()override;
    void applyWidgetStyle()override;

    void initWidget(PropertyBoxStyle boxStyle,const QVariant& initValue =QVariant());

    void setLinkObj(QObject* obj , const QMetaProperty& property);

    void initValueBox(PropertyBoxStyle boxStyle,const QVariant& initValue =QVariant());
public:
    void submitValue();
    void updateValue();

protected:
    void resizeEvent(QResizeEvent*e)override;
private:
    class AuraPropertyBoxPrivate;
    friend class AuraPropertyBoxPrivate;
    QScopedPointer<AuraPropertyBoxPrivate>m_d;
signals:

    void updateValueSig();//const QVariant & value
    void submitValueSig();
};

} // namespace AuraUI
