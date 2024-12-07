#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H

#include <QObject>
#include <QVector>
#include <QMap>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "../../DATA/baseClass/systemobject.h"

#include "../../DATA/BaseClass/gamedemo.h"
#include "../../DATA/constvalue.h"

//========================Engine的系统层结构================//
#include "rendersystem.h"
#include "scriptsystem.h"
#include "sourcesystem.h"
#include "instructionsystem.h"
//========================Engine的系统层结构================//

//====================Template===================
#include "../Template/CheckTool.hpp"
//====================Template===================

class GameSystem : public SystemObject
{
    Q_OBJECT

public:
    static GameSystem *getInstance(QObject *parent = nullptr);

    bool systemStart() override;
    bool systemInit()  override;
    bool systemClose() override;

    void initNowDemo(const QJsonObject &obj);

    bool initView();
    void startDemo();

    void restartDemo();

    GameDemo *nowDemo() const;
    void setNowDemo(GameDemo *newNowDemo);

    void updateRender();
    void updateScirpt();
    void initMainView(QGraphicsView* view);
private:
    explicit GameSystem(QObject *parent = nullptr);
    static GameSystem* m_instance;

    ConstValue::EngineFPS m_fps;
    GameDemo  * m_nowDemo=nullptr;

    QVector<QGraphicsView*  > m_viewList;
    QVector<QGraphicsScene* > m_sceneList;

    QGraphicsView  * m_nowView=nullptr;
    QGraphicsScene * m_nowScene=nullptr;

    bool m_viewFlag;
signals:

};
//REGISTFUNCTIONFORCHECK(item)



#endif // GAMESYSTEM_H
