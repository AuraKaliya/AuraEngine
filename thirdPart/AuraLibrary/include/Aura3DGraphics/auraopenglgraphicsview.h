#pragma once

#include <QWidget>
#include <QGraphicsView>
#include "../AuraGlobal.h"
namespace AuraUI {
class AURAUI_LIB_DECL AuraOpenGLGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit AuraOpenGLGraphicsView(QWidget *parent = nullptr);

signals:

};
}//AuraUI
