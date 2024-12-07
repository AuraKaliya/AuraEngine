#include "testdemo.h"

TestDemo::TestDemo(QObject *parent)
    : GameDemo{parent}
{
    // 改为DemoName
    setObjectName("TestDemo");

    addDemoSystem(new DemoBattleSystem(this));
    addDemoSystem(new DemoItemRenderSystem(this));
    addDemoSystem(new DemoMoveSystem(this));
    addDemoSystem(new DemoPhysicalSystem(this));

    addInsFunction("TestDemoShowCharacterInfo",TestDemoShowCharacterInfo);
    addInsFunction("TestDemoAttacked",TestDemoAttacked,QVector<QString>{"OppoId"});
    addInsFunction("TestDemoInitCollisionGetter",TestDemoInitCollisionGetter,QVector<QString>{"LinkObjId","CCC/CCG"});
}

void TestDemo::initDemo(const QJsonObject &obj)
{
    // // 仅做测试， 实际上的初始化应该由Demo对obj数据进行分发，在GameObject内进行
    // //=================================================//
    // m_ground=new TestGround(this);
    // m_ground->initObject();

    // //m_ground->setId(1008);
    // m_ground->setName("TestGround");

    // m_ground->getComponent<Model2DItem>()->setPixPath(ConstValue::SourceDir().path()+"/Demo/TestDemo/Image/TestGround1.png");
    // m_ground->getComponent<Model2DItem>()->setPixHeight(50);
    // m_ground->getComponent<Model2DItem>()->setPixWidth(800);
    // m_ground->getComponent<Model2DItem>()->setX(0);
    // m_ground->getComponent<Model2DItem>()->setY(300);
    // m_ground->getComponent<Model2DItem>()->setSceneId(0);

    // for(auto it:m_ground->items())
    // {
    //     m_itemList.append(it);
    // }

    // m_me=new TestCharacter(this);
    // m_me->initObject();

    // //m_me->setId(10086);
    // m_me->setName("Luwies");

    // m_me->getComponent<ModelBattleBase>()->setATK(20);
    // m_me->getComponent<ModelBattleBase>()->setDEF(12);
    // m_me->getComponent<ModelBattleBase>()->setHP(200);

    // m_me->getComponent<Model2DItem>()->setPixPath(ConstValue::SourceDir().path()+"/Demo/TestDemo/Image/Luwies.png");
    // m_me->getComponent<Model2DItem>()->setPixHeight(160);
    // m_me->getComponent<Model2DItem>()->setPixWidth(90);
    // m_me->getComponent<Model2DItem>()->setX(30);
    // m_me->getComponent<Model2DItem>()->setY(100);
    // m_me->getComponent<Model2DItem>()->setSceneId(0);

    // m_me->getComponent<Model2DHPBar>()->setMaxHP(200);
    // m_me->getComponent<Model2DHPBar>()->setNowHP(200);
    // m_me->getComponent<Model2DHPBar>()->setPixHeight(30);
    // m_me->getComponent<Model2DHPBar>()->setPixWidth(90);
    // m_me->getComponent<Model2DHPBar>()->setX(30);
    // m_me->getComponent<Model2DHPBar>()->setY(60);
    // m_me->getComponent<Model2DHPBar>()->setSceneId(0);
    // m_me->getComponent<Model2DHPBar>()->setHPColor(QColor(Qt::green));

    // m_me->getComponent<ModelScript>()->setScriptPath(ConstValue::SourceDir().path()+"/Demo/TestDemo/Script/test.lua");
    // m_scriptsList.append(m_me->getComponent<ModelScript>()->script());

    // m_me->getComponent<Model2DMove>()->setXResistance(3.0);
    // m_me->getComponent<Model2DMove>()->setYResistance(3.0);
    // m_me->getComponent<Model2DMove>()->setGravityFlag(true);
    // m_me->getComponent<Model2DMove>()->setGravity(5.0);

    // for(auto it:m_me->items())
    // {
    //     m_itemList.append(it);
    // }
    // //=================================================//

    // //=================================================//
    // m_op=new TestCharacter(this);
    // m_op->initObject();

    // //m_op->setId(112423);
    // m_op->setName("Lilyan");

    // m_op->getComponent<ModelBattleBase>()->setATK(15);
    // m_op->getComponent<ModelBattleBase>()->setDEF(8);
    // m_op->getComponent<ModelBattleBase>()->setHP(178);

    // m_op->getComponent<Model2DItem>()->setPixPath(ConstValue::SourceDir().path()+"/Demo/TestDemo/Image/Lilyan.png");
    // m_op->getComponent<Model2DItem>()->setPixHeight(160);
    // m_op->getComponent<Model2DItem>()->setPixWidth(90);
    // m_op->getComponent<Model2DItem>()->setX(230);
    // m_op->getComponent<Model2DItem>()->setY(100);
    // m_op->getComponent<Model2DItem>()->setSceneId(0);

    // m_op->getComponent<Model2DHPBar>()->setMaxHP(178);
    // m_op->getComponent<Model2DHPBar>()->setNowHP(178);
    // m_op->getComponent<Model2DHPBar>()->setPixHeight(30);
    // m_op->getComponent<Model2DHPBar>()->setPixWidth(90);
    // m_op->getComponent<Model2DHPBar>()->setX(230);
    // m_op->getComponent<Model2DHPBar>()->setY(60);
    // m_op->getComponent<Model2DHPBar>()->setSceneId(0);
    // m_op->getComponent<Model2DHPBar>()->setHPColor(QColor(Qt::red));

    // for(auto it:m_op->items())
    // {
    //     m_itemList.append(it);
    // }
    // //=================================================//

    // //=================================================//
    // m_op2=new TestCharacter(this);
    // m_op2->initObject();

    // //m_op2->setId(114514);
    // m_op2->setName("LanDu");

    // m_op2->getComponent<ModelBattleBase>()->setATK(15);
    // m_op2->getComponent<ModelBattleBase>()->setDEF(8);
    // m_op2->getComponent<ModelBattleBase>()->setHP(150);

    // m_op2->getComponent<Model2DItem>()->setPixPath(ConstValue::SourceDir().path()+"/Demo/TestDemo/Image/LanDu.png");
    // m_op2->getComponent<Model2DItem>()->setPixHeight(160);
    // m_op2->getComponent<Model2DItem>()->setPixWidth(90);
    // m_op2->getComponent<Model2DItem>()->setX(530);
    // m_op2->getComponent<Model2DItem>()->setY(100);
    // m_op2->getComponent<Model2DItem>()->setSceneId(0);

    // m_op2->getComponent<Model2DHPBar>()->setMaxHP(178);
    // m_op2->getComponent<Model2DHPBar>()->setNowHP(150);
    // m_op2->getComponent<Model2DHPBar>()->setPixHeight(30);
    // m_op2->getComponent<Model2DHPBar>()->setPixWidth(90);
    // m_op2->getComponent<Model2DHPBar>()->setX(530);
    // m_op2->getComponent<Model2DHPBar>()->setY(60);
    // m_op2->getComponent<Model2DHPBar>()->setSceneId(0);
    // m_op2->getComponent<Model2DHPBar>()->setHPColor(QColor(Qt::red));

    // for(auto it:m_op2->items())
    // {
    //     m_itemList.append(it);
    // }

    // //=================================================//


    // //=================================================//
    // // 后续处理
    // m_me->getComponent<ModelBattleBase>()->setBattleObject(m_op);
    // m_op->getComponent<ModelBattleBase>()->setBattleObject(m_me);
    // m_op2->getComponent<ModelBattleBase>()->setBattleObject(m_me);

    // m_me->getComponent<Model2DCollision>()->addGetter(m_op);
    // m_me->getComponent<Model2DCollision>()->addGetter(m_op2);
    // m_me->getComponent<Model2DCollision>()->addGetter(m_ground);

    // m_op->getComponent<Model2DCollision>() ->setGetterFunction(CharacterCollideCharacter);
    // m_op2->getComponent<Model2DCollision>()->setGetterFunction(CharacterCollideCharacter);

    // m_ground->getComponent<Model2DCollision>()->setGetterFunction(CharacterCollideGround);

    // //=================================================//

    // //scene
    // m_sceneRectList.append(QRectF(0,0,500,500));
    // setSceneCount(1);

    // //GameObject Dictionary
    // addGameObject(m_me);
    // addGameObject(m_op);
    // addGameObject(m_op2);
    // addGameObject(m_ground);

    // //ClassInfo
    // addObjClass("TestCharacter");
    // addObjClass("TestGround");
    // addComponentClass("ModelBattleBase");
    // addComponentClass("Model2DItem");
    // addComponentClass("Model2DHPBar");
    // addComponentClass("ModelScript");
    // addComponentClass("Model2DMove");
    // addComponentClass("Model2DCollision");


    GameDemo::initDemo(obj);


    //延迟处理部分--放在所有Obj都构建完成后再进行处理  （考虑到obj之间的link）
    for(auto obj :m_gameObjectDictionary.values())
    {
        //test
        if(!m_me &&obj->objClass()=="TestCharacter")
        {
            m_me =reinterpret_cast<TestCharacter*>(obj);
        }
        if(!m_ground && obj->objClass() == "TestGround")
        {
            m_ground = reinterpret_cast<TestGround*>(obj);
        }
        //test




        if(obj->delayInitFlag())
        {
            // 1. Collision
            auto collisionComponent =obj->getComponent<Model2DCollision>();
            if(collisionComponent)
            {
                //qDebug()<<"===============================collision";
                auto collisionType =collisionComponent->getDelayPropertyValue("CollisionType");
                //qDebug()<<collisionType;
                if(collisionType == "S")
                {
                    for(auto it : collisionComponent->getDelayPropertyValue("GetterIdList").split(","))
                    {
                        auto id = it.toUInt();
                        auto targetObj = getGameObject<GameObject>(id);
                        if(targetObj)
                        {
                            //qDebug()<<" target Obj ====================="<<targetObj->objClass();
                            collisionComponent->addGetter(targetObj);
                        }
                    }
                }
                else if(collisionType == "G")
                {
                    //此处可用策略模式优化
                    auto getterFunction = collisionComponent->getDelayPropertyValue("GetterFunction");
                    //qDebug()<<"G:"<<getterFunction;
                    if(getterFunction =="CCG")
                    {
                        //qDebug()<<"==========ground getter CCG";
                        collisionComponent->setGetterFunction(CharacterCollideGround);
                    }
                    else if(getterFunction =="CCC")
                    {
                        collisionComponent->setGetterFunction(CharacterCollideCharacter);
                    }
                    else
                    {

                    }

                }
                else
                {

                }

                //other
                collisionComponent->setInitFlag(true);
            }
            //Collision end

            //2. BattleBase
            auto battleBaseComponent =obj->getComponent<ModelBattleBase>();
            if(battleBaseComponent)
            {
                auto id = collisionComponent->getDelayPropertyValue("BattleObject").toUInt();
                auto targetObj = getGameObject<GameObject>(id);
                if(targetObj)
                {
                    battleBaseComponent->setBattleObject(targetObj);
                }
                else
                {
#ifdef QDEBUGCHECK
                    qDebug()<<"TestDemo::initDemo | no have this objId:"<<id;
#endif
                }

                collisionComponent->setInitFlag(true);
            }
            //BattleBase end

        }//delay solve

        //other
        //test
        if(m_me && m_ground)
        {

            m_me->getComponent<Model2DCollision>()->addGetter(m_ground);
        }
        //test
    }

    m_initFlag=true;
}

QJsonObject TestDemo::getDemoSource() const
{
    QJsonObject obj;
    return obj;
}

void TestDemo::updateDemo()
{
    //===========test================

    //battle 放进指令中，通过script调用
    //addUpdateInfo<DemoBattleSystem>(m_me);
    //addUpdateInfo<DemoBattleSystem>(m_op);

    if(m_me)
    {
        addUpdateInfo<DemoMoveSystem>(m_me);
        addUpdateInfo<DemoPhysicalSystem>(m_me);
    }

    //===========test================

    //这里更新的是逻辑帧
    GameDemo::updateDemo();

    //需要有默认的游戏退出的方法   其余方式通过指令、响应函数、脚本、系统等进行确定
    //可通过模板设计一个通用的退出的方法的接口，在此处进行调用
    // if(
    //     !m_me->getComponent<ModelBattleBase>()->getSurvivalState() ||
    //     (!m_op->getComponent<ModelBattleBase>()->getSurvivalState() && !m_op2->getComponent<ModelBattleBase>()->getSurvivalState())

    //     )

    // {
    //     m_quitFlag=true;
    // }
    if(m_quitFlag)
    {
        // 符合退出条件，进行后续处理。
    }

}

void TestDemo::updateRender()
{
    // m_demoSystemDictionary[typeid(DemoItemRenderSystem).name()]->update(*m_me);
    // m_demoSystemDictionary[typeid(DemoItemRenderSystem).name()]->update(*m_op);
    // m_demoSystemDictionary[typeid(DemoItemRenderSystem).name()]->update(*m_op2);
}

void TestDemo::updateItem(GameObject *newGameObject)
{
    if(TestCharacter* character = dynamic_cast<TestCharacter*>(newGameObject))
    {
        for(auto it:character->items())
        {
            m_newItemList.append(it);
        }
        return ;
    }

    if(TestGround * ground = dynamic_cast<TestGround*>(newGameObject))
    {
        for(auto it:ground->items())
        {
            m_newItemList.append(it);
        }
        return ;
    }

#ifdef QDEBUGCHECK
    qDebug()<<"TestDemo::updateItem | obj:"<<newGameObject->objClass()<<" no item.";
#endif
}

void TestDemo::TestDemoShowCharacterInfo(const InstructionContext &insContext)
{
    if(!nowDemo()) return;

    if(!insContext.obj()) return ;

    qDebug()<<"=====TestDemo::TestDemoShowCharacterInfo=====";
    qDebug()<<"Get ins name: "<<insContext.insName();
    qDebug()<<"ins values: "<<insContext.value();
    qDebug()<<"Show the Character: "<<insContext.obj()->name();

    ModelBattleBase * battleInfo=insContext.obj()->getComponent<ModelBattleBase>();
    if(!battleInfo)
    {
        qDebug()<<"TestDemo::TestDemoShowCharacterInfo | no have model ModelBattleBase";
    }
    else
    {
        qDebug()<<"ATK: "<<battleInfo->getATK();
        qDebug()<<"DEF: "<<battleInfo->getDEF();
        qDebug()<<"HP: "<<battleInfo->getHP();
    }
    qDebug()<<"=====TestDemo::TestDemoShowCharacterInfo=====end";
}

void TestDemo::TestDemoAttacked(const InstructionContext &insContext)
{
    if(!nowDemo()) return;

    if(!insContext.obj()) return ;

    qDebug()<<"=====TestDemo::TestDemoAttacked=====";
    qDebug()<<"Get ins name: "<<insContext.insName();
    qDebug()<<"ins values: "<<insContext.value();
    qDebug()<<"Character: "<<insContext.obj()->name();

    /*
        1. obj id
    */
    qDebug()<<" check value : id"<<insContext.value().toList()[0].toUInt();
    TestCharacter * op=nowDemo()->getGameObject<TestCharacter>(insContext.value().toList()[0].toUInt());

    if(!op) return;
    qDebug()<<" now battle with "<<op->name();
    insContext.obj()->getComponent<ModelBattleBase>()->setBattleObject(op);
    op->getComponent<ModelBattleBase>()->setBattleObject(insContext.obj());

    nowDemo()->addUpdateInfo<DemoBattleSystem>(insContext.obj());
    nowDemo()->addUpdateInfo<DemoBattleSystem>(op);
    qDebug()<<"=====TestDemo::TestDemoAttacked=====end";
}

void TestDemo::TestDemoInitCollisionGetter(const InstructionContext &insContext)
{
    if(!nowDemo()) return;

    if(!insContext.obj()) return ;

    if(insContext.value().toList().size()<2) return;

    qDebug()<<"=====TestDemo::TestDemoInitCollisionGetter=====";
    qDebug()<<"Get ins name: "<<insContext.insName();
    qDebug()<<"ins values: "<<insContext.value();
    qDebug()<<"Obj: "<<insContext.obj()->name();

    GameObject * linkObj=nowDemo()->getGameObject<GameObject>(insContext.value().toList()[0].toUInt());

    if(!linkObj) return ;
    qDebug()<<" now link :"<<linkObj->name();

    auto objModel2DCollision = insContext.obj()->getComponent<Model2DCollision>();
    auto linkObjModel2DCollision = linkObj->getComponent<Model2DCollision>();

    if(!objModel2DCollision || !linkObjModel2DCollision) return ;

    objModel2DCollision->addGetter(linkObj);

    // 用List的序号来替换  ---->switch    ---> 写成策略模式
    QString functionName=insContext.value().toList()[1].toString();
    if( functionName == "CCC")
    {
        linkObjModel2DCollision -> setGetterFunction(CharacterCollideCharacter);
    }
    else if(functionName =="CCG")
    {
        linkObjModel2DCollision -> setGetterFunction(CharacterCollideGround);
    }
    else
    {
        qDebug()<<"No find stratagy.";
    }

}

void TestDemo::TestDemoCharacterMoved(const InstructionContext &insContext)
{
    if(!nowDemo()) return;

    if(!insContext.obj()) return ;


}

void TestDemo::CharacterCollideCharacter(GameObject *trigger, GameObject *getter, Model2DMove::Direction direction)
{
    // 已经发生了碰撞
    TestDemo *demo =static_cast<TestDemo*>(nowDemo());

    if(!demo) return;

    //RigidCollision()
    if(getter->getComponent<Model2DCollision>()->collisionStratagy() == Model2DCollision::CollisionStratagy::Rigid)
    //刚体碰撞
    {
        RigidCollision(trigger,getter,direction);
    }
    qDebug()<<"TestDemo::CharacterCollideCharacter | then battle. " ;
    //碰撞-->战斗

    trigger->getComponent<ModelBattleBase>()->setBattleObject(getter);
    demo->addUpdateInfo<DemoBattleSystem>(trigger);
    getter->getComponent<ModelBattleBase>()->setBattleObject(trigger);
    demo->addUpdateInfo<DemoBattleSystem>(getter);

}

void TestDemo::CharacterCollideGround(GameObject *trigger, GameObject *getter, Model2DMove::Direction direction)
{

    // 已经发生了碰撞
    TestDemo *demo =static_cast<TestDemo*>(nowDemo());
    if(!demo) return;
    if(getter->getComponent<Model2DCollision>()->collisionStratagy() == Model2DCollision::CollisionStratagy::Rigid)
        //刚体碰撞
    {
        RigidCollision(trigger,getter,direction);
    }

    //站在地上什么都不会发生

}

void TestDemo::RigidCollision(GameObject *trigger, GameObject *getter, Model2DMove::Direction direction)
{
#ifdef QDEBUGCHECK
    qDebug()<<"TestDemo::RigidCollision | check direction:"<<direction;
#endif
    //向上  看trigger顶 与 getter底
    if(direction & Model2DMove::Direction::Up)
    {
        //qDebug()<<"TestDemo::RigidCollision | Up";
        //   位置判断
        float value1 = trigger->getComponent<Model2DItem>()->y();
        float speed  = trigger->getComponent<Model2DMove>()->ySpeed();
        float value2 = getter->getComponent<Model2DItem>()->y()+getter->getComponent<Model2DItem>()->pixHeight();
        //
        if(value1>=value2 && value1+speed < value2 )
        {
            //1. 位置设置
            //trigger->getComponent<Model2DItem>()->setY(getter->getComponent<Model2DItem>()->y()+getter->getComponent<Model2DItem>()->pixHeight());
            //2. 速度设置
            trigger->getComponent<Model2DMove>()->setYSpeed(0.0);

        }
    }
    else
        //向下  看trigger底 与 getter顶
        if(direction & Model2DMove::Direction::Down)
        {
            //qDebug()<<"TestDemo::RigidCollision | Down";
            //   位置判断
            float value1 = trigger->getComponent<Model2DItem>()->y()+trigger->getComponent<Model2DItem>()->pixHeight();
            float speed  = trigger->getComponent<Model2DMove>()->ySpeed();
            float value2 = getter->getComponent<Model2DItem>()->y();
            //
            if(value1<=value2 && value1+speed > value2)
            {
                //1. 位置设置
                //trigger->getComponent<Model2DItem>()->setY(getter->getComponent<Model2DItem>()->y()-trigger->getComponent<Model2DItem>()->pixHeight());
                //2. 速度设置
                trigger->getComponent<Model2DMove>()->setYSpeed(0.0);

            }
        }

    //向左  看trigger左 与 getter右
    if(direction & Model2DMove::Direction::Left)
    {
        //qDebug()<<"TestDemo::RigidCollision | Left";
        //   位置判断
        float value1 = trigger->getComponent<Model2DItem>()->x();
        float speed  = trigger->getComponent<Model2DMove>()->xSpeed();
        float value2 = getter->getComponent<Model2DItem>()->x()+getter->getComponent<Model2DItem>()->pixWidth();
        //
        if(value1>=value2 && value1+speed < value2)
        {
            //1. 位置设置
            //trigger->getComponent<Model2DItem>()->setX(getter->getComponent<Model2DItem>()->x()+getter->getComponent<Model2DItem>()->pixWidth());
            //2. 速度设置
            trigger->getComponent<Model2DMove>()->setXSpeed(0.0);

        }
    }
    else
        //向右  看trigger左 与 getter右
        if(direction & Model2DMove::Direction::Right)
        {
            //qDebug()<<"TestDemo::RigidCollision | Right";
            //   位置判断
            float value1 = trigger->getComponent<Model2DItem>()->x()+trigger->getComponent<Model2DItem>()->pixWidth();
            float speed  = trigger->getComponent<Model2DMove>()->xSpeed();
            float value2 = getter->getComponent<Model2DItem>()->x();
            //
            if(value1<=value2 && value1 + speed > value2)
            {
                //1. 位置设置
                //trigger->getComponent<Model2DItem>()->setX(getter->getComponent<Model2DItem>()->x()-trigger->getComponent<Model2DItem>()->pixWidth());
                //2. 速度设置
                trigger->getComponent<Model2DMove>()->setXSpeed(0.0);
            }
        }
}
