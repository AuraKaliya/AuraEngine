#pragma once
#include <QMainWindow>

#include "EngineCore/enginecore.h"

using namespace AuraEngine::EngineCore;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AuraMainWindow(QWidget *parent = nullptr);
    void initMenuBar();
private:
    EngineCore m_engineCore;
signals:
};


