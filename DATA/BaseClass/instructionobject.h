#ifndef INSTRUCTIONOBJECT_H
#define INSTRUCTIONOBJECT_H

#include <QObject>
#include <QVariant>
#include "gameobject.h"

#include "../../TOOL/Template/Registor.hpp"

class InstructionObject : public QObject
{
    Q_OBJECT
public:
    explicit InstructionObject(GameObject *obj,const QVariant& value,QObject *parent = nullptr);
    virtual void solution();

    GameObject *obj() const;
    void setObj(GameObject *newObj);
    QVariant value() const;
    void setValue(const QVariant &newValue);

protected:
    GameObject* m_obj=nullptr;
    QVariant m_value;
signals:

};

#endif // INSTRUCTIONOBJECT_H
