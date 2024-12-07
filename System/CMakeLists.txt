include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(Build_From_AuraEngine)
    get_property(Module_Output_Path GLOBAL PROPERTY "Module_Output_Path")
    get_property(ThirdParty_Path GLOBAL PROPERTY "ThirdParty_Path")
else()
    set(Module_Output_Path "${CMAKE_INSTALL_PREFIX}")
    set(ThirdParty_Path "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty")
endif()

set(module_name ${PROJECT_NAME}_System)   
file(GLOB SYSTEM_SOURCE "*.cpp")
file(GLOB SYSTEM_HEADER "*.h")

add_library(${module_name} SHARED 
    ${SYSTEM_SOURCE}
    ${SYSTEM_HEADER}
)

list(APPEND ${module_name}_RUNTIME_LIBRARIES
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Gui
)
list(APPEND ${module_name}_DEPEND_LIBRARIES
    ${PROJECT_NAME}_Core
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

add_dependencies(${module_name} ${${module_name}_DEPEND_LIBRARIES})
