#ifndef INSTRUCTIONCONTEXT_H
#define INSTRUCTIONCONTEXT_H

#include <QString>
#include <QVariant>
#include "gameobject.h"


class InstructionContext
{
public:
    InstructionContext(GameObject*obj,const QString & insName,const QString& insType, const QVariant& value);

    QString insName() const;

    QString insType() const;

    QVariant value() const;

    GameObject *obj() const;

    void setObj(GameObject *newObj);

    void setInsName(const QString &newInsName);

    void setInsType(const QString &newInsType);

    void setValue(const QVariant &newValue);

private:
    GameObject* m_obj=nullptr;
    QString m_insName;
    QString m_insType;
    QVariant  m_value;
};

using  InsFunction=void(*)(const InstructionContext& );

#endif // INSTRUCTIONCONTEXT_H
