#pragma once

#include <QCheckBox>
#include <QLineEdit>

#include "UIHeader.h"
#include "uiwidget2c.hpp"

namespace AuraUI {

class AuraLibrary_DECL CheckBoxBoxWidget : public UIWidget2C<QCheckBox,QLineEdit>
{
    Q_OBJECT
public:
    explicit CheckBoxBoxWidget(const QString& str,QWidget *parent = nullptr);
    void initWidget()override;
    void setDirFlag(UIDirection newDirFlag);

    QCheckBox *checkBox() const;
    QLineEdit *editBox() const;

    void setAllowedValue(AllowedValueType valueType,double minValue = -1.78e30,double maxValue = 1.78e30);
    AllowedValueType allowedValueType();
    bool isLimited();

    double minValue() const;

    double maxValue() const;

    QString nowValue() const;
    void setNowValue(const QString &newNowValue);


    bool checkValueValid(QString value);


private:
    QCheckBox* m_checkBox;
    QLineEdit* m_editBox;
    UIDirection m_dirFlag;

    bool m_editableFlag;
    QString m_nowValue;
    QString m_preValue;

    AllowedValueType m_allowedValueType;
    bool m_valueLimitFlag;

    double m_minValue;
    double m_maxValue;

signals:
    void valueChangedSig();
    void valueRejectedSig();
};

}// namespace AuraUI
