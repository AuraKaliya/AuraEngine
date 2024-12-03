#pragma once

#include "../AuraGlobal.h"

#include <AuraTemplate/Singleton.hpp>

namespace AuraTool {

class AURAUI_LIB_DECL AuraMachineTool
{
    SINGLETON_H(AuraMachineTool)
    SINGLETON_H_CONSTRUCTOR(AuraMachineTool)
public:
    //AuraMachineTool();
    static QString getMACAdress();
};

} // namespace AuraTool

