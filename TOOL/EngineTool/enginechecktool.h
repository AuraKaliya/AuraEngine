#ifndef ENGINECHECKTOOL_H
#define ENGINECHECKTOOL_H

#include <QObject>
#include "../../DATA/BaseClass/baseclass.h"
#include "../QtTool/aurapropertytool.h"

class EngineCheckTool : public QObject
{
    Q_OBJECT
public:
    explicit EngineCheckTool(QObject *parent = nullptr);

    static void checkGameObject(GameObject* obj);
signals:

};

#endif // ENGINECHECKTOOL_H
