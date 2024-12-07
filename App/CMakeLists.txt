set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

if(Build_From_AuraEngine)
    get_property(Module_Output_Path GLOBAL PROPERTY "Module_Output_Path")
else()
    set(Module_Output_Path "${CMAKE_INSTALL_PREFIX}")
endif()

list(APPEND EXE_RUNTIME_LIBRARIES


)
set(module_name ${PROJECT_NAME}_App)

file(GLOB EXE_SOURCE 
    "main.cpp"  
    "mainwindow.cpp"
    "mainwindow.h"
)

add_executable(${module_name} ${EXE_SOURCE})

list(APPEND ${module_name}_RUNTIME_LIBRARIES
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::StateMachine
    ${AuraLibrary_Library}
)
list(APPEND ${module_name}_DEPEND_LIBRARIES
    ${PROJECT_NAME}_Core
    ${PROJECT_NAME}_System
    ${PROJECT_NAME}_EngineCore
)
target_link_libraries(${module_name} PRIVATE
    ${${module_name}_DEPEND_LIBRARIES}
    ${${module_name}_RUNTIME_LIBRARIES}
)

install(TARGETS
    ${module_name}
    EXPORT ${module_name}Target
    RUNTIME DESTINATION "${Module_Output_Path}/"
    LIBRARY DESTINATION "${Module_Output_Path}/"
    ARCHIVE DESTINATION "${Module_Output_Path}/"
)

target_compile_definitions(${module_name} PRIVATE AuraEngine_Use_Library)

