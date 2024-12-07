#ifndef COMPONENTEDITWIDGET_H
#define COMPONENTEDITWIDGET_H

#include <QWidget>
#include "../../DATA/BaseClass/uiwidget.h"
#include "../../DATA/BaseClass/baseclass.h"

#include "../../TOOL/QtTool/aurapropertytool.h"

#include "propertyeditwidget.h"

#include "propertytoolwidget.h"


class ComponentEditWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit ComponentEditWidget(QWidget *parent = nullptr);


    void initWidget()override;

    void updateLayout();
    void updateValue();

    void setComponentObj(ComponentObject* cobj);
    ComponentObject* componentObj();

    void loadPropertyToolWidget(PropertyEditWidget * w,const QMetaProperty & property);
protected:
    void resizeEvent(QResizeEvent* e)override;
    void paintEvent(QPaintEvent * e)override;
private:
    ComponentObject* m_componentObj=nullptr;
    QRect m_nameRect;
    QVector<PropertyEditWidget* > m_propertyEditWidgetList;

    int m_nameRectH;
    int m_propertyRectH;


signals:

};

#endif // COMPONENTEDITWIDGET_H
