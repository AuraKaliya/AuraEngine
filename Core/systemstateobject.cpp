#include "systemstateobject.h"
namespace AuraEngine::Core
{       
SystemStateObject::SystemStateObject(QState *parent)
    : QState{parent}
{
    m_startState=new QState(this);
    m_workingState=new QState(this);
    m_closeState=new QState(this);
}

void SystemStateObject::connectToSystem(SystemObject *sys)
{
    m_connectSystem=sys;

    m_startState    ->assignProperty(sys,"state",(int)SystemState::Start);
    m_workingState  ->assignProperty(sys,"state",(int)SystemState::Working);
    m_closeState    ->assignProperty(sys,"state",(int)SystemState::Close);

    connect(m_workingState, SIGNAL(entered()),      this,SLOT(stateSwitch()),       Qt::ConnectionType(Qt::AutoConnection | Qt::UniqueConnection));
    connect(m_closeState,   SIGNAL(entered()),      this,SLOT(stateSwitch()),       Qt::ConnectionType(Qt::AutoConnection | Qt::UniqueConnection));

    this->setInitialState(m_startState);
}

void SystemStateObject::stateSwitch(SystemState state)
{
    //主动进行状态转换
    //检查
    assert(
        (m_connectSystem!=nullptr)&&(m_startState!=nullptr)
        &&(m_workingState!=nullptr)&&(m_closeState!=nullptr)
           );

    //处理需要转换的状态
    m_connectSystem->setState(state);
    //后续 -通知
    stateSwitch();
}

void SystemStateObject::connectToWorkingBySignal(const QObject *sender, const char *signal)
{
    m_startState->addTransition(sender,signal,m_workingState);

}

void SystemStateObject::connectToCloseBySignal(const QObject *sender, const char *signal)
{
    m_workingState->addTransition(sender,signal,m_closeState);
}

void SystemStateObject::stateSwitch()
{
    emit nowStateChanged(m_connectSystem->state());
    emit systemStateChanged(m_connectSystem);
    
}

}

