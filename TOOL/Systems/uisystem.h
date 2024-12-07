#ifndef UISYSTEM_H
#define UISYSTEM_H

#include <QMainWindow>
#include <QMenuBar>
#include <QObject>
#include <QMap>
#include <QString>

#include "../../DATA/baseClass/systemobject.h"

#include "../../DATA/BaseClass/uiwidget.h"
#include "../../DATA/constvalue.h"

//====================搭载反射===============//
#include "../Template/Factory.hpp"
//====================搭载反射===============//

//========================Engine的系统层结构================//
//ui应该是最顶层的
#include "gamesystem.h"
//========================Engine的系统层结构================//

class UISystem : public SystemObject
{
    Q_OBJECT
public:

    static UISystem*getInstance(QObject *parent = nullptr);

    bool systemStart() override;
    bool systemInit()  override;
    bool systemClose() override;

    void initUI();
    void loadUI(const QJsonObject & obj);
    void uiConnections();


    //==========test=============//
    void testLoadUI();
    //==========test=============//

    void initMenu(QMenuBar* menuBar);
private:
    explicit UISystem(QObject *parent = nullptr);
    static UISystem* m_instance;

    ConstValue::EngineOptions m_engineOption;


    //========同质的map可以通过struct进行整合
    QMap<QString,UIWidget*> m_uiDictionary;
    //====test====
    QMap<QString,QRect> m_uiRectDictionary;
    //====test====



    UIWidget * m_rootWidget=nullptr;
    QMainWindow * m_mainWindow=nullptr;

    bool m_initFlag;


signals:

};

#endif // UISYSTEM_H
