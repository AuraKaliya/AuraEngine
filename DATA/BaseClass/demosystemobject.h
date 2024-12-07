#ifndef DEMOSYSTEM_H
#define DEMOSYSTEM_H

#include <QObject>
#include "gameobject.h"

class DemoSystemObject : public QObject
{
    Q_OBJECT
public:
    explicit DemoSystemObject(QObject *parent = nullptr);
    virtual ~DemoSystemObject();
    virtual void update(GameObject& obj)=0;
signals:
};

#endif // DEMOSYSTEM_H
