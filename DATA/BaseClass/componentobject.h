#ifndef COMPONENTOBJECT_H
#define COMPONENTOBJECT_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QMetaProperty>
#include <QString>
#include <QStringList>


#include "../constvalue.h"

//=========================加入反射
#include "../../TOOL/Template/Registor.hpp"
//===============================

class GameObject;
class ComponentObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString className READ className WRITE setClassName NOTIFY classNameChanged FINAL)
public:
    explicit ComponentObject(QObject *parent = nullptr);
    explicit ComponentObject(ComponentObject& other);
    virtual ~ComponentObject();
    virtual QJsonObject getMetaData()const;
    virtual void setLinkObj(GameObject*obj);
    virtual void initComponent(const QJsonObject& obj);
    GameObject* getLinkObj();

    bool initFlag() const;
    void setInitFlag(bool newInitFlag);

    QString typeId() const;

    QString className() const;
    void setClassName(const QString &newClassName);

    bool delayInitFlag() const;
    void setDelayInitFlag(bool newDelayInitFlag);

    QVector<QString> getDelayPropertyList();
    QString getDelayPropertyValue(const QString & key)const;

protected:
    bool m_initFlag;
    bool m_linkFlag;
    bool m_delayInitFlag;
    QMap<QString,QString> m_delayPropertyMap;


    GameObject* m_linkObj=nullptr;
    QString m_typeId;
    QString m_className;
signals:

    void classNameChanged();
private:

};


#define REGISTER_TYPEID \
m_typeId=QString(typeid(decltype(*this)).name());

#endif // COMPONENTOBJECT_H
