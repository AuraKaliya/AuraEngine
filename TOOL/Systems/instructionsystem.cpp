#include "instructionsystem.h"


InstructionSystem * InstructionSystem::m_instance=nullptr;
QMap<QString,InsFunction> InstructionSystem::m_insFunctionDictionary{};
QMap<QString,InstructionFunctionInfomation> InstructionSystem::m_insFunctionInfoDictionary;
GameDemo * InstructionSystem::m_nowDemo=nullptr;
InstructionSystem *InstructionSystem::getInstance(QObject *parent)
{
    if(m_instance==nullptr)
    {
        m_instance=new InstructionSystem(parent);
    }
    return m_instance;
}

void InstructionSystem::registerInsFunction(QString insName, InsFunction function)
{
    m_insFunctionDictionary[insName]=function;
}

void InstructionSystem::registerInsFunctionInfo(QString insName, const InstructionFunctionInfomation &functionInfo)
{
    m_insFunctionInfoDictionary[insName]=functionInfo;
}

void InstructionSystem::soluteInsContext(const InstructionContext &insContext)
{
    /*
        1. obj id  --> 代表触发/发出指令的单位
        2. insName  --> 指令名
        3. insType  --> 指令类型   Function / Object
        4. insParagram -->指令参数  按顺序集成QVariant
        5. ...
        -1. 具体参数个数   从4开始计算
    */

    QString insName= insContext.insName();
    if(insName.isEmpty()) return;

    if(insContext.insType()=="Function")
    {
       m_insFunctionDictionary[insName](insContext);
    }
    else
    {
       //生成insObject处理

    }
}

void InstructionSystem::setNowDemo(GameDemo *demo)
{
    if(demo)
    {
        m_nowDemo = demo;

        //切换demo后，将清空 demo相关资源 ，以便重新注册
        m_insFunctionDictionary.clear();
        m_insFunctionInfoDictionary.clear();

        registDemo(demo);
    }
}

void InstructionSystem::registDemo(GameDemo *demo)
{
    if(!demo) return;
    m_nowDemo=demo;

    for(auto it: demo->insFunctionList())
    {
        registerInsFunction(it.first,it.second);
    }
    for(int i=0;i< demo->insFunctionInfoList().size() ;++i)
    {
        registerInsFunctionInfo(demo->insFunctionInfoList()[i].insName(),demo->insFunctionInfoList()[i]);
    }

}

QVector<QString> InstructionSystem::getInsFunctionList()
{
    return m_insFunctionDictionary.keys();
}

InstructionFunctionInfomation InstructionSystem::getInsFunctionInfo(QString insName)
{
    auto it =m_insFunctionInfoDictionary.find(insName);
    if(it == m_insFunctionInfoDictionary.end())
    {
        return InstructionFunctionInfomation("Default","Function");
    }
    InstructionFunctionInfomation insFunctionInfo(it.value());
    return insFunctionInfo;
}

bool InstructionSystem::systemStart()
{
    return true;
}

bool InstructionSystem::systemInit()
{
#ifdef QDEBUGCHECK
    qDebug()<<"InstructionSystem::systemInit | √ ";
#endif

    connect(SourceSystem::getInstance(),&SourceSystem::sourceLoadDemo,this,[this](GameDemo* demo){
        setNowDemo(demo);
    });

 return true;
}

bool InstructionSystem::systemClose()
{
 return true;
}

InstructionSystem::InstructionSystem(QObject *parent)
    : SystemObject{parent}
{

}
