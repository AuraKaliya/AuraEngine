#ifndef SYSTEMSTATEMACHINE_H
#define SYSTEMSTATEMACHINE_H

#include <QObject>
#include <QState>
#include <QFinalState>
#include <QStateMachine>


class SystemStateMachine : public QStateMachine
{
    Q_OBJECT
public:
    explicit SystemStateMachine(QObject *parent = nullptr);
    void startSystem();

signals:
    void startAllSystem();
};

#endif // SYSTEMSTATEMACHINE_H
