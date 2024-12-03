#pragma once

#include <QObject>
#include <QGraphicsScene>
#include "../AuraGlobal.h"
namespace AuraUI {
class AURAUI_LIB_DECL AuraOpenGLGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit AuraOpenGLGraphicsScene(QObject *parent = nullptr);

signals:

};

}//AuraUI
