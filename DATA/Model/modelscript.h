#ifndef MODELSCRIPT_H
#define MODELSCRIPT_H

#include <QObject>
#include "../BaseClass/componentobject.h"
#include "../BaseClass/scriptobjectlua.h"


class ModelScript : public ComponentObject
{
    Q_OBJECT
    Q_PROPERTY(QString scriptPath READ scriptPath WRITE setScriptPath NOTIFY scriptPathChanged)
public:
    explicit ModelScript(QString fileName="",GameObject* obj=nullptr,QObject *parent = nullptr);
    QJsonObject getMetaData()const override;
    void initComponent(const QJsonObject& obj)override;

    QString scriptPath() const;
    void setScriptPath(const QString &newScriptPath);

    ScriptObjectLua *script() const;

    void updateScript();
signals:
    void scriptPathChanged();
private:
    QString m_scriptPath;
    GameObject * m_linkObj=nullptr;
    ScriptObjectLua* m_script=nullptr;
};
REGISTER_CLASS(ModelScript,ComponentObject)
REGISTER_COPY_CLASS(ModelScript,ComponentObject)
#endif // MODELSCRIPT_H
