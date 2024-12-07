#ifndef EDITGAMEEDITWIDGET_H
#define EDITGAMEEDITWIDGET_H

#include <QWidget>
#include <QStackedWidget>



#include "../../DATA/BaseClass/uiwidget.h"

#include "../componentUI/auraswitchwidget01.h"
#include "../componentUI/aurastatelabel01.h"
#include "../componentUI/gameobjecteditwidget.h"
#include "../componentUI/demoeditwidget.h"
#include "../componentUI/itemeditwidget.h"

//=======================test=======================
#include "../../DATA/Entity/testcharacter.h"
//=======================test=======================


class EditGameEditWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit EditGameEditWidget(QWidget *parent = nullptr);
    void initWidget()override;
    void updateLayout();

public slots:
    void setNowGameObject(GameObject*obj);
protected:
    void resizeEvent(QResizeEvent* e)override;
private:
    AuraSwitchWidget01 * m_switchWidget=nullptr;
    QStackedWidget * m_mainEditWidget=nullptr;
    DemoEditWidget* m_demoEditWidget=nullptr;
    GameObjectEditWidget* m_gameObjectEditWidget=nullptr;
    ItemEditWidget * m_itemEditWidget=nullptr;
    QVector<QWidget*> m_editWidgetList;
signals:

};

REGISTER_CLASS(EditGameEditWidget,UIWidget,QWidget*)
#endif // EDITGAMEEDITWIDGET_H
