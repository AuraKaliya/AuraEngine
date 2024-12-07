#ifndef INSTRUCTIONSYSTEM_H
#define INSTRUCTIONSYSTEM_H

#include <QObject>
#include <QMap>

#include "../../DATA/baseClass/systemobject.h"
#include "../../DATA/BaseClass/instructioncontext.h"
#include "../../DATA/BaseClass/instructionfunctioninfomation.h"
#include "../../DATA/BaseClass/gamedemo.h"
//========================Engine的系统层结构================//
#include "sourcesystem.h"
//========================Engine的系统层结构================//
class InstructionSystem : public SystemObject
{
    Q_OBJECT
public:
    static InstructionSystem* getInstance(QObject *parent = nullptr);
    static void registerInsFunction(QString insName,InsFunction function);
    static void registerInsFunctionInfo(QString insName,const InstructionFunctionInfomation& functionInfo);
    static void soluteInsContext(const InstructionContext& insContext);
    static void setNowDemo(GameDemo* demo);
    static void registDemo(GameDemo* demo);
    static QVector<QString>  getInsFunctionList();
    static InstructionFunctionInfomation getInsFunctionInfo(QString insName);


public:
    bool systemStart() override;
    bool systemInit()  override;
    bool systemClose() override;

private:
    explicit InstructionSystem(QObject *parent = nullptr);

private:
    static InstructionSystem * m_instance;
    static QMap<QString,InsFunction> m_insFunctionDictionary;
    static QMap<QString,InstructionFunctionInfomation> m_insFunctionInfoDictionary;
    static GameDemo * m_nowDemo;
signals:

};

#endif // INSTRUCTIONSYSTEM_H
