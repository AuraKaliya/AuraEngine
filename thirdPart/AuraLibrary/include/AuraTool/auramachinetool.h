#pragma once

// #include <vector>
// #include <memory>
// #include <string>
//
//

#include "../AuraGlobal.h"

#include <AuraTemplate/Singleton.hpp>


namespace AuraTool {

class AuraLibrary_DECL AuraMachineTool
{
    SINGLETON_H(AuraMachineTool)
    SINGLETON_H_CONSTRUCTOR(AuraMachineTool)
public:
    //AuraMachineTool();
    static QString getMACAdress();


};

} // namespace AuraTool

