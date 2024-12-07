#ifndef SYSTEMOBJECT_H
#define SYSTEMOBJECT_H

#include <QObject>
#include <QString>

#include "../constvalue.h"


#ifdef QDEBUGCHECK
#include <QDebug>
#endif

/*
系统基类---
    系统共性： 状态---属性
    管理者  管理内部属性的组织和共给---object
    注册器  对内部属性进行身份注册---object
    支持者  提供扩展（将自己交出去）---object

*/

class SystemObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ConstValue::SystemState state READ state WRITE setState NOTIFY stateChanged)

public:
protected:
    QObject* m_manager;
    ConstValue::SystemState m_state;

public:
    explicit SystemObject(QObject *parent = nullptr);

    virtual bool systemStart()=0;
    virtual bool systemInit()=0;
    virtual bool systemClose()=0;

    ConstValue::SystemState state() const;
    void setState(ConstValue::SystemState newState);

    int testName() const;
    void setTestName(int newTestName);

signals:
    void stateChanged(ConstValue::SystemState state);


};

#endif // SYSTEMOBJECT_H
