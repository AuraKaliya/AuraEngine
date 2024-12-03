#pragma once

#include<QMetaObject>
#include<QMetaProperty>

#include <QList>
#include <QMap>
#include "../AuraGlobal.h"

namespace AuraUI {

class AURAUI_LIB_DECL AuraPropertyTool
{
public:
    AuraPropertyTool();
    static QList<QMetaProperty> getProperty(QObject* obj, unsigned int start ,unsigned int num = 0);
    static QString getPropertyName(const QString& property);
    static void setPropertyName(const QString& property,const QString& name);

    static QVector<QString> getCustomEnumValueNameList(const QString & enumClass);
    static int getCustomEnumValue(const QString & enumValueName);

private:
    static QMap<QString,QString> m_propertyDictionary;
    static QMap<QString,QVector< QString > > m_customEnumValueNameDictionary;
    static QMap<QString,int> m_customEnumValueDictionary;
};

}// namespace AuraUI
