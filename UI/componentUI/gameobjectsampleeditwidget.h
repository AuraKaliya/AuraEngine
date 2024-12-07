#ifndef GAMEOBJECTSAMPLEEDITWIDGET_H
#define GAMEOBJECTSAMPLEEDITWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "../../DATA/BaseClass/baseclass.h"
#include "wheelslidewidget.h"
#include "../../TOOL/QtTool/aurapropertytool.h"
#include "propertyeditwidget.h"
#include "cardlabel.h"
#include "componenteditwidget.h"



class GameObjectSampleEditWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameObjectSampleEditWidget(GameObject * obj,QWidget *parent = nullptr);

    bool initFlag() const;


    static void paintPix(QPainter *p,CardLabel * w);
private:
    void preInit();

private:
    GameObject* m_linkObject=nullptr;

    QVBoxLayout * m_mainLayout              =nullptr;
    QVBoxLayout * m_objPropertyLayout       =nullptr;
    QHBoxLayout * m_headLayout              =nullptr;
    QHBoxLayout * m_bottomLayout            =nullptr;


    bool m_initFlag;
signals:

};

#endif // GAMEOBJECTSAMPLEEDITWIDGET_H
