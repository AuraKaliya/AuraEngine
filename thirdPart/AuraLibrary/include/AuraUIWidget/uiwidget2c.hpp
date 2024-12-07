
#pragma once
/*
    作为组合widget中2个组件组合的基类
    作为一个容器来管理两个widget
*/

#include <QWidget>
#include <QScopedPointer>
#include "UIWidget2CImpl.hpp"
#include <AuraGlobal.h>

namespace AuraUI {

template<typename T1, typename T2,
         typename = std::enable_if_t<std::is_base_of<QWidget, T1>::value
                                     && std::is_base_of<QWidget, T2>::value>>
class AuraLibrary_DECL UIWidget2C : public UIWidget
{
public:
    explicit UIWidget2C(T1* firstWidget, T2* secondWidget, QWidget *parent = nullptr)
        : UIWidget{parent}
        , m_impl(new UIWidget2CImpl<T1,T2>(firstWidget,secondWidget))
    {
        setObjectName("UIWidget2C");
        if(firstWidget)
        {
            firstWidget->setParent(this);
            firstWidget->setVisible(true);
        }

        if(secondWidget)
        {
            secondWidget->setParent(this);
            secondWidget->setVisible(true);
        }
    }

    void initWidget() override
    {
        m_impl->initWidget();
    }

    void setDirection(AuraUI::UIDirection direction)
    {
        setUiDirectionFlag(direction);
    }

    void setRatio(unsigned int first, unsigned int second)
    {
        m_impl->setRatio(first,second);
    }

    T1*firstWidget()
    {
        return m_impl->firstWidget();
    }

    T2* secondWidget()
    {
        return m_impl->secondWidget();
    }

    template<typename T,typename = std::enable_if_t<std::is_base_of<QWidget, T>::value>>
    T* firstWidget()
    {
        return reinterpret_cast<T*>(m_impl->firstWidget());
    }

    template<typename T,typename = std::enable_if_t<std::is_base_of<QWidget, T>::value>>
    T* secondWidget()
    {
        return reinterpret_cast<T*>(m_impl->secondWidget());
    };

protected:
    void resizeEvent(QResizeEvent* e) override
    {
        UIWidget::resizeEvent(e);

        T1 * firstWidget  =m_impl->firstWidget();
        T2 * secondWidget = m_impl->secondWidget();

        if(!firstWidget || !secondWidget )
        {
            qDebug()<<"UIWidget2C | error: no have complete widget.";
            return;
        }

        auto mainW=width();
        auto mainH=height();
        auto firstRatio =m_impl->firstRatio();
        auto secondRatio =m_impl->secondRatio();

        if(!firstRatio) firstRatio=1;
        if(!secondRatio) secondRatio=1;

        auto sumRatio =firstRatio+secondRatio;

        switch (uiDirectionFlag())
        {
        case UIDirection::Vertical:
        {
            int firtstWidgetHeight=mainH*firstRatio/sumRatio;
            int secondWidgetHeight=mainH*secondRatio/sumRatio;

            firstWidget->resize(mainW,firtstWidgetHeight);
            secondWidget->resize(mainW,secondWidgetHeight);
            firstWidget->move(0,0);
            secondWidget->move(0,firtstWidgetHeight);
        }
        break;
        case UIDirection::Horizon:
        {
            int firtstWidgetWidth=mainW*firstRatio/sumRatio;
            int secondWidgetWidth=mainW*secondRatio/sumRatio;

            firstWidget->resize(firtstWidgetWidth,mainH);
            secondWidget->resize(secondWidgetWidth,mainH);
            firstWidget->move(0,0);
            secondWidget->move(firtstWidgetWidth,0);
        }
        break;
        default:
            break;
        }
    }
    QScopedPointer<UIWidget2CImpl<T1,T2> > m_impl;
};
} // namespace AuraUI
