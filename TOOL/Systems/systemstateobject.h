#ifndef SYSTEMSTATEOBJECT_H
#define SYSTEMSTATEOBJECT_H

#include <QObject>
#include <QState>
#include "../../DATA/BaseClass/systemobject.h"

class SystemStateObject : public QState
{
    Q_OBJECT
public:
    explicit SystemStateObject(QState *parent = nullptr);

    void connectToSystem(SystemObject* sys);
    void stateSwitch(ConstValue::SystemState  state);
    void connectToWorkingBySignal(const QObject *sender, const char *signal);
    void connectToCloseBySignal(const QObject *sender, const char *signal);

private:
    SystemObject* m_connectSystem=nullptr;
    QState* m_startState=nullptr;
    QState* m_workingState=nullptr;
    QState* m_closeState=nullptr;

signals:
    void nowStateChanged(ConstValue::SystemState);
    void systemStateChanged(SystemObject*);
private slots:
    void stateSwitch();

};

#endif // SYSTEMSTATEOBJECT_H
