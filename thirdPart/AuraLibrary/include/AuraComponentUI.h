#ifndef AURACOMPONENTUI_H
#define AURACOMPONENTUI_H

/*

    Version:0.0.1
    Author:AuraKaliye

*/
#define _HAS_STD_BYTE 0

#include <QStackedWidget>

#include "AuraGlobal.h"

#include <AuraUIWidget/uiwidget.h>
#include <AuraUIWidget/uiwidget2c.hpp>

#include <AuraUIWidget/labelboxwidget.h>
#include <AuraUIWidget/labelcomboboxwidget.h>
#include <AuraUIWidget/checkboxboxwidget.h>

#include <AuraUIWidget/CardWidget/auracardwidget.h>
#include <AuraUIWidget/CarouselWidget/auracarouselwidget.h>

#include <AuraUIWidget/switchwidget.h>
#include <AuraUIWidget/classifydisplaywidget.h>
#include <AuraUIWidget/wheelslidewidget.h>
#include <AuraUIWidget/hoverlightbtn.h>
#include <AuraUIWidget/auraprogressbar.h>
#include <AuraUIWidget/switchbtn.h>
#include <AuraUIWidget/auradockwidget.h>
#include <AuraUIWidget/auratitlebar.h>
#include <AuraUIWidget/auratreeview.h>
#include <AuraUIWidget/auratreewidget.h>
#include <AuraUIWidget/aurapropertyeditbox.h>
#include <AuraUIWidget/auramultipropertyeditbox.h>
#include <AuraUIWidget/aurapropertyselectbox.h>

#include <AuraUIWidget/aurastartwidgetnormal.h>
#include <AuraUIWidget/auracardlabel.h>

#include <Aura3DGraphics/OpenGL/auraopenglwidget.h>

#include <Aura2DChart/aurachartqcp.h>

namespace AuraUI {

class AuraLibrary_DECL  AuraComponentUI
{
/*
    仅提供获取对象途径，不提供对象管理
*/
public:
    AuraComponentUI();

    //=======================================容器组件特化组件UI=======================================
    static LabelBoxWidget* createLabelBoxWidget(const QString & labelText,QWidget* parent = nullptr);
    static LabelBoxWidget* createLabelBoxWidget(const QString & labelText,bool linkedBuildFlag,QWidget* parent = nullptr);
    static LabelComboBoxWidget* createLabelComboBoxWidget(const QString & labelText,QWidget* parent = nullptr);
    static LabelComboBoxWidget* createLabelComboBoxWidget(const QString & labelText,bool linkedBuildFlag,QWidget* parent = nullptr);
    static CheckBoxBoxWidget* createCheckBoxBoxWidget(const QString & checkBoxText,QWidget* parent = nullptr);
    //=======================================容器组件特化组件UI=======================================


    static ClassifyDisplayWidget* createClassifyDisplayWidget(QWidget* parent = nullptr);
    static AuraChartQCP* createAuraChartQCP(QWidget* parent = nullptr);
    static WheelSlideWidget* createWheelSlideWidget(QWidget* parent =nullptr);
    static HoverLightBtn * createHoverLightBtn(QWidget*parent =nullptr);
    static HoverLightBtn * createHoverLightBtn(const QString & text,QWidget*parent =nullptr);
    static AuraProgressBar* createAuraProgressBar(QWidget*parent =nullptr);
    static AuraSwitchBtn * createSwitchBtn(QWidget* parent =nullptr);
    static AuraDockWidget* createAuraDockWidget(QWidget* parent = nullptr);
    static AuraDockWidget* createAuraDockWidget(const QString& title,QColor bkColor,QWidget* parent = nullptr);
    static AuraTitleBar * createAuraTitleBar(QWidget* parent =nullptr);
    static AuraTitleBar * createAuraTitleBar(const QString& title,QWidget* parent =nullptr);
    static AuraTreeView * createAuraTreeView(QWidget*parent=nullptr);
    static AuraTreeWidget* createAuraTreeWidget(QWidget* parent =nullptr);
    static AuraPropertyEditBox* createAuraPropertyEditBox(QWidget* parent =nullptr);
    static AuraMultiPropertyEditBox* createAuraMultiPropertyEditBox(QWidget* parent = nullptr);
    static AuraPropertySelectBox* createAuraPropertySelectBox(QWidget *parent=nullptr);
    //static AuraRibbonWidgetSA* createAuraRibbonWindowSA(QWidget* parenet =nullptr);

    static AuraCardWidget* createAuraCardWidget(QWidget* parent =nullptr);
    static AuraCarouselWidget* createAuraCarouselWidget(QWidget* parent = nullptr);

    static AuraCardLabel* createAuraCardLabel(QWidget* parent = nullptr);
    static AuraStartWidgetNormal* createAuraStartWidgetNormal(QWidget* parent = nullptr);

    //static AuraOpenGLWidget* createAuraOpenGLWidget(QWidget* parent =nullptr);

    static void init(AuraUIPath path);

public:
    static void printResourceStructure(const QString &path);
private:
    static bool m_initFlag;

};
}// namespace AuraUI
#endif // AURACOMPONENTUI_H
