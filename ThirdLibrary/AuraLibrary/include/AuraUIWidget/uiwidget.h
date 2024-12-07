#pragma once

#include <QWidget>
#include <QVector>
#include <QString>
#include <QPainter>
#include <QStyleOption>
#include <QJsonObject>

#include "UIHeader.h"

namespace AuraUI {
/*
            Style设置约定
    1. 约定 每层Widget只通过Manager设置自己所管理的下一层Widget。
    2. 最外层（Root Widget） 由外部控制。
    3. 通常是在initWidget中 通过Manager设置，然后再在initWidgetStyle中应用。
    4. initWidgetStyle 只设置自己的和非UIWidget部分。
*/



class AuraLibrary_DECL UIWidget : public QWidget
{
    Q_OBJECT
public:

public:

public:
    explicit UIWidget(QWidget *parent = nullptr);
    virtual void initWidget();
    virtual void initWidget(const QJsonObject& obj);
    virtual void initWidgetStyle();
    virtual void applyWidgetStyle();

    void setUIStyle(const UIStyle & style);

    //==================控制位======================
    bool autoInitUIStyleFlag() const;
    UIDirection uiDirectionFlag() const;

    bool autoAdjustUIFlag() const;
    void setAutoAdjustUIFlag(bool newAutoAdjustUIFlag);

    UIStyle uiStyle() const;

    bool uiStyleReadyFlag() const;

    StyleStratagy uiStyleStratagy() const;
    void setUiStyleStratagy(StyleStratagy newUiStyleStratagy);

    void addChirldWidget(UIWidget* w);

protected:
    void setAutoInitUIStyleFlag(bool newAutoInitUIStyleFlag);
    void setUiDirectionFlag(UIDirection newUiDirectionFlag);
    void paintEvent(QPaintEvent*e)override;

protected:
    // style-property
    UIStyle m_uiStyle;


private:
    //之后会将其整合至impl中

    //专门用于管理子部件的容器
    QVector<UIWidget*> m_widgetList;
    //自动设置UIStyle的控制位
    bool m_autoInitUIStyleFlag;
    //自动调整ui的控制位
    bool m_autoAdjustUIFlag;
    //  横向UI/纵向UI；
    UIDirection m_uiDirectionFlag;

    //用于标识Style的设置策略
    StyleStratagy m_uiStyleStratagy;

    // 用于管理style-Property初始化的控制位
    bool m_uiStyleReadyFlag;

    // 用于标识对象初始化进程
    bool m_initFlag;

signals:
    void setUIStyleFinished();
    void adjustUISig();

    void actionSignal(const QString&);
    void errorSignal(const QString&);
    void logSignal(const QString& ,AuraUI::LogType);
};

#if defined(AuraComponentUI_USE_REFLEX)
REGISTER_CLASS(UIWidget,UIWidget,QWidget*);
#endif



}// namespace AuraUI



