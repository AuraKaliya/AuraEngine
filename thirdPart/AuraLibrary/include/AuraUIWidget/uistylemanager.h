#pragma once

#include <QObject>
#include "uistyle.h"

#include <AuraGlobal.h>

namespace AuraUI {
class UIWidget;

enum class  StyleStratagy : int {
    None=0,
    Style,
    QSS
};

/*
            Style设置约定
    1. 约定 每层Widget只通过Manager设置自己所管理的下一层Widget。
    2. 最外层（Root Widget） 由外部控制。
    3. 通常是在initWidget中 通过Manager设置，然后再在initWidgetStyle中应用。
    4. initWidgetStyle 只设置自己的和非UIWidget部分。
*/
class AURAUI_LIB_DECL UIStyleManager : public QObject
{
    Q_OBJECT
public:

public:
    explicit UIStyleManager(QObject *parent = nullptr);
    static void initStyle(UIWidget* w ,StyleStratagy stratagy,const QString& theme="Default");

public:
    static void initStyleByJson(const QJsonObject& obj);

//=========================Property Style===============================
    static UIStyle getLowerWidgetStyle(UIWidget* w);
    static UIStyle getSplitWidgetStyle();

    static void setWidgetStyle(UIWidget* w);
    static void setLabelStyle(UIWidget* w,unsigned int textLevel=0);
    static void setBtnStyle(UIWidget*w,unsigned int textLevel=0);
    static void setHeadLineStyle(UIWidget* w);
//=========================Property Style===============================

public:
    //====================================================================
    //tool 类 功能型函数
    //窗体样式设置
    static void setQtWidgetBackgroundColor(QWidget* w,QColor color);
    static void setQtWidgetTextColor(QWidget* w,QColor color);
    static void setQtWidgetRadius(QWidget*w,unsigned int radius);
    //对象树部分处理
    static unsigned int getParentLinkListCount(QObject*obj);
    //====================================================================

    static QString styleSheetStr();
    static void setStyleSheetStr(const QString &newStyleSheetStr);

    static QString styleSourceDir();
    static void setStyleSourceDir(const QString &newStyleSourceDir);

    static QString styleName();

protected:
    static bool checkSourceIntegrity();
    static void setWidgetStyle(UIStyle* style,unsigned int level);

    static bool readThemeByQSS(UIWidget* w,const QString & theme);
    static bool readThemeByStyle(UIWidget* w,const QString & theme);
    static void initObjectTreeStyleStratagy(UIWidget*w,StyleStratagy stratagy);
    static void initObjectTreeStyle(UIWidget* w);
    static void applyObjectTreeStyle(UIWidget* w);
private:
    static bool m_sourceIntegrityFlag;
    static QString m_styleName;
    static QString m_styleSourceDir;
    //static QMap<QString,UIBaseStyle*> m_normalBaseStyleDictionary;
    static QMap<QString,std::shared_ptr<UIBaseStyle>> m_normalBaseStyleDictionary;
    static QString m_styleSheetStr;
signals:

};

}// namespace AuraUI
