#ifndef DEMOMOVESYSTEM_H
#define DEMOMOVESYSTEM_H

#include <QObject>
#include "../../DATA/BaseClass/demosystemobject.h"

#include "../../DATA/Model/model2ditem.h"
#include "../../DATA/Model/model2dmove.h"

#include "../../DATA/constvalue.h"
class DemoMoveSystem : public DemoSystemObject
{
    Q_OBJECT
public:
    explicit DemoMoveSystem(QObject *parent = nullptr);
    void update(GameObject& obj)override;
signals:

};

#endif // DEMOMOVESYSTEM_H
