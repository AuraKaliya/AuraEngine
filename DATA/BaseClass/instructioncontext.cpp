#include "instructioncontext.h"

InstructionContext::InstructionContext(GameObject *obj, const QString &insName, const QString &insType, const QVariant &value)
    :m_obj(obj),m_insName(insName),m_insType(insType),m_value(value)
{

}

QString InstructionContext::insName() const
{
    return m_insName;
}

QString InstructionContext::insType() const
{
    return m_insType;
}

QVariant InstructionContext::value() const
{
    return m_value;
}

GameObject *InstructionContext::obj() const
{
    return m_obj;
}

void InstructionContext::setObj(GameObject *newObj)
{
    m_obj = newObj;
}

void InstructionContext::setInsName(const QString &newInsName)
{
    m_insName = newInsName;
}

void InstructionContext::setInsType(const QString &newInsType)
{
    m_insType = newInsType;
}

void InstructionContext::setValue(const QVariant &newValue)
{
    m_value = newValue;
}
