#include "scriptsystem.h"

#include "../../DATA/Model/model2dhpbar.h"


ScriptSystem* ScriptSystem::m_instance=nullptr;
QVector<ScriptObjectLua*> ScriptSystem::m_scriptsList{};
GameDemo * ScriptSystem::m_nowDemo=nullptr;

ScriptSystem *ScriptSystem::getInstance(QObject *parent)
{
    if(m_instance==nullptr)
    {
        m_instance=new ScriptSystem(parent);
    }
    return m_instance;
}

void ScriptSystem::addScript(ScriptObjectLua *script)
{
    lua_State* lua=luaL_newstate();
    script->setLua(lua);
    luaL_openlibs(lua);

    //==================test===========================
    qDebug()<<"ScriptSystem::addScript| filename c: "<<script->fileName().toStdString().c_str();
    //==================test===========================

    int res=luaL_dofile(lua,script->fileName().toStdString().c_str());
    if(res!=0)
    {
        qDebug()<<"ScriptSystem::addScript | error in lua:"<<lua_tostring(lua, -1);
    }

    //==================test===========================
    lua_getglobal(lua,"testname");
    qDebug()<<"ScriptSystem::addScript | testName: "<<lua_tostring(lua,-1);
    //==================test===========================

    //注册函数
    registerFunc(lua);

    //初始化脚本参数
    lua_getglobal(lua,"init");
    lua_pushnumber(lua,script->obj()->id());
    lua_pcall(lua, 1, 0, 0);

    m_scriptsList.append(script);
}

void ScriptSystem::initDemoScript(QVector<ScriptObjectLua *> scriptsList)
{
    for(auto it:scriptsList)
    {
        lua_State* lua=luaL_newstate();
        it->setLua(lua);
        luaL_openlibs(lua);

        //==================test===========================
        qDebug()<<"ScriptSystem::initDemoScript|===========================================";
        qDebug()<<"ScriptSystem::initDemoScript| filename c: "<<it->fileName().toStdString().c_str();
        //==================test===========================

        int res=luaL_dofile(lua,it->fileName().toStdString().c_str());
        if(res!=0)
        {
            qDebug()<<"ScriptSystem::initDemoScript | error in lua:"<<lua_tostring(lua, -1);
        }

        //==================test===========================
        lua_getglobal(lua,"testname");
        qDebug()<<"ScriptSystem::initDemoScript | testName: "<<lua_tostring(lua,-1);
        qDebug()<<"ScriptSystem::initDemoScript|===========================================";
        //==================test===========================

        //注册函数
        registerFunc(lua);

        //初始化脚本参数
        lua_getglobal(lua,"init");
        lua_pushnumber(lua,it->obj()->id());
        lua_pcall(lua, 1, 0, 0);
        m_scriptsList.append(it);
    }
}

void ScriptSystem::registerFunc(lua_State *lua)
{
    //注册Key状态获取函数   --这个可以每个都注册一个
    lua_register(lua,"readKeyState",readKeyState);

    //注册object管理函数
    lua_register(lua,"setObjectState",setObjectState);
    lua_register(lua,"getObjectState",getObjectState);

    //注册指令调用函数
    lua_register(lua,"soluteInstruction",soluteInstruction);

}

int ScriptSystem::readKeyState(lua_State *state)
{
    //Key状态获取函数
    GlobalKeyValue keyValue;
    const char* key=lua_tostring(state,-1);
    bool flag=keyValue.getKeyPressedState(key);
    lua_pushboolean(state,flag);
    return 1;
}

int ScriptSystem::setItemState(lua_State *state)
{
    return 0;
}

int ScriptSystem::setObjectState(lua_State *state)
{
#ifdef QDEBUGCHECK
    qDebug()<<"ScriptSystem::setObjectState | In.";
#endif
    // 参数  id  componentClass propertyName newValue
    unsigned int objId=lua_tonumber(state,-4);
    const char* componentClass=lua_tostring(state,-3);
    const char* propertyName=lua_tostring(state,-2);

    auto  obj=m_nowDemo->getGameObject<GameObject>(objId);
    if(!obj)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"ScriptSystem::setObjectState | Demo:"<<m_nowDemo->objectName()<<" no have this obj :"<<objId;
#endif
        return 0;
    }
    auto  componentObj=obj->getComponent(Factory<ComponentObject>::GetInstance()->getClassTypeIdName(componentClass).c_str());
    if(!componentObj)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"ScriptSystem::setObjectState | Demo:"<<m_nowDemo->objectName()<<"obj :"<<objId<<" no have this component:"<<componentClass;
#endif
        return 0;
    }
    QMetaProperty property=SourceSystem::getComponentMetaProperty(componentClass,propertyName);

    switch (getPropertyType(property)) {
    case ConstValue::DataType::Double:
        property.write(componentObj,QVariant(lua_tonumber(state,-1)));
        break;
    case ConstValue::DataType::Float:
        property.write(componentObj,QVariant(lua_tonumber(state,-1)));
        break;
    case ConstValue::DataType::Int:
#ifdef QDEBUGCHECK
        qDebug()<<"ScriptSystem::getObjectState | check  int!"<<property.read(componentObj).toInt();
#endif
        property.write(componentObj,QVariant(lua_tonumber(state,-1)));
        break;
    case ConstValue::DataType::UInt:
        property.write(componentObj,QVariant(lua_tonumber(state,-1)));
        break;
    case ConstValue::DataType::String:
        property.write(componentObj,QVariant(lua_tostring(state,-1)));
        break;
    default:
#ifdef QDEBUGCHECK
        qDebug()<<"ScriptSystem::setObjectState | Obj:"<<obj->name()<<"no have this property:"<<property.name();
#endif
        break;
    }
#ifdef QDEBUGCHECK
    qDebug()<<"ScriptSystem::setObjectState | out.";
#endif
    return 0;
}

int ScriptSystem::getObjectState(lua_State *state)
{
#ifdef QDEBUGCHECK
    qDebug()<<"ScriptSystem::getObjectState | In.";
#endif
    if(!m_nowDemo)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"ScriptSystem::getObjectState | no have demo .";
#endif
        return -1;
    }

    // 参数  id  componentClass propertyName
    unsigned int objId=lua_tonumber(state,-3);
    const char* componentClass=lua_tostring(state,-2);
    const char* propertyName=lua_tostring(state,-1);
#ifdef QDEBUGCHECK
    qDebug()<<"ScriptSystem::getObjectState | check componentClass:"<<componentClass <<"  propertyName:"<<propertyName;
#endif
    auto  obj=m_nowDemo->getGameObject<GameObject>(objId);
    if(!obj)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"ScriptSystem::getObjectState | Demo:"<<m_nowDemo->objectName()<<" no have this obj :"<<objId;
#endif
        return 0;
    }
    auto  componentObj=obj->getComponent(Factory<ComponentObject>::GetInstance()->getClassTypeIdName(componentClass).c_str());
    if(!componentObj)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"ScriptSystem::getObjectState | Demo:"<<m_nowDemo->objectName()<<"obj :"<<objId<<" no have this component:"<<componentClass;
#endif
        return 0;
    }
#ifdef QDEBUGCHECK
    qDebug()<<"ScriptSystem::getObjectState | check Component0:"<< componentObj;
    qDebug()<<"ScriptSystem::getObjectState | check Component1:"<< obj->getComponent<Model2DHPBar>();
    qDebug()<<"ScriptSystem::getObjectState | check Component2:"<< typeid(obj->getComponent<Model2DHPBar>()).name();
    qDebug()<<"ScriptSystem::getObjectState | check Component3:"<< Factory<ComponentObject>::GetInstance()->getClassTypeIdName(componentClass).c_str();
    qDebug()<<"ScriptSystem::getObjectState | check Component4:"<< obj->getComponent(typeid(obj->getComponent<Model2DHPBar>()).name());
    qDebug()<<"ScriptSystem::getObjectState | check Component5:"<< obj->getComponent(Factory<ComponentObject>::GetInstance()->getClassTypeIdName(componentClass).c_str());
#endif
    QMetaProperty property=SourceSystem::getComponentMetaProperty(componentClass,propertyName);

#ifdef QDEBUGCHECK
    qDebug()<<"ScriptSystem::getObjectState | check Demo:"<<m_nowDemo->objectName()<<"obj :"<<objId <<"property"<<property.name();
#endif

    switch (getPropertyType(property)) {
    case ConstValue::DataType::Double:
        lua_pushinteger(state,property.read(componentObj).toDouble());
        break;
    case ConstValue::DataType::Float:
        lua_pushinteger(state,property.read(componentObj).toFloat());
        break;
    case ConstValue::DataType::Int:
#ifdef QDEBUGCHECK
        qDebug()<<"ScriptSystem::getObjectState | check  int!"<<property.read(componentObj).toInt();
#endif
        lua_pushinteger(state,property.read(componentObj).toInt());
        break;
    case ConstValue::DataType::UInt:
        lua_pushinteger(state,property.read(componentObj).toUInt());
        break;
    case ConstValue::DataType::String:
        lua_pushstring(state,property.read(componentObj).toString().toStdString().c_str());
        break;
    default:
#ifdef QDEBUGCHECK
        qDebug()<<"ScriptSystem::getObjectState | Obj:"<<obj->name()<<"no have this property:"<<property.name();
#endif
        break;
    }
#ifdef QDEBUGCHECK
    qDebug()<<"ScriptSystem::getObjectState | out.";
#endif
    return 1;
}

int ScriptSystem::soluteInstruction(lua_State *state)
{
    /*
        1. obj id  --> 代表触发/发出指令的单位
        2. insName  --> 指令名
        3. insType  --> 指令类型   Function / Object
        4. insParagram -->指令参数  按顺序集成QVariant
        5. ...
        -1. 具体参数个数   从4开始计算
    */

    unsigned int objId=lua_tonumber(state,1);
    const char* insName =lua_tostring(state,2);
    const char* insType =lua_tostring(state,3);
    int n=lua_tonumber(state,-1);

    QVector<QVariant> paramlist;
    for(int i=4;i<n+4;++i)
    {
        paramlist.append(QVariant(lua_tostring(state,i)));
    }

    auto  obj=m_nowDemo->getGameObject<GameObject>(objId);

    if(!obj)
    {
#ifdef QDEBUGCHECK
        qDebug()<<"ScriptSystem::soluteInstruction | Demo:"<<m_nowDemo->objectName()<<" no have this obj :"<<objId;
#endif
        return 0;
    }
    InstructionContext context(obj,insName,insType,QVariant(paramlist));
    InstructionSystem::soluteInsContext(context);
    return 0;
}

void ScriptSystem::updateScript()
{
    //轮询方式更新脚本逻辑
    for(auto it:m_scriptsList)
    {
        lua_State * lua=it->lua();
        lua_getglobal(lua,"tick");
        lua_pcall(lua,0,0,0);
    }
}

bool ScriptSystem::systemStart()
{
    return true;
}

bool ScriptSystem::systemInit()
{
    return true;
}

bool ScriptSystem::systemClose()
{
    return true;
}

ScriptSystem::ScriptSystem(QObject *parent)
    : SystemObject{parent}
{

}

void ScriptSystem::setNowDemo(GameDemo *newNowDemo)
{
    m_nowDemo = newNowDemo;
}

ConstValue::DataType ScriptSystem::getPropertyType(const QMetaProperty &p)
{
 //   if(!p.isValid()) return ConstValue::DataType::Error;

    //可以写成Dictionary的形式
    if(strcmp(p.typeName(),"QString")==0) return ConstValue::DataType::String;
    if(strcmp(p.typeName(),"int")==0) return ConstValue::DataType::Int;
    if(strcmp(p.typeName(),"uint")==0) return ConstValue::DataType::UInt;
    if(strcmp(p.typeName(),"double")==0) return ConstValue::DataType::Double;
    if(strcmp(p.typeName(),"float")==0) return ConstValue::DataType::Float;

    return ConstValue::DataType::Unknown;
}
