#pragma once

#include <QWidget>
#include "UIHeader.h"
#include "uiwidget.h"
#include "SARibbon/SARibbon.h"

namespace AuraUI {
class AURAUI_LIB_DECL AuraRibbonWidgetSA : public SARibbonMainWindow
{
    Q_OBJECT
public:
    explicit AuraRibbonWidgetSA(QWidget *parent = nullptr);
    void initWidget(){
        //qDebug()<<"AuraRibbonWidgetSA::initWidget | call.";
        m_themeDir =AURAUI_SATHEME_DIR;
    }

private:
    QString m_themeDir;
signals:
};

}//AuraUI
