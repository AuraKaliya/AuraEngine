set(VERSION ${PROJECT_VERSION_MAJOR})

#头文件搜索路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../)

#####=======================前置配置=============================#####



#模块依赖
#############################外部动态库##############################
# 模块引入部分放在最外层CMake中，代表整个项目需要引入的动态库
# 各模块若需要单独列出进行编译，需要按需引入动态库
# 在各模块中只需列出使用库的列表即可

#库使用列表
list(APPEND AuraEngine_App_RUNTIME_LIBRARIES
    Qt${QT_VERSION_MAJOR}::Widgets
    # Qt${QT_VERSION_MAJOR}::PrintSupport
    Qt${QT_VERSION_MAJOR}::Core
    # Qt${QT_VERSION_MAJOR}::Gui
    # Eigen3::Eigen
    # OpenGL::GL
)
#############################外部动态库##############################end

#############################模块依赖项##############################
list(APPEND AuraEngine_App_DEPEND_LIBRARIES
#     SARibbon
#     QCustomPlot
# ##################################
#     AuraUIWidget
#     Aura3DGraphics
#     AuraTool
#     Aura2DChart
)

#############################模块依赖项##############################end

#############################模块文件##############################
# 模块文件
file(GLOB_RECURSE AuraEngine_App_FILES
    main.cpp
)
add_executable(
    AuraEngine
    ${AuraEngine_App_FILES}
)

# 链接库
target_link_libraries( AuraEngine PRIVATE
 ${AuraEngine_App_RUNTIME_LIBRARIES}
)

# 添加库用宏
#target_compile_definitions
#############################模块文件##############################end
