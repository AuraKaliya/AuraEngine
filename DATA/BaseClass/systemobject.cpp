#include "systemobject.h"
#include <QDebug>

ConstValue::SystemState SystemObject::state() const
{
    return m_state;
}

void SystemObject::setState(ConstValue::SystemState newState)
{
    m_state = newState;
    emit stateChanged(m_state);
}

SystemObject::SystemObject(QObject *parent)
    : QObject{parent},m_state(ConstValue::SystemState::Start)
{

    connect(this,&SystemObject::stateChanged,this,[&](){
#ifdef QDEBUGCHECK
        //qDebug()<<" SystemObject Get Signal SystemObject::stateChanged | now state | "<<m_state;
#endif
        switch (m_state) {
        case ConstValue::SystemState::Start:
            systemStart();
            break;
        case ConstValue::SystemState::Working:
            systemInit();
            break;
        case ConstValue::SystemState::Close:
            systemClose();
            break;
        default:
            break;
        }
    });
}
