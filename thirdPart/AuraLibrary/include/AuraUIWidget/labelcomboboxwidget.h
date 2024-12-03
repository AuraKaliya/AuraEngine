#pragma once
#include <QLabel>
#include <QComboBox>

#include "UIHeader.h"
#include "uiwidget2c.hpp"

namespace AuraUI {

class AURAUI_LIB_DECL LabelComboBoxWidget : public /*UIWidget2C*/ UIWidget2C<QLabel,QComboBox>
{
    Q_OBJECT
    Q_PROPERTY(bool buildCountFlag READ buildCountFlag WRITE setBuildCountFlag NOTIFY buildCountFlagChanged FINAL)
public:
    explicit LabelComboBoxWidget(QString str,QWidget *parent = nullptr);
    explicit LabelComboBoxWidget(QString str,bool linkedBuildFlag, QWidget *parent = nullptr);

    void initWidget()override;
    void addValue(const QString & value);

    QComboBox *box() const;
    QLabel* label()const;
    bool buildCountFlag() const;
    void setBuildCountFlag(bool newBuildCountFlag);

    static bool staticBuildCountFlag();
    static void setStaticBuildCountFlag(bool newStaticBuildCountFlag);

private:

    QLabel* m_label;
    QComboBox* m_box;

    bool m_buildCountFlag;
    static bool m_staticBuildCountFlag;

signals:
    void valueChangedSig();
    void buildCountFlagChanged();
};
}// namespace AuraUI

