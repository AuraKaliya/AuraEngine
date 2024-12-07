#ifndef DEMOPHYSICALSYSTEM_H
#define DEMOPHYSICALSYSTEM_H

#include <QObject>
#include <QVector2D>
#include "../../DATA/BaseClass/demosystemobject.h"

#include "../../DATA/Model/model2dmove.h"

#include "../../DATA/Model/model2dhpbar.h"
#include "../../DATA/Model/model2ditem.h"

#include "../../DATA/Model/model2dcollision.h"

class DemoPhysicalSystem : public DemoSystemObject
{
    Q_OBJECT
public:
    explicit DemoPhysicalSystem(QObject *parent = nullptr);
     void update(GameObject& obj)override;

    bool rayCheck(QRectF rect,QVector2D startPos,QVector2D direction,double length,int zValueRange);
    bool rayCheck(QRectF rect,QVector2D startPos,QVector2D direction,double length);
    bool rectCheck(QRectF rect1,QRectF rect2);
signals:

};

#endif // DEMOPHYSICALSYSTEM_H
