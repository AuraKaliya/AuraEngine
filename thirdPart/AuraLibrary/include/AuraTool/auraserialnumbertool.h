#pragma once

#include <QSet>
#include "auraopenssltool.h"

#include "../AuraGlobal.h"
namespace AuraTool {

struct AURAUI_LIB_DECL SerialNumberInformation
{
    QString mac;
    QString extraInfo;
    bool timeFlag;
    qint64 timestamp;
    qint64 validDuration;
};


class AURAUI_LIB_DECL AuraSerialNumberTool
{
public:
    static AuraSerialNumberTool* getInstance();

    void initKey();
    void initKey(const QString & filePath);
    bool initFlag() const;

    //===============Verify=======================================
    bool quarySerialNumber(const QString & serialNumber);
    //===============Verify=======================================
    //===============Create========================================
    QString createSerialNumber(const SerialNumberInformation & info);
    //===============Create========================================

    //===============SerialNumberSet======================
    void loadSerialNumberSet(const QString & filePath);
    void saveSerialNumberSet(const QString & filePath);
    QSet<QString> serialNumberSet() const;
    void addSerialNumberToSet(const QString & value);
    //===============SerialNumberSet======================
protected:
    void updateInitState();

private:
    bool m_initFlag;
    RSA* m_privateKey;
    QString m_keyContext;
    QSet<QString> m_serialNumberSet;
private:
    AuraSerialNumberTool();
    AuraSerialNumberTool(const AuraSerialNumberTool&) = delete;
    AuraSerialNumberTool& operator=(const AuraSerialNumberTool&) = delete;
    static AuraSerialNumberTool* m_instance;
};

} // namespace AuraTool

