#ifndef SERIALNUMBERMANAGER_H

#define SERIALNUMBERMANAGER_H

#include <QObject>
#include <QMap>
#include <QSet>
#include <QString>
#include <QFile>

#include "openssltool.h"

class SerialNumberManager : public QObject
{
    Q_OBJECT
public:
    static SerialNumberManager* getInstance(QObject *parent = nullptr);
    static void loadSerialNumberFile(const QString& filePath);
    static bool quarySerialNumber(QString serialNumber);
private:
    explicit SerialNumberManager(QObject *parent = nullptr);
    static void initManager();
private:
    static SerialNumberManager * m_instance;
    static QSet<QString> m_serialNumberSet;
    static RSA* m_key;
    static QString m_keyContext;


signals:
};

#endif // SERIALNUMBERMANAGER_H

