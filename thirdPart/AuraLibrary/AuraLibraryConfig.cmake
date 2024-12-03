
####################################################################################################################


set(AuraLibrary_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/AuraLibrary.dll")

include_directories(${AuraLibrary_INCLUDE_DIRS})

include("${CMAKE_CURRENT_LIST_DIR}/AuraLibraryTargets.cmake")

# 添加依赖DLL到导入路径
foreach(TARGET_NAME IN ITEMS SARibbon QCustomPlot AuraUIWidget Aura3DGraphics AuraTool Aura2DChart)
    get_target_property(TARGET_LOCATION ${TARGET_NAME} IMPORTED_LOCATION)
    set_property(TARGET AuraLibrary APPEND PROPERTY IMPORTED_LOCATION ${TARGET_LOCATION})
endforeach()

include(CMakeFindDependencyMacro)

# 添加Qt运行库
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS)

set(QT_COMPONENTS
    Widgets
    PrintSupport
    Core
    Gui
)

# Qt版本适配
if(${QT_VERSION_MAJOR} EQUAL 6)
    list(APPEND QT_COMPONENTS
        OpenGL
        OpenGLWidgets
    )
else()
    list(APPEND QT_COMPONENTS
        OpenGL
    )
endif()

foreach(COMPONENT IN LISTS QT_COMPONENTS)
    find_dependency(Qt${QT_VERSION_MAJOR}${COMPONENT})
endforeach()

# 查找其他依赖
find_dependency(OpenGL)
find_dependency(Eigen3)

#find_dependency(OpenSSL)
# OpenSSL 优先查找包，当查找不到时才从thirdPart路径中读取
find_package(OpenSSL QUIET)
if (NOT OpenSSL_FOUND)
    add_compile_options(-fpermissive)
    set(OPENSSL_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/thirdPart/openssl/include")
    set(OPENSSL_LIB "${CMAKE_CURRENT_LIST_DIR}/thirdPart/openssl/lib")
    include_directories(${OPENSSL_INCLUDE})
    link_directories(${OPENSSL_LIB})
    link_libraries(
        ${OPENSSL_LIB}/libssl.lib
        ${OPENSSL_LIB}/libcrypto.lib
    )
endif()

#include("${CMAKE_CURRENT_LIST_DIR}/AuraLibraryTargets.cmake")

set (AuraLibrary_FOUND 1)
set(AuraLibrary_RESOURCE_PATH "${CMAKE_CURRENT_LIST_DIR}/resource")
set(AuraLibrary_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")

list(APPEND AuraLibrary_COMPONENT 
SARibbon 
QCustomPlot 
AuraUIWidget 
Aura3DGraphics 
AuraTool 
Aura2DChart
)

list(APPEND AuraLibrary_Library
AuraLibrary
${AuraLibrary_COMPONENT}
Eigen3::Eigen
OpenGL::GL
)

if(OpenSSL_FOUND)
list(APPEND AuraLibrary_Library
OpenSSL::SSL
)
endif()

foreach(COMPONENT IN LISTS QT_COMPONENTS)
    list(APPEND AuraLibrary_Library Qt${QT_VERSION_MAJOR}::${COMPONENT})
endforeach()
