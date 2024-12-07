cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
#项目信息
project(
AuraEngine
VERSION 0.0.1 
LANGUAGES CXX
)

#编译系统设置
##C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS ON)
##qt编译flag
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#项目控制语句
set(Build_From_AuraEngine ON)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
##项目属性
set_property(GLOBAL PROPERTY ThirdParty_Path "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty")
set_property(GLOBAL PROPERTY Module_Output_Path "${CMAKE_INSTALL_PREFIX}")

#外部依赖引入
##Qt依赖
list(APPEND QtNeededModules
Core
Widgets
Gui
StateMachine
)
find_package(QT NAMES Qt6 Qt5 COMPONENTS ${QtNeededModules} REQUIRED )
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS ${QtNeededModules}  REQUIRED)
#AuraLibrary依赖
# list(APPEND AuraLibraryNeededModules
# AuraLibrary_Library
# )
find_package(AuraLibrary REQUIRED)

#项目构建依赖
add_subdirectory(App)
add_subdirectory(Core)
add_subdirectory(EngineCore)
add_subdirectory(System)
add_subdirectory(Widgets)




