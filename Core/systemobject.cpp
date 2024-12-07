#include "systemobject.h"

namespace AuraEngine::Core  
{

EngineConstValue::SystemState SystemObject::state() const
{
    return m_state;
}

void SystemObject::setState(EngineConstValue::SystemState newState)
{
    m_state = newState;
    emit stateChanged(m_state);
}

SystemObject::SystemObject(QObject *parent)
    : QObject{parent},m_state(EngineConstValue::SystemState::Start)
{

    connect(this,&SystemObject::stateChanged,this,[&](){
        switch (m_state) {
        case EngineConstValue::SystemState::Start:
            systemStart();
            break;
        case EngineConstValue::SystemState::Working:
            systemInit();
            break;
        case EngineConstValue::SystemState::Close:
            systemClose();
            break;
        default:
            break;
        }
    });
}

}
