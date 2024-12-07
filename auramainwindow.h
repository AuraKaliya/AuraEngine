#ifndef AURAMAINWINDOW_H
#define AURAMAINWINDOW_H

#include <QMainWindow>

#include "enginecore.h"




class AuraMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AuraMainWindow(QWidget *parent = nullptr);
    void initMenuBar();
private:
    EngineCore m_engineCore;
    EngineCore& m_mainWidget=m_engineCore;
signals:
};

#endif // AURAMAINWINDOW_H
