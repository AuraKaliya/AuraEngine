#include "instructionfunctioninfomation.h"

InstructionFunctionInfomation::InstructionFunctionInfomation(const QString &insName, const QString &insType, unsigned int argsCount)
    : m_insName(insName)
    , m_insType(insType)
{
    setArgsCount(argsCount);
}

InstructionFunctionInfomation::InstructionFunctionInfomation(const InstructionFunctionInfomation &other)
{
    m_insName =other.m_insName;
    m_insType =other.m_insType;
    m_argsCount =other.m_argsCount;
    m_tips =other.m_tips;
}

InstructionFunctionInfomation::InstructionFunctionInfomation(const InstructionContext &context)
{
    setInsName(context.insName());
    setInsType(context.insType());
    setArgsCount(context.value().toList().count());
}

QString InstructionFunctionInfomation::insName() const
{
    return m_insName;
}

void InstructionFunctionInfomation::setInsName(const QString &newInsName)
{
    m_insName = newInsName;
}

QString InstructionFunctionInfomation::insType() const
{
    return m_insType;
}

void InstructionFunctionInfomation::setInsType(const QString &newInsType)
{
    m_insType = newInsType;
}

unsigned int InstructionFunctionInfomation::argsCount() const
{
    return m_argsCount;
}

void InstructionFunctionInfomation::setArgsCount(unsigned int newArgsCount)
{
    m_argsCount = newArgsCount;
    m_tips.resize(m_argsCount);
    m_tips.fill("Default");
}

QVector<QString> InstructionFunctionInfomation::tips() const
{
    return m_tips;
}

void InstructionFunctionInfomation::setTips(const QVector<QString> &newTips)
{
    m_tips = newTips;
}
