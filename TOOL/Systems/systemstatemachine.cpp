#include "systemstatemachine.h"

SystemStateMachine::SystemStateMachine(QObject *parent)
    : QStateMachine{parent}
{

}

void SystemStateMachine::startSystem()
{
#ifdef QDEBUGCHECK
    qDebug()<<"SystemStateMachine::startSystem | emit startAllSystem.";
#endif
    emit startAllSystem();
}
