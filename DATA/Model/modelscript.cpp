#include "modelscript.h"

ModelScript::ModelScript(QString fileName, GameObject *obj, QObject *parent)
    : ComponentObject{parent},m_scriptPath(fileName),m_linkObj(obj)
{
    REGISTER_TYPEID
    setObjectName("ModelScript");
    m_script=new ScriptObjectLua(m_scriptPath,m_linkObj);
}

QJsonObject ModelScript::getMetaData() const
{
    QJsonObject obj;

    return obj;
}

void ModelScript::initComponent(const QJsonObject &obj)
{
    ComponentObject::initComponent(obj);

    //get Value
    auto scriptPath =obj.value("ScriptPath").toString();

    //set Value
    setScriptPath(ConstValue::SourceDir().path()+scriptPath);

    //other
    setInitFlag(true);
}

QString ModelScript::scriptPath() const
{
    return m_scriptPath;
}

void ModelScript::setScriptPath(const QString &newScriptPath)
{
    if (m_scriptPath == newScriptPath)
        return;
    m_scriptPath = newScriptPath;
    updateScript();
    emit scriptPathChanged();
}

ScriptObjectLua *ModelScript::script() const
{
    return m_script;
}

void ModelScript::updateScript()
{
    if(!m_script)
    {
        return;
    }
    m_script->setFileName(m_scriptPath);
}


