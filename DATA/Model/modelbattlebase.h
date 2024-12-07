#ifndef MODELBATTLEBASE_H
#define MODELBATTLEBASE_H

#include <QObject>
#include "../BaseClass/componentobject.h"
#include "../BaseClass/gameobject.h"



class ModelBattleBase : public ComponentObject
{
    Q_OBJECT
    Q_PROPERTY(int ATK READ getATK WRITE setATK NOTIFY ATKChanged)
    Q_PROPERTY(int DEF READ getDEF WRITE setDEF NOTIFY DEFChanged)
    Q_PROPERTY(int HP READ getHP WRITE setHP NOTIFY HPChanged)
    Q_PROPERTY(bool survivalState READ getSurvivalState WRITE setSurvivalState NOTIFY survivalStateChanged)
public:
    explicit ModelBattleBase(QObject *parent = nullptr);
    QJsonObject getMetaData()const override;
    void initComponent(const QJsonObject& obj)override;
    int getATK() const;
    void setATK(int newATK);

    int getDEF() const;
    void setDEF(int newDEF);

    int getHP() const;
    void setHP(int newHP);

    bool getSurvivalState() const;
    void setSurvivalState(bool newSurvivalState);

    GameObject *battleObject() const;
    void setBattleObject(GameObject *newBattleObject);

private:

    int m_ATK;

    int m_DEF;

    int m_HP;

    bool m_survivalState;

    GameObject * m_battleObject;
signals:

    void ATKChanged();
    void DEFChanged();
    void HPChanged();
    void survivalStateChanged();

};
REGISTER_CLASS(ModelBattleBase,ComponentObject)
REGISTER_COPY_CLASS(ModelBattleBase,ComponentObject)
#endif // MODELBATTLEBASE_H
