
####################################################################################################################
if(AuraLibrary_ALREADY_INCLUDED)
	return()
endif()
set(AuraLibrary_ALREADY_INCLUDED ON)


set(AuraLibrary_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/bin/AuraLibrary.dll")
set(AuraLibrary_RESOURCE_PATH "${CMAKE_CURRENT_LIST_DIR}/resource")
set(AuraLibrary_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")

include("${CMAKE_CURRENT_LIST_DIR}/AuraLibraryTargets.cmake")
include_directories(${AuraLibrary_INCLUDE_DIRS})

# 添加依赖DLL到导入路径
#SARibbon
foreach(TARGET_NAME IN ITEMS  QCustomPlot AuraUIWidget Aura3DGraphics AuraTool Aura2DChart)
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
#find_dependency(Python3)
#find_dependency(OpenSSL)

# OpenSSL 优先查找包，当查找不到时才从thirdPart路径中读取
find_package(OpenSSL QUIET)
if (NOT OpenSSL_FOUND)
    message("openssl not found. use thirdPart")
    set(OpenSSL_Origin ON)
    add_compile_options(-fpermissive)
    set(OPENSSL_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/thirdPart/openssl/include")
    set(OPENSSL_LIB "${CMAKE_CURRENT_LIST_DIR}/thirdPart/openssl/lib")
    include_directories(${OPENSSL_INCLUDE})
    link_directories(${OPENSSL_LIB})
endif()

# Python
if(NOT Use_ThirdPart_Python)
find_package (Python3 COMPONENTS Interpreter Development)
endif()

if(NOT Python3_FOUND)
message("py not found. use thirdPart")
set(Python_Origin ON)
set(PYTHON_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/thirdPart/Python312/include")
set(PYTHON_LIB "${CMAKE_CURRENT_LIST_DIR}/thirdPart/Python312")
include_directories(${PYTHON_INCLUDE})
link_directories(${PYTHON_LIB})
else()
include_directories(${Python3_INCLUDE_DIRS})
link_directories(${Python3_LIBRARY_DIRS})
message("py found in auralibrary config.")
message("python root dir : ${Python3_ROOT_DIR}")
message("python Runtime Dir: ${Python3_RUNTIME_LIBRARY_DIRS}")
message("python version: ${Python3_VERSION} ")
message("python include dir : ${Python3_INCLUDE_DIRS}")
message("py lib :${Python3_LIBRARY_DIRS}")
endif()


set (AuraLibrary_FOUND 1)

list(APPEND AuraLibrary_COMPONENT 
#SARibbon 
QCustomPlot 
AuraUIWidget 
Aura3DGraphics 
AuraTool 
Aura2DChart
)

list(APPEND AuraLibrary_Library
AuraLibrary
${AuraLibrary_COMPONENT}
#${Python3_LIBRARIES}
Eigen3::Eigen
OpenGL::GL
)

if(OpenSSL_FOUND)
list(APPEND AuraLibrary_Library
OpenSSL::SSL
)
elseif(OpenSSL_Origin)
list(APPEND AuraLibrary_Library
${OPENSSL_LIB}/libssl.lib
${OPENSSL_LIB}/libcrypto.lib
)
endif()

if(Python3_FOUND)
list(APPEND AuraLibrary_Library
Python3::Python
)
elseif(Python_Origin)
list(APPEND AuraLibrary_Library
${PYTHON_LIB}/python312.dll
)
endif()

foreach(COMPONENT IN LISTS QT_COMPONENTS)
    list(APPEND AuraLibrary_Library Qt${QT_VERSION_MAJOR}::${COMPONENT})
endforeach()
