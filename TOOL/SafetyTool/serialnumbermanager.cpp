

#ifdef LOAD_OPENSSL_BY_PROJECT

 #include "serialnumbermanager.h"

SerialNumberManager * SerialNumberManager::m_instance =nullptr;
QSet<QString> SerialNumberManager::m_serialNumberSet{};
RSA* SerialNumberManager::m_key=nullptr;
QString SerialNumberManager::m_keyContext={
"-----BEGIN PRIVATE KEY-----\n\
MIIEvAIBADANBgkqhkiG9w0BAQEFAASCBKYwggSiAgEAAoIBAQCdeznpgCC/FYoh\
EmQ+wXkMbLxGEzDt3gItaeX0o20WULNXYxHhnAPiQJaiVo4qxVXfd1jfnL02iFiW\
e/9mZf+HfrUvUAf9JMGhq9He1f5bOgUFVGJ8rALWMeqIbo0s0+Am4p8wME8MnOsA\
G14j1dwnkw6QhH+h8vOl+FNPXNXl8fAMYJFGDAJd1Q8xatOQFLl5r1dhOQn8RClI\
Pka8K6OFCE9vIoErTR6z3GZ/ityjcCpSMGu/PQnusvbqXHQxCWdwT6E1IY66NOnF\
97fEQY4qKroLQV8+LRJdIUIh6tRVQtGHEVIssFFil/VjaZXhA/oAi5rv7enaR0lC\
P4Mb+sKfAgMBAAECggEAHNDnj+p6E30FgXe0ECem1rcu3EO2uE/fZh/yjAk7dNHf\
fyYJp5a8vzHCXoIoEXt6cyGLiZ9MoCXiz+ZwnXQchdaRoM6sJ44KQGMITBYsLNU5\
Bfii7N0sx7TqjXxtKL68TWE6b77nOA+ekK5xU21Wk4c9KwSTtjaWjtAZrnP2T9Tj\
vA4wYFbeqPjjj6VIBjHN6FpzMwvFA6c8WBfHSZnlSuFrT5uW6rmRVMJY9H8pDze7\
/piKZk69g2aJ0LYdi+i9EiEkiBbCsM/PdyBbFAJCPPQo8PfU/Zi0A28WPgaQv/dF\
ewjw9elqASTSPcqC7bOQh+iO2ew2GA3rKrFpuNVOwQKBgQDY+6b0skiSdKpm3D9T\
LwSzqmP4B8Fq0S8syeD6mx8KdUxa6bKmTf1CoGAkHTwAuNBZRo6KXTrdoVngQ5mW\
vOS9hNeYsCTwFTLyu/GE6CW2RNNO/lITKEqJRJ8+cQcN1C6diQsyU8aFfl5MRV5z\
507s0RnopYd1H5AhZ52tbK6L8wKBgQC5zIrk2UmFbroEM4IYIPsZkwBS75r41yNU\
+OWX7RtPAvQCgNltxZAoR6prOajpnRKu7MuHk65otnZZ9HfCQaD4lqEMl4gWiqdy\
Bhme3uXqA/IE/C6Hkm7h++vc0I1i+HQ8e2kXgOkdeFEn85alIVxIivWQw8KBnhwE\
qQIPiAn1pQKBgC+d2h+s2Dw7mgGEp+jrUo7S/6k4mnuEeGPN0a9tRzyWTTFOQ8Q3\
LTLn2vFR8Q7/f8l3sGQw3XAxrnWGoDfyMAhfFKkPTqvZGxsln3TZNR1wsSaOrRhD\
KUhCZOfhCflA7RHpNynONKyq9KqsNnQc+LcDlDn3yWgsiwappHKgfRV9AoGATsbd\
4RgL5ypCboOUVjytmnNMgN2cnINDNMTvO9JJcN+0q9cL2VIZxCpWpG3nI134zPgT\
d6FzImyyk4Nmv5Np99yN3jPlfIE/a8YQWN7zJpyToe92nv7ESsawg4hdWigzyG0e\
6ts6e8dGyaSrK8qQQSXB5qZJswFhqcwq1oD8kA0CgYAX14OBWsx0yJdOjqZs1vnr\
AwkAnAWaW27p2OhL7xQnnbAg1H7z73TofYJghnxxlAxO8L0w9UCZPOuvUDO3DaRn\
IjXatWdoyRjQrWXyirWN4OtaJ7lpUWb7U+kVYxbWvDlRZBD+GPW7t+sa+NNSNicU\
7Dfdef+kEenDEMPXSwPgJQ==\n\
-----END PRIVATE KEY-----\
"
};
SerialNumberManager *SerialNumberManager::getInstance(QObject *parent)
{
    if(!m_instance)
    {
        m_instance =new SerialNumberManager(parent);
        initManager();
    }
    return m_instance;
}

SerialNumberManager::SerialNumberManager(QObject *parent)
    : QObject{parent}
{

}

void SerialNumberManager::initManager()
{

    //qDebug()<<"SerialNumberManager::initManager | in.";
    // loadKey
    //qDebug()<<"SerialNumberManager::initManager | check m_keyContext"<<m_keyContext;
    //qDebug()<<"SerialNumberManager::initManager | check 1 Key :."<<(m_key==nullptr);
    OpenSSLTool tool;

    m_key=tool.readRSAKeyFromContext(m_keyContext);
    //m_key = tool.readRSAKeyFromFile("D:/QTF/LicenseTest/CertainTest/AuraTestKey.pem");

    //qDebug()<<"SerialNumberManager::initManager | check 2 Key :."<<(m_key==nullptr);
    //read
}

void SerialNumberManager::loadSerialNumberFile(const QString &filePath)
{
    if(!m_key)
    {
        qDebug()<<"未加载密钥";
        return;
    }
    auto fileNameList = filePath.split(".");
    if(fileNameList.count()<2)
    {
        qDebug()<<"格式错误";
        return ;
    }
    QString lastType =fileNameList[fileNameList.count()-1];
    if(lastType != "snf")
    {
        qDebug()<<"格式错误";
        return ;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly )) {
        qDebug() << "无法打开文件";
        return;
    }
    OpenSSLTool tool;
    QByteArray data =file.readAll();
    QByteArray decryptData = tool.getDecryptStrByRSA(m_key,data);
    decryptData = decryptData.replace('\0', ""); // 移除所有空字符
    QString strList = QString::fromLocal8Bit(decryptData);

    qDebug()<<"================check================";
    m_serialNumberSet.clear();
    for(auto it : strList.split("|"))
    {
        m_serialNumberSet.insert(it);
    }
    qDebug()<<m_serialNumberSet;
}

bool SerialNumberManager::quarySerialNumber(QString serialNumber)
{
    //这里验证时间序列

    //这里验证是否在集合内
    return m_serialNumberSet.contains(serialNumber);
}


#endif
