#pragma once

#include <QtCore/qglobal.h>
#include <QString>

#if defined(AuraComponentUI_LIBRARY)
#define AURAUI_LIB_DECL Q_DECL_EXPORT
#elif defined (AuraComponentUI_USE_LIBRARY)
#define AURAUI_LIB_DECL Q_DECL_IMPORT
#else
#define AURAUI_LIB_DECL
#endif

#if defined(AuraComponentUI_USE_REFLEX)
//使用了反射机制
#include "TOOL/Template/ReflexTool/Registor.hpp"
#include "TOOL/Template/ReflexTool/Factory.hpp"
#endif

//=================================================================================
//遗留问题
#define AURAUI_EXPORT AURAUI_LIB_DECL
//=================================================================================

#ifndef AURA_LIBRARY_RESOURCE_DIR
#define AURA_LIBRARY_RESOURCE_DIR "./resource"
#endif

#define AURA_LIBRARY_STYLE_DIR  QString(QString(AURA_LIBRARY_RESOURCE_DIR)+"/style")
#define AURA_LIBRARY_SHADER_DIR QString(QString(AURA_LIBRARY_RESOURCE_DIR)+"/shader")
#define AURA_LIBRARY_MODULE_DIR QString(QString(AURA_LIBRARY_RESOURCE_DIR)+"/module")
#define AURA_LIBRARY_SATHEME_DIR QString(QString(AURA_LIBRARY_RESOURCE_DIR)+"/style/SARibbon")
#define AURA_LIBRARY_RCC_DIR QString(QString(AURA_LIBRARY_RESOURCE_DIR)+"/rcc")
#define AURA_LIBRARY_TEXTURE_DIR QString(QString(AURA_LIBRARY_RESOURCE_DIR)+"/texture")

//=================================================================================
//遗留问题
#define AURAUI_STYLE_DIR  QString(QString(AURA_LIBRARY_RESOURCE_DIR)+"/style")
#define AURAUI_SHADER_DIR QString(QString(AURA_LIBRARY_RESOURCE_DIR)+"/shader")
#define AURAUI_MODULE_DIR QString(QString(AURA_LIBRARY_RESOURCE_DIR)+"/module")
#define AURAUI_TEXTURE_DIR QString(QString(AURA_LIBRARY_RESOURCE_DIR)+"/texture")
#define AURAUI_SATHEME_DIR QString(QString(AURA_LIBRARY_RESOURCE_DIR)+"/style/SARibbon")
#define AURAUI_RCC_DIR QString(QString(AURA_LIBRARY_RESOURCE_DIR)+"/rcc")
//=================================================================================
