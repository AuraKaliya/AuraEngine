#ifndef TESTGROUND_H
#define TESTGROUND_H

#include <QObject>
#include "../BaseClass/gameobject.h"

#include "../Model/model2ditem.h"
#include "../Model/model2dcollision.h"

class TestGround : public GameObject
{
    Q_OBJECT
public:
    explicit TestGround(QObject *parent = nullptr);
    void initObject(const QJsonObject & objData) override;
    void initObject()override;
    QJsonObject getMetaData() const override;
    QVector<ObjectItem*> items()override;
signals:

};

REGISTER_CLASS(TestGround,GameObject,QObject*)
REGISTER_COPY_CLASS(TestGround,GameObject,QObject*)
#endif // TESTGROUND_H
