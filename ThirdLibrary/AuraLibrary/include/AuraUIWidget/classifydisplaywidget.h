#pragma once
#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>

#include "UIHeader.h"
#include "uiwidget.h"



/*内部组件非UIWidget体系*/
namespace AuraUI {
class BaseSwitchWidget;
class ComponentClickLabel;

class AuraLibrary_DECL ClassifyDisplayWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit ClassifyDisplayWidget(BaseSwitchWidget* switchWidget,QStackedWidget* stackedWidget,QWidget *parent = nullptr);
    int getNowWidgetIndex();
    int getWidgetCount();
    void addWidget(ComponentClickLabel* lb,QWidget* w);
    void initWidget()override;
    //void setUIStyle(const UIStyle & style)override;

    void setRadio(unsigned int headRadio,unsigned int bodyRadio);

private:
    QVBoxLayout* m_mainLayout=nullptr;
    BaseSwitchWidget* m_switchWidget=nullptr;
    QStackedWidget* m_stackedWidget=nullptr;
signals:
    void currentWidgetChanged();
};


}// namespace AuraUI
