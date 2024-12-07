#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QMap>

#include "componentobject.h"
#include "../constvalue.h"
/*
游戏对象类，是引擎中对可操作对象的统称

    1. 作为实体，具有唯一Id和用于系统对其控制的一些属性
    2. 拥有获取和修改组件的方法，需要通过模板实现
    3. 将诸多功能分配给组件实现

======property========
* id--全局标识符
* class 类名
* name 实例名
======static========
* registFlag  类的注册状态 标识符
* m_itemFlag  类是否存在item 标识符
*/

//=========================加入反射
#include "../../TOOL/Template/Registor.hpp"
//===============================

class ObjectItem;

class GameObject : public QObject
{
    Q_OBJECT

    /*property*/
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString objClass READ objClass WRITE setObjClass NOTIFY objClassChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    /*property*/

public:
    explicit GameObject(/*bool initByJsonFlag = false,*/QObject *parent = nullptr);
    explicit GameObject(GameObject& other);
    template<typename T>
    void addComponent(T* component)
    {
        m_componentAutoDictionary[typeid( T ).name()]=component;
    }

    template<typename T>
    T* getComponent()
    {
        return static_cast<T*>(m_componentAutoDictionary[typeid(T).name()]);
    }

    static bool itemFlag();

    /*virtual function*/
    virtual void initObject(const QJsonObject & objData);
    virtual void initObject();
    virtual QJsonObject getMetaData() const;
    virtual QVector<ObjectItem*> items();
    /*virtual function*/

    /*property*/
    int id() const;
    void setId(int newId);

    QString objClass() const;
    void setObjClass(const QString &newObjClass);

    QString name() const;
    void setName(const QString &newName);
    /*property*/

    /*   function  */
    void addComponent(QString comTypeId,ComponentObject*component);
    ComponentObject* getComponent(QString commponentClass);
    QVector<ComponentObject*> getComponetList();
    /*   function  */

    /*  other   */
    bool delayInitFlag() const;
    void setDelayInitFlag(bool newDelayInitFlag);
    /*  other   */

protected:
    /*实例相关*/
    int         m_id;
    QString     m_objClass;
    QString     m_name;
    QMap<QString,ComponentObject*> m_componentAutoDictionary;
    bool        m_initByJsonFlag;
    bool        m_delayInitFlag;

    /*实例相关*/

    /*类相关*/
    static bool m_registFlag;
    static bool m_itemFlag;
    /*类相关*/

signals:

    /*property*/
    void idChanged();
    void objClassChanged();
    void nameChanged();
    /*property*/
};

REGISTER_CLASS(GameObject,GameObject,QObject*)

#endif // GAMEOBJECT_H
