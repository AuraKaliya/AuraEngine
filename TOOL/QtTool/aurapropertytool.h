#ifndef AURAPROPERTYTOOL_H
#define AURAPROPERTYTOOL_H

#include <QProperty>
#include <QMetaObject>
#include <QMetaProperty>

#include <QVector>


class AuraPropertyTool
{
public:
    static QVector<QMetaProperty> getProperty(QObject*obj,int start,int num=0);
public:
    AuraPropertyTool();
};

#endif // AURAPROPERTYTOOL_H
