#include "auramainwindow.h"

AuraMainWindow::AuraMainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    setCentralWidget(&m_mainWidget);
}

void AuraMainWindow::initMenuBar()
{

}
