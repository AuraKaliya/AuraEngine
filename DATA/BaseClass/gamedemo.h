#ifndef GAMEDEMO_H
#define GAMEDEMO_H

#include <QObject>
#include <QMap>

#include <QGraphicsItem>
#include <QGraphicsScene>


#include "gameobject.h"
#include "objectitem.h"
#include "scriptobjectlua.h"
#include "demosystemobject.h"
#include "instructioncontext.h"
#include "instructionfunctioninfomation.h"

//=========================加入反射
#include "../../TOOL/Template/Registor.hpp"
//===============================
class GameDemo;
using DemoExitFunction = bool(*)();


class GameDemo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int sceneCount READ sceneCount WRITE setSceneCount NOTIFY sceneCountChanged)
public:
    explicit GameDemo(QObject *parent = nullptr);
    virtual ~GameDemo();
    void addGameObject(GameObject* obj)
    {
        m_gameObjectDictionary.insert(obj->id(),obj);
    }

    template<typename T>
    T* getGameObject(unsigned int id)
    {

        auto it=m_gameObjectDictionary.values(id);
        if(it.empty()) return nullptr;
        return static_cast<T*>(it[0]);
    }

    template<typename T>
    void addDemoSystem(T* sys)
    {
        m_demoSystemDictionary[typeid( T ).name()]=sys;
    }
    template<typename T>
    T* getDemoSystem()
    {
        return static_cast<T*>(m_demoSystemDictionary[typeid(T).name()]);
    }

    template<typename System>
    void addUpdateInfo(GameObject* obj)
    {
        if(!m_infoPool.contains(typeid(System).name()))
        {
            m_infoPool[typeid(System).name()]=QVector<GameObject*>{obj};
        }
        else
        {
            m_infoPool[typeid(System).name()].append(obj);
        }
    }

    static void setNowDemo(GameDemo* demo);
    static GameDemo* nowDemo();

    virtual void initDemo(const QJsonObject& obj);
    virtual QJsonObject getDemoSource()const;
    virtual void updateDemo();
    virtual void updateRender();
    virtual void updateItem(GameObject* newGameObject);

    void initDemoClassInfo(QVector<QString> objClassList,QVector<QString> componentClassList);
    void addObjClass(QString objClass);
    void addComponentClass(QString componentClass);
    void addInsFunction(QString insName,InsFunction insFunc);
    void addInsFunction(QString insName,InsFunction insFunc,const QVector<QString>&argTip);
    void linkObjectToSystem(GameObject* obj,QString systemClass,QString otherInfo);
    /*可优化*/
    //这里还需要商榷，view在系统中可以有多个，这样仅将其绑定在主view上
    //或许添加新view时可以在别处进行映射
    virtual void linkView(QVector<QGraphicsScene*> sceneList);
    virtual void updateView(QVector<QGraphicsScene*> sceneList);
    /*可优化*/

    bool initFlag() const;
    bool quitFlag() const;
    bool exitFunctionFlag() const;


    int sceneCount() const;
    void setSceneCount(int newSceneCount);

    QVector<ScriptObjectLua *> scriptsList() const;
    void addScript(ScriptObjectLua * script);

    QVector<QString> objectClassList() const;

    QVector<QString> componentClassList() const;

    QVector<QPair<QString,InsFunction>> insFunctionList() const;

    QVector<GameObject*> objectList();

    QMultiMap<unsigned int, GameObject *> gameObjectDictionary() const;
    void updateGameObjectDictionary(unsigned int oldId,GameObject* obj);
    void resetGameObjectDictionary();
    QVector<InstructionFunctionInfomation> insFunctionInfoList() const;



    void setExitFunction(DemoExitFunction &newExitFunction);

protected:
    QMultiMap<unsigned int,GameObject*> m_gameObjectDictionary;
    QMap<QString,DemoSystemObject*> m_demoSystemDictionary;
    QMap<QString,QVector<GameObject*> > m_infoPool;
    QMap<QString,QVector<GameObject*> > m_preInfoPool;
    QVector<ObjectItem* > m_itemList;
    QVector<ObjectItem* > m_newItemList;
    QVector<QRectF> m_sceneRectList;
    QVector<ScriptObjectLua*> m_scriptsList;

    QVector<QPair<QString,InsFunction>  > m_insFunctionList;
    QVector<InstructionFunctionInfomation> m_insFunctionInfoList;

    QVector<QString> m_objectClassList;
    QVector<QString> m_componentClassList;

    int m_sceneCount;
    bool m_initFlag;
    bool m_quitFlag;

    bool m_exitFunctionFlag;
    DemoExitFunction m_exitFunction;

private:
    static GameDemo* m_nowDemo;
signals:
    void sceneCountChanged();
private:

};

#endif // GAMEDEMO_H
