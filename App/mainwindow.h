#pragma once
#include <QMainWindow>

#include "EngineCore/enginecore.h"

using namespace AuraEngine::EngineCore;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    EngineCore m_engineCore;
signals:
};


