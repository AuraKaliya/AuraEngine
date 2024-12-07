#pragma once

#include <QMainWindow>
#include <QWidget>

#include "DATA/baseClass/baseclass.h"

#include "DATA/constvalue.h"

#include "TOOL/Systems/systemstatemachine.h"

/*
引擎之心
1.管理所有系统的各阶段，通过状态机统筹。
2.引擎的主界面，rootWidget
3.存储引擎的各全局数据

·构造函数中创建全局变量、构建各系统

·其实EngineCore并不适合作为Widget，它应该与UI分离
 (先这么做  等再学学些项目再把这个优化了)

*/

class EngineCore : public UIWidget
{
    Q_OBJECT

public:
    EngineCore(QWidget *parent = nullptr);
    ~EngineCore();
protected:
    void keyPressEvent(QKeyEvent*e)override;
    void keyReleaseEvent(QKeyEvent*e)override;
    void paintEvent(QPaintEvent* e)override;
signals:
    void closeEngine();

private:
    SystemStateMachine* m_systemStateMachine=nullptr;

private slots:

    void startSystem();

};
