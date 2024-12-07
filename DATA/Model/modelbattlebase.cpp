#include "modelbattlebase.h"

ModelBattleBase::ModelBattleBase(QObject *parent)
    : ComponentObject{parent},m_ATK(15),m_DEF(10),m_HP(100),m_survivalState(true),m_battleObject(nullptr)
{
    REGISTER_TYPEID
    setObjectName("ModelBattleBase");
}

QJsonObject ModelBattleBase::getMetaData() const
{
    QJsonObject obj;

    return obj;
}

void ModelBattleBase::initComponent(const QJsonObject &obj)
{
    ComponentObject::initComponent(obj);

    //get Value
    auto atk =obj.value("ATK").toInt();
    auto def =obj.value("DEF").toInt();
    auto hp =obj.value("HP").toInt();
    auto battleObject =obj.value("BattleObject").toInt();

    //setValue
    setATK(atk);
    setDEF(def);
    setHP(hp);

    //other
    if(m_linkFlag)
    {
        setDelayInitFlag(true);
        m_delayPropertyMap["BattleObject"]=QString::number(battleObject);
    }
    else
    {
#ifdef QDEBUGCHECK
        qDebug()<<"ModelBattleBase::initComponent | warning: "<<this<<" no have link obj.";
#endif
    }
}

 int ModelBattleBase::getATK() const
{
    return m_ATK;
}

void ModelBattleBase::setATK( int newATK)
{
    if (m_ATK == newATK)
        return;
    m_ATK = newATK;
    emit ATKChanged();
}

 int ModelBattleBase::getDEF() const
{
    return m_DEF;
}

void ModelBattleBase::setDEF( int newDEF)
{
    if (m_DEF == newDEF)
        return;
    m_DEF = newDEF;
    emit DEFChanged();
}

 int ModelBattleBase::getHP() const
{
    return m_HP;
}

void ModelBattleBase::setHP( int newHP)
{
    if (m_HP == newHP)
        return;
    m_HP = newHP;
    emit HPChanged();
}

bool ModelBattleBase::getSurvivalState() const
{
    return m_survivalState;
}

void ModelBattleBase::setSurvivalState(bool newSurvivalState)
{
    if (m_survivalState == newSurvivalState)
        return;
    m_survivalState = newSurvivalState;
    emit survivalStateChanged();
}

GameObject *ModelBattleBase::battleObject() const
{
    return m_battleObject;
}

void ModelBattleBase::setBattleObject(GameObject *newBattleObject)
{
    m_battleObject = newBattleObject;
}
