#ifndef TESTDEMO_H
#define TESTDEMO_H

#include <QObject>
#include "../DATA/BaseClass/gamedemo.h"

#include "../DATA/BaseClass/gameobject.h"
#include "../TOOL/DemoSystems/demobattlesystem.h"
#include "../TOOL/DemoSystems/demoitemrendersystem.h"
#include "../TOOL/DemoSystems/demomovesystem.h"
#include "../TOOL/DemoSystems/demophysicalsystem.h"

#include "../DATA/Entity/testcharacter.h"
#include "../DATA/Entity/testground.h"

class TestDemo : public GameDemo
{
    Q_OBJECT
public:
    explicit TestDemo(QObject *parent = nullptr);
    void initDemo(const QJsonObject& obj)       override;
    QJsonObject getDemoSource()const            override;
    void updateDemo()                           override;
    void updateRender()                         override;
    void updateItem(GameObject* newGameObject)  override;

    static void TestDemoShowCharacterInfo(const InstructionContext& insContext);
    static void TestDemoAttacked(const InstructionContext& insContext);
    static void TestDemoInitCollisionGetter(const InstructionContext& insContext);
    static void TestDemoCharacterMoved(const InstructionContext& insContext);

    static void CharacterCollideCharacter(GameObject* trigger, GameObject* getter, Model2DMove::Direction direction);
    static void CharacterCollideGround(GameObject* trigger, GameObject* getter, Model2DMove::Direction direction);

protected:
    static void RigidCollision(GameObject* trigger, GameObject* getter, Model2DMove::Direction direction);
private:
    TestCharacter* m_me=nullptr;
    TestCharacter* m_op=nullptr;
    TestCharacter* m_op2=nullptr;

    TestGround * m_ground=nullptr;
signals:

};

REGISTER_CLASS(TestDemo,GameDemo,QObject*)

#endif // TESTDEMO_H
