# add_subdirectory(App)
# add_subdirectory(Core)
# add_subdirectory(Manager)
# add_subdirectory(UI)

##############################模块引入设置##############################
#子工程引入
list(APPEND AuraEngine_PROJECTS
    App
    Core
    Manager
    UI
)

foreach(AuraEngine_PROJECT  ${AuraEngine_PROJECTS})
        add_subdirectory(${AuraEngine_PROJECT})

        # set_target_properties(${PROJECT_LIB}   PROPERTIES
        # MACOSX_RPATH ON
        # SKIP_BUILD_RPATH OFF
        # BUILD_WITH_INSTALL_RPATH ON
        # INSTALL_RPATH "\$ORIGIN:\$ORIGIN/"
        # INSTALL_RPATH_USE_LINK_PATH ON
        # VERSION ${PROJECT_VERSION} SOVERSION ${PROJECT_VERSION_MAJOR}
        # FOLDER Modules
        # )
endforeach()

##############################模块引入设置##############################

##安装
