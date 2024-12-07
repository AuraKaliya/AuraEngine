#ifndef TESTCHARACTER_H
#define TESTCHARACTER_H

#include <QObject>
#include "../BaseClass/gameobject.h"

#include "../Model/modelbattlebase.h"
#include "../Model/model2ditem.h"
#include "../Model/model2dhpbar.h"
#include "../Model/modelscript.h"

#include "../Model/model2dmove.h"
#include "../Model/model2dcollision.h"


class TestCharacter : public GameObject
{
    Q_OBJECT
public:
    explicit TestCharacter(/*bool initByJsonFlag=false,*/QObject *parent = nullptr);
    void initObject(const QJsonObject & objData) override;
    void initObject()override;
    QJsonObject getMetaData() const override;
    QVector<ObjectItem*> items()override;

private:
    void initModel2DItem(const QJsonObject & objData);
signals:

};

REGISTER_CLASS(TestCharacter,GameObject,QObject*)
//REGISTER_CLASS(TestCharacter,GameObject,bool,QObject*)
REGISTER_COPY_CLASS(TestCharacter,GameObject,QObject*)
#endif // TESTCHARACTER_H
