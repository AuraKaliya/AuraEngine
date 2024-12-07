# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)
#set_property(TARGET SARibbon APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG RELEASE)

set(DEBUG_SUFFIX "d")

# set_target_properties(SARibbon PROPERTIES
#   IMPORTED_IMPLIB_DEBUG "${CMAKE_CURRENT_LIST_DIR}/arc/libSARibbon${DEBUG_SUFFIX}.dll.a"
#   IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libSARibbon.dll.a"
#   IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "Qt${QT_VERSION_MAJOR}::Widgets"
#   IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Qt${QT_VERSION_MAJOR}::Widgets"
#   IMPORTED_LOCATION_DEBUG "${CMAKE_CURRENT_LIST_DIR}/bin/SARibbon${DEBUG_SUFFIX}.dll"
#   IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/SARibbon.dll"
# )

# list(APPEND _cmake_import_check_targets SARibbon)
# list(APPEND _cmake_import_check_files_for_SARibbon 
#     "${CMAKE_CURRENT_LIST_DIR}/arc/libSARibbon${DEBUG_SUFFIX}.dll.a" 
#     "${CMAKE_CURRENT_LIST_DIR}/bin/SARibbon${DEBUG_SUFFIX}.dll" 
#     "${CMAKE_CURRENT_LIST_DIR}/arc/libSARibbon.dll.a" 
#     "${CMAKE_CURRENT_LIST_DIR}/bin/SARibbon.dll"
# )

# Import target "QCustomPlot" for configurations "Debug" and "Release"
set_property(TARGET QCustomPlot APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG RELEASE)

set_target_properties(QCustomPlot PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${CMAKE_CURRENT_LIST_DIR}/arc/libQCustomPlot${DEBUG_SUFFIX}.dll.a"
  IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libQCustomPlot.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "Qt${QT_VERSION_MAJOR}::Widgets;Qt${QT_VERSION_MAJOR}::Core;Qt${QT_VERSION_MAJOR}::Gui;Qt${QT_VERSION_MAJOR}::PrintSupport"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Qt${QT_VERSION_MAJOR}::Widgets;Qt${QT_VERSION_MAJOR}::Core;Qt${QT_VERSION_MAJOR}::Gui;Qt${QT_VERSION_MAJOR}::PrintSupport"
  IMPORTED_LOCATION_DEBUG "${CMAKE_CURRENT_LIST_DIR}/bin/QCustomPlot${DEBUG_SUFFIX}.dll"
  IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/QCustomPlot.dll"
)

list(APPEND _cmake_import_check_targets QCustomPlot)
list(APPEND _cmake_import_check_files_for_QCustomPlot 
  "${CMAKE_CURRENT_LIST_DIR}/arc/libQCustomPlot${DEBUG_SUFFIX}.dll.a" 
  "${CMAKE_CURRENT_LIST_DIR}/bin/QCustomPlot${DEBUG_SUFFIX}.dll"
  "${CMAKE_CURRENT_LIST_DIR}/arc/libQCustomPlot.dll.a" 
  "${CMAKE_CURRENT_LIST_DIR}/bin/QCustomPlot.dll"
)

# Import target "AuraUIWidget" for configurations "Debug" and "Release"
set_property(TARGET AuraUIWidget APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG RELEASE)

set_target_properties(AuraUIWidget PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraUIWidget${DEBUG_SUFFIX}.dll.a"
  IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraUIWidget.dll.a"
  #SARibbon;
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "Qt${QT_VERSION_MAJOR}::Core;Qt${QT_VERSION_MAJOR}::Gui;Qt${QT_VERSION_MAJOR}::Widgets;AuraTool"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Qt${QT_VERSION_MAJOR}::Core;Qt${QT_VERSION_MAJOR}::Gui;Qt${QT_VERSION_MAJOR}::Widgets;AuraTool"
  IMPORTED_LOCATION_DEBUG "${CMAKE_CURRENT_LIST_DIR}/bin/AuraUIWidget${DEBUG_SUFFIX}.dll"
  IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/AuraUIWidget.dll"
)

list(APPEND _cmake_import_check_targets AuraUIWidget)
list(APPEND _cmake_import_check_files_for_AuraUIWidget 
  "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraUIWidget${DEBUG_SUFFIX}.dll.a" 
  "${CMAKE_CURRENT_LIST_DIR}/bin/AuraUIWidget${DEBUG_SUFFIX}.dll"
  "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraUIWidget.dll.a" 
  "${CMAKE_CURRENT_LIST_DIR}/bin/AuraUIWidget.dll"
)

# Import target "Aura3DGraphics" for configurations "Debug" and "Release"
list(APPEND Aura3DGraphics_Link
    "Qt${QT_VERSION_MAJOR}::Widgets"
    "Qt${QT_VERSION_MAJOR}::Core"
    "Qt${QT_VERSION_MAJOR}::Gui"
    "AuraTool"
    "AuraUIWidget"
)

if("${QT_VERSION_MAJOR}" STREQUAL "6")
    list(APPEND Aura3DGraphics_Link
        "Qt${QT_VERSION_MAJOR}::OpenGLWidgets"
        "Qt${QT_VERSION_MAJOR}::OpenGL"
    )
else()
    list(APPEND Aura3DGraphics_Link
        "Qt${QT_VERSION_MAJOR}::OpenGL"
    )
endif()


# Set target properties for both Debug and Release configurations
set_property(TARGET Aura3DGraphics APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG RELEASE)
set_target_properties(Aura3DGraphics PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${CMAKE_CURRENT_LIST_DIR}/arc/libAura3DGraphics${DEBUG_SUFFIX}.dll.a"
  IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libAura3DGraphics.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "${Aura3DGraphics_Link}"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "${Aura3DGraphics_Link}"
  IMPORTED_LOCATION_DEBUG "${CMAKE_CURRENT_LIST_DIR}/bin/Aura3DGraphics${DEBUG_SUFFIX}.dll"
  IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/Aura3DGraphics.dll"
)

list(APPEND _cmake_import_check_targets Aura3DGraphics)
list(APPEND _cmake_import_check_files_for_Aura3DGraphics
    "${CMAKE_CURRENT_LIST_DIR}/arc/libAura3DGraphics${DEBUG_SUFFIX}.dll.a"
    "${CMAKE_CURRENT_LIST_DIR}/bin/Aura3DGraphics${DEBUG_SUFFIX}.dll"
    "${CMAKE_CURRENT_LIST_DIR}/arc/libAura3DGraphics.dll.a"
    "${CMAKE_CURRENT_LIST_DIR}/bin/Aura3DGraphics.dll"
)

# Import target "AuraTool" for configurations "Debug" and "Release"
set_property(TARGET AuraTool APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG RELEASE)

#    #####${Python_COMPONENT}
set_target_properties(AuraTool PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraTool${DEBUG_SUFFIX}.dll.a"
  IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraTool.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "Qt${QT_VERSION_MAJOR}::Core;Qt${QT_VERSION_MAJOR}::Gui"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Qt${QT_VERSION_MAJOR}::Core;Qt${QT_VERSION_MAJOR}::Gui"
  IMPORTED_LOCATION_DEBUG "${CMAKE_CURRENT_LIST_DIR}/bin/AuraTool${DEBUG_SUFFIX}.dll"
  IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/AuraTool.dll"
)

list(APPEND _cmake_import_check_targets AuraTool)
list(APPEND _cmake_import_check_files_for_AuraTool
  "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraTool${DEBUG_SUFFIX}.dll.a"
  "${CMAKE_CURRENT_LIST_DIR}/bin/AuraTool${DEBUG_SUFFIX}.dll"
  "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraTool.dll.a"
  "${CMAKE_CURRENT_LIST_DIR}/bin/AuraTool.dll"
)

# Import target "Aura2DChart" for configurations "Debug" and "Release"
set_property(TARGET Aura2DChart APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG RELEASE)

set_target_properties(Aura2DChart PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${CMAKE_CURRENT_LIST_DIR}/arc/libAura2DChart${DEBUG_SUFFIX}.dll.a"
  IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libAura2DChart.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "Qt${QT_VERSION_MAJOR}::Widgets;Qt${QT_VERSION_MAJOR}::PrintSupport;Qt${QT_VERSION_MAJOR}::Core;Qt${QT_VERSION_MAJOR}::Gui"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Qt${QT_VERSION_MAJOR}::Widgets;Qt${QT_VERSION_MAJOR}::PrintSupport;Qt${QT_VERSION_MAJOR}::Core;Qt${QT_VERSION_MAJOR}::Gui"
  IMPORTED_LOCATION_DEBUG "${CMAKE_CURRENT_LIST_DIR}/bin/Aura2DChart${DEBUG_SUFFIX}.dll"
  IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/Aura2DChart.dll"
)

list(APPEND _cmake_import_check_targets Aura2DChart)
list(APPEND _cmake_import_check_files_for_Aura2DChart
  "${CMAKE_CURRENT_LIST_DIR}/arc/libAura2DChart${DEBUG_SUFFIX}.dll.a"
  "${CMAKE_CURRENT_LIST_DIR}/bin/Aura2DChart${DEBUG_SUFFIX}.dll"
  "${CMAKE_CURRENT_LIST_DIR}/arc/libAura2DChart.dll.a"
  "${CMAKE_CURRENT_LIST_DIR}/bin/Aura2DChart.dll"
)

# Import target "AuraLibrary" for configurations "Debug" and "Release"
list(APPEND AuraLibrary_Link
    "Qt${QT_VERSION_MAJOR}::Widgets"
    "Qt${QT_VERSION_MAJOR}::PrintSupport"
    "Qt${QT_VERSION_MAJOR}::Core"
    "Qt${QT_VERSION_MAJOR}::Gui"
    #"SARibbon"
    "QCustomPlot"
    "AuraUIWidget"
    "Aura3DGraphics"
    "AuraTool"
)
if("${QT_VERSION_MAJOR}" STREQUAL "6")
    list(APPEND AuraLibrary_Link
        "Qt${QT_VERSION_MAJOR}::OpenGLWidgets"
        "Qt${QT_VERSION_MAJOR}::OpenGL"
    )

else()
    list(APPEND AuraLibrary_Link
        "Qt${QT_VERSION_MAJOR}::OpenGL"
    )
endif()

# foreach(Python_COMPONENT in ${Python3_LIBRARIES})
# list(APPEND AuraLibrary_Link 
# "${Python_COMPONENT}"
# )
# endforeach()



# Set target properties for both Debug and Release configurations
set_property(TARGET AuraLibrary APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG RELEASE)
set_target_properties(AuraLibrary PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraLibrary${DEBUG_SUFFIX}.dll.a"
  IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraLibrary.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "${AuraLibrary_Link}"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "${AuraLibrary_Link}"
  IMPORTED_LOCATION_DEBUG "${CMAKE_CURRENT_LIST_DIR}/bin/AuraLibrary${DEBUG_SUFFIX}.dll"
  IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/AuraLibrary.dll"
)

list(APPEND _cmake_import_check_targets AuraLibrary)
list(APPEND _cmake_import_check_files_for_AuraLibrary
    "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraLibrary${DEBUG_SUFFIX}.dll.a"
    "${CMAKE_CURRENT_LIST_DIR}/bin/AuraLibrary${DEBUG_SUFFIX}.dll"
    "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraLibrary.dll.a"
    "${CMAKE_CURRENT_LIST_DIR}/bin/AuraLibrary.dll"
)

# Import target "AuraLibraryStatic" for configurations "Debug" and "Release"
set_property(TARGET AuraLibraryStatic APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG RELEASE)
set_target_properties(AuraLibraryStatic PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_DEBUG "${CMAKE_CURRENT_LIST_DIR}/lib/AuraLibrary${DEBUG_SUFFIX}.a"
  IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/lib/AuraLibrary.a"
)

list(APPEND _cmake_import_check_targets AuraLibraryStatic)
list(APPEND _cmake_import_check_files_for_AuraLibraryStatic
    "${CMAKE_CURRENT_LIST_DIR}/lib/AuraLibrary${DEBUG_SUFFIX}.a"
    "${CMAKE_CURRENT_LIST_DIR}/lib/AuraLibrary.a"
)

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)



