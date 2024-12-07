#pragma once
#include <QString>
#include <AuraGlobal.h>

namespace AuraUI {

enum LogType{
    Action,Error
};

enum  UIDirection{
    Horizon=1,Vertical=2
};

enum class AllowedValueType
{
    IntOnly,
    Number,
    Normal
};

enum class WidgetDragStratagy
{
    Fixed,
    Draged,
    Selected,
};

class AuraLibrary_DECL AuraUIPath
{
public:
void init(){
    StyleDir =  AURAUI_STYLE_DIR;
    ShaderDir = AURAUI_SHADER_DIR;
    ModuleDir = AURAUI_MODULE_DIR;
    SAThemeDir = AURAUI_SATHEME_DIR;
    RCCDir = AURAUI_RCC_DIR;
    TextureDir =AURAUI_TEXTURE_DIR;
    ScriptDir = AURA_LIBRARY_SCRIPT_DIR;
}

mutable QString StyleDir;
mutable QString ShaderDir;
mutable QString ModuleDir;
mutable QString SAThemeDir;
mutable QString RCCDir;
mutable QString TextureDir;
mutable QString ScriptDir;
};

}// namespace AuraUI


