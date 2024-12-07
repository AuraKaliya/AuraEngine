#include "enginecore.h"

#include "TOOL/Systems/systemstateobject.h"

#include "TOOL/Systems/sourcesystem.h"
#include "TOOL/Systems/gamesystem.h"
#include "TOOL/Systems/uisystem.h"
#include "TOOL/Systems/rendersystem.h"
#include "TOOL/Systems/scriptsystem.h"
#include "TOOL/Systems/instructionsystem.h"
#include <QKeyEvent>
#include <QTimer>


//=================test================
#include "DEMO/testdemo.h"
#include "UI/completeUI/editinstructioneditwidget.h"
//=================test================




EngineCore::EngineCore(QWidget *parent)
    : UIWidget(parent)
{
/*=====================宏检查====================*/
#ifdef QDEBUGCHECK
    qDebug()<<"Define QDEBUGCHECK";
#endif
/*=====================宏检查====================*/

/*=====================构建全局变量====================*/
    //构建状态机
    m_systemStateMachine= new SystemStateMachine(this);

    //初始化状态机
    QState* engineStartState=new QState(QState::ParallelStates);
    QFinalState* engineStopState=new QFinalState ;
    engineStartState->addTransition(this,SIGNAL(closeEngine()),engineStopState);
    m_systemStateMachine->addState(engineStartState);
    m_systemStateMachine->addState(engineStopState);
    m_systemStateMachine->setInitialState(engineStartState);

    //构建资源系统
    SystemStateObject* stateToSourceSystem=new SystemStateObject(engineStartState);
    stateToSourceSystem->connectToSystem(SourceSystem::getInstance(this));
    stateToSourceSystem->connectToWorkingBySignal(m_systemStateMachine,SIGNAL(startAllSystem()));

    //构建UI系统
    SystemStateObject* stateToUISystem=new SystemStateObject(engineStartState);
    stateToUISystem->connectToSystem(UISystem::getInstance(this));
    stateToUISystem->connectToWorkingBySignal(m_systemStateMachine,SIGNAL(startAllSystem()));

    //构建渲染系统
    SystemStateObject* stateToRenderSystem=new SystemStateObject(engineStartState);
    stateToRenderSystem->connectToSystem(RenderSystem::getInstance(this));
    stateToRenderSystem->connectToWorkingBySignal(m_systemStateMachine,SIGNAL(startAllSystem()));

    //构建脚本系统
    SystemStateObject* stateToScriptSystem=new SystemStateObject(engineStartState);
    stateToScriptSystem->connectToSystem(ScriptSystem::getInstance(this));
    stateToScriptSystem->connectToWorkingBySignal(m_systemStateMachine,SIGNAL(startAllSystem()));

    //构建指令系统
    SystemStateObject* stateToInstructionSystem=new SystemStateObject(engineStartState);
    stateToInstructionSystem->connectToSystem(InstructionSystem::getInstance(this));
    stateToInstructionSystem->connectToWorkingBySignal(m_systemStateMachine,SIGNAL(startAllSystem()));

    //构建游戏系统
    SystemStateObject* stateToGameSystem=new SystemStateObject(engineStartState);
    stateToGameSystem->connectToSystem(GameSystem::getInstance(this));
    stateToGameSystem->connectToWorkingBySignal(m_systemStateMachine,SIGNAL(startAllSystem()));



/*=====================构建全局变量====================end*/
/*=============系统构建完成，进入统一管理启动===============*/
    QTimer *startTimer=new QTimer;
    startTimer->setInterval(20);
    connect(startTimer,&QTimer::timeout,this,[=](){
#ifdef QDEBUGCHECK
        qDebug()<<"startTimer | timeout. ";
#endif
        startTimer->stop();
        startTimer->deleteLater();
        startSystem();

    });
    m_systemStateMachine->start();
    startTimer->start();
/*=============系统构建完成，进入统一管理启动===============end*/

}

EngineCore::~EngineCore()
{
}

void EngineCore::keyPressEvent(QKeyEvent *e)
{

    if(e->key()==Qt::Key_P)
    {
        // TestDemo * demo =new TestDemo(this);
        // GameSystem::getInstance()->setNowDemo(demo);
        // GameSystem::getInstance()->initNowDemo(QJsonObject());
        // GameSystem::getInstance()->initView();

        SourceSystem::loadDemoConfigFile("D:/QTF/ADreamEngine/SOURCE/Demo/TestDemo/TestDemoConfig.json");
        GameSystem::getInstance()->initView();

        EditInstructionEditWidget * testWidget = new EditInstructionEditWidget();
        testWidget->initWidget();
        testWidget->resize(600,400);
        testWidget->show();
    }

    if(e->key()==Qt::Key_O)
    {
        GameSystem::getInstance()->startDemo();
    }


    GlobalKeyValue keyValue;
    //目前支持定义0-9：48~57  a-z:65~90
    if(e->key()>=65&&e->key()<=90)
    {
        *(keyValue.keyDictionaryByChar.find(e->key()-65).value())=true;
    }

    if(e->key()>=48&&e->key()<=57)
    {
        *(keyValue.keyDictionaryByNum.find(e->key()-48).value())=true;
    }

}

void EngineCore::keyReleaseEvent(QKeyEvent *e)
{
    GlobalKeyValue keyValue;

    if(e->key()>=65&&e->key()<=90)
    {
        *(keyValue.keyDictionaryByChar.find(e->key()-65).value())=false;
    }

    if(e->key()>=48&&e->key()<=57)
    {
        *(keyValue.keyDictionaryByNum.find(e->key()-48).value())=false;
    }

}

void EngineCore::paintEvent(QPaintEvent *e)
{
    UIWidget::paintEvent(e);
}

void EngineCore::startSystem()
{
    if(m_systemStateMachine)
    {
        m_systemStateMachine->startSystem();
    }

}
