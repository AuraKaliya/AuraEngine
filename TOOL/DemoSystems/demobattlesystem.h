#ifndef DEMOBATTLESYSTEM_H
#define DEMOBATTLESYSTEM_H

#include <QObject>
#include "../../DATA/BaseClass/demosystemobject.h"
#include "../../DATA/Model/modelbattlebase.h"
#include "../../DATA/Model/model2dhpbar.h"
class DemoBattleSystem : public DemoSystemObject
{
    Q_OBJECT
public:
    explicit DemoBattleSystem(QObject *parent = nullptr);
    void update(GameObject& obj)override;
signals:

};

#endif // DEMOBATTLESYSTEM_H
