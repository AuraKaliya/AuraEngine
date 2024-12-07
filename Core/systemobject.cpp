#include "systemobject.h"

namespace AuraEngine::Core  
{

SystemState SystemObject::state() const
{
    return m_state;
}

void SystemObject::setState(SystemState newState)
{
    m_state = newState;
    emit stateChanged(m_state);
}

SystemObject::SystemObject(QObject *parent)
    : QObject{parent},m_state(SystemState::Start)
{

    connect(this,&SystemObject::stateChanged,this,[&](){
        switch (m_state) {
        case SystemState::Start:
            systemStart();
            break;
        case SystemState::Working:
            systemInit();
            break;
        case SystemState::Close:
            systemClose();
            break;
        default:
            break;
        }
    });
}

}
