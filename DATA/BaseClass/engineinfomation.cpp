#include "engineinfomation.h"

EngineInfomation::EngineInfomation() {}

QString EngineInfomation::projectName() const
{
    return m_projectName;
}

void EngineInfomation::setProjectName(const QString &newProjectName)
{
    m_projectName = newProjectName;
}

QString EngineInfomation::demoName() const
{
    return m_demoName;
}

void EngineInfomation::setDemoName(const QString &newDemoName)
{
    m_demoName = newDemoName;
}

QString EngineInfomation::dataPath() const
{
    return m_dataPath;
}

void EngineInfomation::setDataPath(const QString &newDataPath)
{
    m_dataPath = newDataPath;
}
