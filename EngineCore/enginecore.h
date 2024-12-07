#pragma once

/*
引擎之心
1.管理所有系统的各阶段，通过状态机统筹。
2.引擎的主界面，rootWidget
3.存储引擎的各全局数据
·构造函数中创建全局变量、构建各系统
*/
namespace AuraEngine::EngineCore    
{
class EngineCore
{
public:
    EngineCore();
    ~EngineCore();

};
}
