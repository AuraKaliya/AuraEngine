#pragma once
#include <QLabel>
#include <QLineEdit>
#include "UIHeader.h"

#include "uiwidget2c.hpp"

namespace AuraUI {

class AuraLibrary_DECL LabelBoxWidget : public UIWidget2C<QLabel,QLineEdit>
{
    Q_OBJECT
    Q_PROPERTY(bool buildCountFlag READ buildCountFlag WRITE setBuildCountFlag NOTIFY buildCountFlagChanged FINAL)
public:
    explicit LabelBoxWidget(QString str,QWidget *parent = nullptr);
    explicit LabelBoxWidget(QString str,bool linkedBuildFlag, QWidget *parent = nullptr);
    void initWidget()override;

    QLineEdit *box();
    QLabel* label();

    bool editableFlag() const;
    void setEditableFlag(bool newEditableFlag);

    QString nowValue() const;
    void setNowValue(const QString &newNowValue);

    void setAllowedValue(AllowedValueType valueType,double minValue = -1.78e308,double maxValue = 1.78e30);
    AllowedValueType allowedValueType();
    bool isLimited();
    double minValue() const;
    double maxValue() const;

    bool buildCountFlag() const;
    void setBuildCountFlag(bool newBuildCountFlag);

    static bool staticBuildCountFlag();
    static void setStaticBuildCountFlag(bool newStaticBuildCountFlag);

protected:
    bool checkValueValid(QString value);

private:
    QLabel* m_label=nullptr;
    QLineEdit* m_box=nullptr;

    bool m_editableFlag;
    bool m_buildCountFlag;

    QString m_nowValue;
    QString m_preValue;

    AllowedValueType m_allowedValueType;
    bool m_valueLimitFlag;
    double m_minValue;
    double m_maxValue;

    static bool m_staticBuildCountFlag;

signals:
    void valueChangedSig();
    void valueRejectedSig();
    void buildCountFlagChanged();
};

}// namespace AuraUI

