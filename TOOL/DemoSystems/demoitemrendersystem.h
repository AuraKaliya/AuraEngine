#ifndef DEMOITEMRENDERSYSTEM_H
#define DEMOITEMRENDERSYSTEM_H

#include <QObject>
#include "../../DATA/BaseClass/demosystemobject.h"
#include "../../DATA/Model/model2ditem.h"
#include "../../DATA/Model/model2dhpbar.h"
class DemoItemRenderSystem : public DemoSystemObject
{
    Q_OBJECT
public:
    explicit DemoItemRenderSystem(QObject *parent = nullptr);
    void update(GameObject& obj)override;
signals:

};

#endif // DEMOITEMRENDERSYSTEM_H
