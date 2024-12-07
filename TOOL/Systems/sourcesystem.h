#ifndef SOURCESYSTEM_H
#define SOURCESYSTEM_H

#include <QObject>
#include <QMetaObject>
#include <QMetaProperty>
#include <QFile>
#include <QTextStream>
#include "../../DATA/baseClass/systemobject.h"

#include "../../DATA/BaseClass/gameobject.h"
#include "../../DATA/BaseClass/gamedemo.h"
#include "../../DATA/BaseClass/componentobject.h"
#include "../../DATA/BaseClass/engineinfomation.h"

//========================
#include "../Template/Factory.hpp"
//=========================
class SourceSystem : public SystemObject
{
    Q_OBJECT
public:
    static SourceSystem *getInstance(QObject *parent = nullptr);

    bool systemStart() override;
    bool systemInit()  override;
    bool systemClose() override;

    static int loadProjectFile(QString projectFilePath);
    static int loadDemoConfigFile(QString configFilePath);

    static bool registDemo(GameDemo* demo);
    static bool registerGameObject(GameObject* obj);

    static void initGameObjectList(GameDemo* demo);

    static void setNowDemo(GameDemo* demo);
    static bool addGameObject(GameObject* obj);
    static void addGameObjectFromSample(QString className);

    static GameObject* getGameObjectById(unsigned int id);
    static QMetaProperty getComponentMetaProperty(QString componentName, QString propertyName);
    static QVector<GameObject*> gameObjectList();
    static unsigned int globalId();

    static QSet<QString> gameObjectClassSet();

    static QSet<QString> componentClassSet();

    static GameObject* getGameObjectSample(QString className);
    static GameObject* createGameObjectSample(QString className);

    static void cleanNowDemo();

protected:
    static void updateSourceId(unsigned int registerId);
    static void registerGameObjectId(GameObject* obj);

    static bool registGameObjectClass(QString objClassName);
    static bool registComponentClass(QString componentClassName);
    static bool registDemoClass(QString demoClassName);
private:
    static SourceSystem* m_instance;
    static GameDemo * m_nowDemo;
    static QMap<unsigned int,GameObject* > m_gameObjectDictionary;
    static QMap<QString,GameObject*> m_gameObjectSampleDictionary;
    static QSet<QString> m_gameObjectClassSet;
    static QSet<QString> m_componentClassSet;

    static unsigned int m_globalId;

    //static QMap<unsigned int,QMap<>>
private:
    explicit SourceSystem(QObject *parent = nullptr);


signals:
    void sourceNeedUpdateView();
    void sourceGameObjectUpdated();
    void sourceReflexUpdated();
    void sourceLoadDemo(GameDemo* );
    void sourceNowDemoChanged();

};

#endif // SOURCESYSTEM_H
