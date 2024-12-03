#pragma once

//#include <QComboBox>
//#include <QWidget>
#include "uiwidget.h"
//#include <QScopedPointer>
#include <AuraGlobal.h>

namespace AuraUI {
template<typename T1, typename T2,
         typename = std::enable_if_t<std::is_base_of<QWidget, T1>::value
                                     && std::is_base_of<QWidget, T2>::value>>
class AURAUI_LIB_DECL UIWidget2CImpl
{
public:
    explicit UIWidget2CImpl(T1 *firstWidget, T2 *secondWidget)
        : m_firstWidget(firstWidget), m_secondWidget(secondWidget), m_firstRatio(1), m_secondRatio(1)
    {

    }
    //C17之前
    void initWidget()
    {
        initWidget(m_firstWidget);
        initWidget(m_secondWidget);
    }

    template<typename T>
    void initWidget(T* widget, std::enable_if_t<std::is_base_of<UIWidget, T>::value>* = nullptr)
    {
        widget->initWidget();
        qDebug()<<"init by uiwidget";
    }

    //该方法不可行
    template<typename T>
    void initWidget(T* w, std::enable_if_t<!std::is_base_of<UIWidget, T>::value>* = nullptr)
    {
        qDebug()<<"init by normal";

        // if(std::is_base_of<QComboBox, T>::value)
        // {
        //     qDebug()<<"init by QComboBox";
        //     // connect(w,&QComboBox::currentTextChanged,this,[this](){
        //     //     //emit valueChangedSig();
        //     // });
        // }

        return;
    }
    //C17之前

    void setRatio(unsigned int first, unsigned int second)
    {
        m_firstRatio=first;
        m_secondRatio=second;
    }

    T1* firstWidget()
    {
        return m_firstWidget;
    }

    T2* secondWidget()
    {
        return m_secondWidget;
    }

    unsigned int firstRatio()
    {
        return m_firstRatio;
    }

    unsigned int secondRatio()
    {
        return m_secondRatio;
    }

public: /*property*/
    T1* m_firstWidget;
    T2* m_secondWidget;
    unsigned int m_firstRatio;
    unsigned int m_secondRatio;
};
} // namespace AuraUI
