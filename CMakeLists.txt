cmake_minimum_required(VERSION 3.5)

project(AuraEngine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

############################## hong #############################
add_compile_definitions(
    QDEBUGCHECK

)
############################## hong #############################

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools StateMachine OpenGLWidgets Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools StateMachine OpenGLWidgets Core)

#openssl
set(OPENSSL_LIB ${CMAKE_CURRENT_SOURCE_DIR}/SOURCE/Engine/ThirdLibrary/openssl/lib)
set(OPENSSL_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/SOURCE/Engine/ThirdLibrary/openssl/include)

#lua
set(LUA_LIB ${CMAKE_CURRENT_SOURCE_DIR}/SOURCE/Engine/ThirdLibrary/lua/lib)
set(LUA_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/SOURCE/Engine/ThirdLibrary/lua/include)

#third library
link_directories(
    ${LUA_LIB}
    ${OPENSSL_LIB}
)
include_directories(
    ${LUA_INCLUDE}
    ${OPENSSL_INCLUDE}
)


file(GLOB_RECURSE SRC_FILES   "DEMO/*.h" "DEMO/*.cpp" "DATA/*.h" "DATA/*.cpp" "TOOL/*.hpp" "TOOL/*.h" "TOOL/*.cpp" "UI/*.h" "UI/*.cpp")

message("=====")
message(${CMAKE_CURRENT_SOURCE_DIR})

set(PROJECT_SOURCES
        main.cpp
        enginecore.cpp
        enginecore.h
        ${SRC_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(AuraEngine
        #MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        UI/completeUI/editinstructioneditwidget.h UI/completeUI/editinstructioneditwidget.cpp
        DATA/BaseClass/instructionfunctioninfomation.h DATA/BaseClass/instructionfunctioninfomation.cpp
        UI/componentUI/argumenteditwidget.h UI/componentUI/argumenteditwidget.cpp
        UI/componentUI/auramenubar.h UI/componentUI/auramenubar.cpp
        DATA/BaseClass/engineinfomation.h DATA/BaseClass/engineinfomation.cpp
        #auramainwindow.h auramainwindow.cpp
    )

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(AuraEngine SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(AuraEngine
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

# #third library
# link_directories(
#     ${LUA_LIB}
#     ${OPENSSL_LIB}
# )


target_link_libraries(AuraEngine PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::StateMachine
    Qt${QT_VERSION_MAJOR}::OpenGLWidgets
    Qt${QT_VERSION_MAJOR}::Core
    lua54
                                       )

set_target_properties(AuraEngine PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS AuraEngine
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(AuraEngine)
endif()


