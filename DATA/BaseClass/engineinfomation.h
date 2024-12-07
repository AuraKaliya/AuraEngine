#ifndef ENGINEINFOMATION_H
#define ENGINEINFOMATION_H

#include <QString>

/*
     * 项目文件信息
    X 1.项目创建日期
    2.项目名
    3.项目使用模板
    4.项目数据文件位置
    5.校验许可-MD5值（用于验证工程是否被篡改）
    */
class EngineInfomation
{

public:
    EngineInfomation();
    QString projectName() const;
    void setProjectName(const QString &newProjectName);

    QString demoName() const;
    void setDemoName(const QString &newDemoName);

    QString dataPath() const;
    void setDataPath(const QString &newDataPath);

private:
    QString m_projectName;
    QString m_demoName;
    QString m_dataPath;
};

#endif // ENGINEINFOMATION_H
