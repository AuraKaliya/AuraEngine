#include "demobattlesystem.h"

DemoBattleSystem::DemoBattleSystem(QObject *parent)
    : DemoSystemObject{parent}
{

}

void DemoBattleSystem::update(GameObject &obj)
{
    //========================必要检查===============================//
    ModelBattleBase* meBattle=obj.getComponent<ModelBattleBase>();
    if(!meBattle)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"DemoBattleSystem::update | "<<obj.objClass()<<" no have component ModelBattleBase.";
#endif
        return;
    }

    if(!meBattle->getSurvivalState())
    {
        return;
    }

    GameObject * oppo =obj.getComponent<ModelBattleBase>()->battleObject();
    if(oppo == nullptr)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"DemoBattleSystem::update | "<<obj.objClass()<<" no have oppo.";
#endif
        return;
    }

    ModelBattleBase* opBattle=oppo->getComponent<ModelBattleBase>();

    if(!opBattle)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"DemoBattleSystem::update | "<<oppo->objClass()<<" no have component ModelBattleBase.";
#endif
        return;
    }

    Model2DHPBar* opHPBar=oppo->getComponent<Model2DHPBar>();
    if(!opHPBar)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"DemoBattleSystem::update | "<<oppo->objClass()<<" no have component Model2DHPBar.";
#endif
        return;
    }
    //========================必要检查===============================//

    //========================逻辑处理===============================//
    /*
       仅对手会受到伤害。
    */
    bool battleFlag=false;
    int meATK=meBattle->getATK();
    int opHp=opBattle->getHP();
    int opDEF=opBattle->getDEF();
    int dHP=qMax(0,meATK-opDEF);
    opHp=opHp-dHP;
    if(opHp<0)battleFlag=true;

    if(battleFlag)
    {
        opBattle->setHP(0);
        opHPBar->setNowHP(0);
        opBattle->setSurvivalState(false);
#ifdef QDEBUGCHECK
        qDebug()<<"===================";
        qDebug()<<"Winner:"<<obj.name();
        qDebug()<<"===================";
#endif
    }
    else
    {
        opBattle->setHP(opHp);
        opHPBar->setNowHP(opHp);
    }

#ifdef QDEBUGCHECK
    qDebug()<<"===================";
    qDebug()<<"DemoBattleSystem::update | now objInfo:"<<obj.id()<<" "<<obj.name();
    qDebug()<<"ATK:"<<meBattle->getATK() << " DEF:"<<meBattle->getDEF() <<" HP:"<<meBattle->getHP();
    qDebug()<<"===================";
#endif
    //========================逻辑处理===============================//
}
