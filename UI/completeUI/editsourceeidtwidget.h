#ifndef EDITSOURCEEIDTWIDGET_H
#define EDITSOURCEEIDTWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include "../../DATA/BaseClass/uiwidget.h"


#include "../componentUI/auraswitchwidget01.h"
#include "../componentUI/aurastatelabel01.h"
#include "../componentUI/checkboxlistwidget.h"

//====================system========================
#include "../../TOOL/Systems/sourcesystem.h"
//==================================================



//========================test=======================
#include <QVBoxLayout>
#include "../componentUI/flowlayout.h"
#include "../componentUI/cardlabel.h"
#include "../../DATA/constvalue.h"
#include "../componentUI/gameobjectsampleeditwidget.h"
//========================test=======================

class EditSourceEidtWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit EditSourceEidtWidget(QWidget *parent = nullptr);
    void initWidget()override;
    void sourceUpdate()override;
    void updateLayout();

protected:
    void resizeEvent(QResizeEvent* e)override;
private:
    AuraSwitchWidget01 * m_switchWidget=nullptr;
    QStackedWidget * m_mainEditWidget=nullptr;




    QVector<QWidget*> m_editWidgetList;
signals:

};

REGISTER_CLASS(EditSourceEidtWidget,UIWidget,QWidget*)
#endif // EDITSOURCEEIDTWIDGET_H
