#ifndef SCRIPTSYSTEM_H
#define SCRIPTSYSTEM_H

#include <QObject>

#include "../../DATA/baseClass/systemobject.h"

#include <lua.hpp>
#include "../../DATA/BaseClass/scriptobjectlua.h"
#include "../../DATA/BaseClass/instructioncontext.h"
#include "../../DATA/constvalue.h"

//========================Engine的系统层结构================//
#include "sourcesystem.h"
#include "instructionsystem.h"
//========================Engine的系统层结构================//


class ScriptSystem : public SystemObject
{
    Q_OBJECT

public:
    static ScriptSystem* getInstance(QObject* parent=nullptr);
    static void addScript(ScriptObjectLua* script);
    static void initDemoScript(QVector<ScriptObjectLua*> scriptsList);
    static void registerFunc(lua_State* lua);

    static int readKeyState(lua_State* state);
    static int setItemState(lua_State* state);
    static int setObjectState(lua_State* state);
    static int getObjectState(lua_State*state);
    static int soluteInstruction(lua_State*state);

    static void updateScript();
    static void setNowDemo(GameDemo *newNowDemo);

    static ConstValue::DataType getPropertyType(const QMetaProperty& p);
private:
    static ScriptSystem* m_instance;
    static  QVector<ScriptObjectLua*> m_scriptsList;


public:
    bool systemStart() override;
    bool systemInit()  override;
    bool systemClose() override;


private:
    explicit ScriptSystem(QObject *parent = nullptr);
    static GameDemo * m_nowDemo;

signals:

};

#endif // SCRIPTSYSTEM_H
