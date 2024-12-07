#include "instructionobject.h"


InstructionObject::InstructionObject(GameObject *obj, const QVariant &value, QObject *parent)
    :QObject{parent} ,m_obj(obj),m_value(value)
{

}

void InstructionObject::solution()
{

}

GameObject *InstructionObject::obj() const
{
    return m_obj;
}

void InstructionObject::setObj(GameObject *newObj)
{
    m_obj = newObj;
}

QVariant InstructionObject::value() const
{
    return m_value;
}

void InstructionObject::setValue(const QVariant &newValue)
{
    m_value = newValue;
}
