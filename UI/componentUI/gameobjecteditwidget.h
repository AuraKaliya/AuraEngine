#ifndef GAMEOBJECTEDITWIDGET_H
#define GAMEOBJECTEDITWIDGET_H

#include <QWidget>

#include "../../DATA/BaseClass/uiwidget.h"
#include "../../DATA/BaseClass/baseclass.h"

#include "../../TOOL/QtTool/aurapropertytool.h"

#include "wheelslidewidget.h"
#include "componenteditwidget.h"
#include "propertyeditwidget.h"
class GameObjectEditWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit GameObjectEditWidget(QWidget *parent = nullptr);
    void initWidget()override;
    void setNowGameObject(GameObject* obj);
    void updateWidget();
    void updateValue();
    void updateLayout();
private:
    WheelSlideWidget * m_centerWidget=nullptr;
    GameObject* m_nowGameObject=nullptr;
    QVector<PropertyEditWidget*> m_gameObjectPropertyWidgetList;
    QVector<ComponentEditWidget*> m_componentWidgetList;
signals:

};

#endif // GAMEOBJECTEDITWIDGET_H
