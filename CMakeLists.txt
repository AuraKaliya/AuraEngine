cmake_minimum_required(VERSION 3.14)

project(AuraEngine VERSION 0.1 LANGUAGES CXX)

#编译选项
##Qt 编译选项
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
##C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
##库前缀
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_MODULE_PREFIX "")


#工程属性
##资源路径
set(MODULE_OUTPUT_PATH "${CMAKE_INSTALL_PREFIX}")
set(PACKAGE_PREFIX_DIR "${MODULE_OUTPUT_PATH}")
set(THIRDPART_DIR "${CMAKE_CURRENT_SOURCE_DIR}/thirdPart")

#依赖引入
#############################外部源代码##############################

#############################外部源代码##############################

#############################外部静态库##############################

#############################外部静态库##############################

#############################外部动态库##############################
#Qt - 模块引入
list(APPEND QtNeededModules
    Core
    Widgets
    PrintSupport
    Gui
)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS )

## Qt6 5 适配
if(${QT_VERSION_MAJOR} EQUAL 6)
    list(APPEND QtNeededModules
        OpenGLWidgets
        OpenGL
    )
    message("WARNING: Qt version is 6.")
else()
    list(APPEND QtNeededModules
        OpenGL
    )
    message("WARNING: Qt version is not 6.")
endif()
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS ${QtNeededModules})


include(GNUInstallDirs)

add_subdirectory(src)

# install(TARGETS AuraEngine
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# if(QT_VERSION_MAJOR EQUAL 6)
#     qt_finalize_executable(AuraEngine)
# endif()
