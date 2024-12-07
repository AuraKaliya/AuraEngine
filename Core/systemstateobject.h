#pragma once
#include <QObject>
#include <QState>
#include "systemobject.h"

namespace AuraEngine::Core  
{
class AuraEngine_DECL SystemStateObject : public QState
{
    Q_OBJECT
public:
    explicit SystemStateObject(QState *parent = nullptr);

    void connectToSystem(SystemObject* sys);
    void stateSwitch(EngineConstValue::SystemState  state);
    void connectToWorkingBySignal(const QObject *sender, const char *signal);
    void connectToCloseBySignal(const QObject *sender, const char *signal);

private:
    SystemObject* m_connectSystem=nullptr;
    QState* m_startState=nullptr;
    QState* m_workingState=nullptr;
    QState* m_closeState=nullptr;

signals:
    void nowStateChanged(EngineConstValue::SystemState);
    void systemStateChanged(SystemObject*);
private slots:
    void stateSwitch();

};

}

