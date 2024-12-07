#ifndef EDITINSTRUCTIONEDITWIDGET_H
#define EDITINSTRUCTIONEDITWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QVector>
#include <QMap>

#include "../../DATA/BaseClass/uiwidget.h"
#include "../../DATA/BaseClass/instructionfunctioninfomation.h"
#include "../componentUI/argumenteditwidget.h"
#include "../componentUI/wheelslidewidget.h"


class EditInstructionEditWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit EditInstructionEditWidget(QWidget *parent = nullptr);
    void initWidget()override;
    void setLinkObj(GameObject* obj);
    void initValueList(const InstructionFunctionInfomation & insFunctionInfo);
protected:
    void resizeEvent(QResizeEvent* e)override;
private:
    QVBoxLayout * m_mainLayout=nullptr;
    QHBoxLayout * m_insLinkObjLayout =nullptr;
    QHBoxLayout * m_insBaseInfoLayout = nullptr;
    QHBoxLayout * m_toolBtnLayout =nullptr;

    ArgumentEditWidget* m_idWidget=nullptr;
    QPushButton * m_linkBtn=nullptr;
    ArgumentEditWidget* m_linkStateWidget=nullptr;
    QComboBox* m_insTypeWidget=nullptr;
    QComboBox* m_insNameWidget=nullptr;

    WheelSlideWidget * m_valueWidget=nullptr;

    QPushButton * m_addArgToolBtn =nullptr;
    QPushButton * m_delArgToolBtn =nullptr;
    QPushButton * m_saveInsToolBtn =nullptr;
    QPushButton * m_createInsToolBtn =nullptr;
    QPushButton * m_createAndRunInsToolBtn =nullptr;




    QVector<ArgumentEditWidget*> m_valueWidgetList;
    QMap<QString,QPushButton*> m_toolBtnList;

    GameObject* m_linkObj=nullptr;
    bool m_linkFlag;


signals:
};

#endif // EDITINSTRUCTIONEDITWIDGET_H
