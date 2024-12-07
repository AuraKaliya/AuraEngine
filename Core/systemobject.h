#pragma once
#include <QObject>
#include <QString>

#include "EngineRef.hpp"
#include "EngineConstValue.hpp"
/*
系统基类---
    系统共性： 状态---属性
    管理者  管理内部属性的组织和共给---object
    注册器  对内部属性进行身份注册---object
    支持者  提供扩展（将自己交出去）---object

*/

namespace AuraEngine::Core  
{
class SystemObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ConstValue::SystemState state READ state WRITE setState NOTIFY stateChanged)

public:

protected:
    QObject* m_manager;
    SystemState m_state;

public:
    explicit SystemObject(QObject *parent = nullptr);

    virtual bool systemStart()=0;
    virtual bool systemInit()=0;
    virtual bool systemClose()=0;

    SystemState state() const;
    void setState(SystemState newState);

    int testName() const;
    void setTestName(int newTestName);

signals:
    void stateChanged(SystemState state);
};

}

