#include "scriptobjectlua.h"


ScriptObjectLua::ScriptObjectLua(QString fileName, GameObject *obj):
m_fileName(fileName),m_obj(obj)
{

}

GameObject *ScriptObjectLua::obj() const
{
    return m_obj;
}

void ScriptObjectLua::setObj(GameObject *newObj)
{
    m_obj = newObj;
}

QString ScriptObjectLua::fileName() const
{
    return m_fileName;
}

void ScriptObjectLua::setFileName(const QString &newFileName)
{
    m_fileName = newFileName;

}

lua_State *ScriptObjectLua::lua() const
{
    return m_lua;
}

void ScriptObjectLua::setLua(lua_State *newLua)
{
    m_lua = newLua;
}


