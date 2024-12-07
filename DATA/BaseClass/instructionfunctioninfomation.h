#ifndef INSTRUCTIONFUNCTIONINFOMATION_H
#define INSTRUCTIONFUNCTIONINFOMATION_H

#include <QString>
#include <QVector>

#include "instructioncontext.h"

class InstructionFunctionInfomation
{
public:
    InstructionFunctionInfomation(const QString &insName,const QString& insType,unsigned int argsCount=1);
    InstructionFunctionInfomation(const InstructionFunctionInfomation& other);
    InstructionFunctionInfomation(const InstructionContext & context);
    explicit InstructionFunctionInfomation()=default;

    QString insName() const;
    void setInsName(const QString &newInsName);

    QString insType() const;
    void setInsType(const QString &newInsType);

    unsigned int argsCount() const;
    void setArgsCount(unsigned int newArgsCount);

    QVector<QString> tips() const;
    void setTips(const QVector<QString> &newTips);

private:
    QString m_insName;
    QString m_insType;
    unsigned int m_argsCount;
    QVector<QString> m_tips;
};

#endif // INSTRUCTIONFUNCTIONINFOMATION_H
