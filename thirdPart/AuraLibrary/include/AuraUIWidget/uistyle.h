#pragma once
#include <QWidget>
#include <QString>
#include <QMap>
#include <QDir>
#include <QApplication>

#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QColor>

#include <functional>
//
#include <QDebug>
//

#include <AuraGlobal.h>

#include "AuraTemplate/Property.hpp"


namespace AuraUI {

class UIStyle;
using UIStyleInitFunction=bool(*)(UIStyle*);
using UIStyleInitByJsonFunction=void(*)(UIStyle*,const QJsonObject&);
using UIStyleStrFunction=std::function<QString()>;


class AURAUI_LIB_DECL Shadow
{
public:
    Shadow(QColor sdColor,int x,int y,int size);
    QColor shadowColor() const;
    void setShadowColor(const QColor &newShadowColor);

    int offsetX() const;
    void setOffsetX(int newOffsetX);

    int offsetY() const;
    void setOffsetY(int newOffsetY);

    int size() const;
    void setSize(int newSize);

private:
    QColor m_shadowColor=QColor("#000000");
    int m_offsetX=0;
    int m_offsetY=0;
    int m_size = 0;
};

class AURAUI_LIB_DECL UIBaseStyle
{
public:
    UIBaseStyle(QColor bk,QColor text,unsigned int radius,Shadow shadow);

    QColor backgroundColor() const;
    void setBackgroundColor(const QColor &newBackgroundColor);

    QColor textColor() const;
    void setTextColor(const QColor &newTextColor);

    unsigned int radius() const;
    void setRadius(unsigned int newRadius);

    Shadow shadow() const;
    void setShadow(const Shadow &newShadow);

private:
    QColor m_backgroundColor;
    QColor m_textColor;
    unsigned int m_radius;
    Shadow m_shadow;
};

struct AURAUI_LIB_DECL UIAnimationStyle
{

};

class AURAUI_LIB_DECL UIStyle
{
public:
    UIStyle(const QString& styleName = "Default");
    ~UIStyle();

    QString styleName() const;
    void setStyleName(const QString &newStyleName);

    bool hoverFlag() const;
    void setHoverFlag(bool newHoverFlag);

    bool pressFlag() const;
    void setPressFlag(bool newPressFlag);

    std::shared_ptr<UIBaseStyle> normalStyle() const;
    void setNormalStyle(const std::shared_ptr<UIBaseStyle> &newNormalStyle);

    std::shared_ptr<UIBaseStyle> hoverStyle() const;
    void setHoverStyle(const std::shared_ptr<UIBaseStyle> &newHoverStyle);

    std::shared_ptr<UIBaseStyle> pressStyle() const;
    void setPressStyle(const std::shared_ptr<UIBaseStyle> &newPressStyle);

private:
    //=============Normal=================
    QString m_styleName;
    std::shared_ptr<UIBaseStyle> m_normalStyle;
    //=============Normal=================

    //=============Hover=================
    bool m_hoverFlag;
    std::shared_ptr<UIBaseStyle> m_hoverStyle;
    std::shared_ptr<UIAnimationStyle> m_hoverAnimationStyle;
    //=============Hover=================

    //==============Press==============
    bool m_pressFlag;
    std::shared_ptr<UIBaseStyle> m_pressStyle;
    std::shared_ptr<UIAnimationStyle> m_pressAnimationStyle;
    //==============Press==============
};


}// namespace AuraUI

