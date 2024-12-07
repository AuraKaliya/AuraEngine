#ifndef SCRIPTOBJECTLUA_H
#define SCRIPTOBJECTLUA_H

#include <QString>
#include <lua.hpp>
#include "gameobject.h"

class ScriptObjectLua
{
public:
    ScriptObjectLua(QString fileName,GameObject*obj);

    GameObject *obj() const;
    void setObj(GameObject *newObj);

    QString fileName() const;
    void setFileName(const QString &newFileName);

    lua_State *lua() const;
    void setLua(lua_State *newLua);

private:
    QString m_fileName;
    lua_State* m_lua=nullptr;
    GameObject* m_obj;
};

#endif // SCRIPTOBJECTLUA_H
