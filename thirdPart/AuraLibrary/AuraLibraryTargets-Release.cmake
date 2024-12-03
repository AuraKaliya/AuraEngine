#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)
message("!!!!==========Config release target:${QT_VERSION_MAJOR}")
# Import target "SARibbon" for configuration "Release"
set_property(TARGET SARibbon APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SARibbon PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libSARibbon.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Qt${QT_VERSION_MAJOR}::Widgets"
  IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/SARibbon.dll"
  )

list(APPEND _cmake_import_check_targets SARibbon )
list(APPEND _cmake_import_check_files_for_SARibbon "${CMAKE_CURRENT_LIST_DIR}/arc/libSARibbon.dll.a" "${CMAKE_CURRENT_LIST_DIR}/bin/SARibbon.dll" )

# Import target "QCustomPlot" for configuration "Release"
set_property(TARGET QCustomPlot APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(QCustomPlot PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libQCustomPlot.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Qt${QT_VERSION_MAJOR}::Widgets;Qt${QT_VERSION_MAJOR}::Core;Qt${QT_VERSION_MAJOR}::Gui;Qt${QT_VERSION_MAJOR}::PrintSupport"
  IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/QCustomPlot.dll"
  )

list(APPEND _cmake_import_check_targets QCustomPlot )
list(APPEND _cmake_import_check_files_for_QCustomPlot "${CMAKE_CURRENT_LIST_DIR}/arc/libQCustomPlot.dll.a" "${CMAKE_CURRENT_LIST_DIR}/bin/QCustomPlot.dll" )

# Import target "AuraUIWidget" for configuration "Release"
set_property(TARGET AuraUIWidget APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(AuraUIWidget PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraUIWidget.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "QT${QT_VERSION_MAJOR}::Core;QT${QT_VERSION_MAJOR}::Gui;QT${QT_VERSION_MAJOR}::Widgets;SARibbon;AuraTool"
  IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/AuraUIWidget.dll"
  )

list(APPEND _cmake_import_check_targets AuraUIWidget )
list(APPEND _cmake_import_check_files_for_AuraUIWidget "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraUIWidget.dll.a" "${CMAKE_CURRENT_LIST_DIR}/bin/AuraUIWidget.dll" )

# Import target "Aura3DGraphics" for configuration "Release"
list (APPEND Aura3DGraphics_Link_release 
"QT${QT_VERSION_MAJOR}::Widgets;QT${QT_VERSION_MAJOR}::Core;QT${QT_VERSION_MAJOR}::Gui;AuraTool;AuraUIWidget"
 )
 if(${QT_VERSION_MAJOR} EQUAL 6)
 list (APPEND Aura3DGraphics_Link_release 
 "QT${QT_VERSION_MAJOR}::OpenGLWidgets"
 "QT${QT_VERSION_MAJOR}::OpenGL"
 )
 else()
 list (APPEND Aura3DGraphics_Link_release 
 "QT${QT_VERSION_MAJOR}::OpenGL"
 )
 endif()
set_property(TARGET Aura3DGraphics APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Aura3DGraphics PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libAura3DGraphics.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "${Aura3DGraphics_Link_release}"
  #"QT${QT_VERSION_MAJOR}::Widgets;QT${QT_VERSION_MAJOR}::Core;QT${QT_VERSION_MAJOR}::Gui;QT${QT_VERSION_MAJOR}::OpenGL;AuraAlgorithm;AuraUIWidget"
  IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/Aura3DGraphics.dll"
  )

list(APPEND _cmake_import_check_targets Aura3DGraphics )
list(APPEND _cmake_import_check_files_for_Aura3DGraphics "${CMAKE_CURRENT_LIST_DIR}/arc/libAura3DGraphics.dll.a" "${CMAKE_CURRENT_LIST_DIR}/bin/Aura3DGraphics.dll" )

# Import target "AuraPixture" for configuration "Release"
# set_property(TARGET AuraPixture APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
# set_target_properties(AuraPixture PROPERTIES
#   IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraPixture.dll.a"
#   IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "QT${QT_VERSION_MAJOR}::Core;QT${QT_VERSION_MAJOR}::Gui;QT${QT_VERSION_MAJOR}::Widgets"
#   IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/AuraPixture.dll"
#   )

# list(APPEND _cmake_import_check_targets AuraPixture )
# list(APPEND _cmake_import_check_files_for_AuraPixture "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraPixture.dll.a" "${CMAKE_CURRENT_LIST_DIR}/bin/AuraPixture.dll" )

# Import target "AuraProperty" for configuration "Release"
# set_property(TARGET AuraProperty APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
# set_target_properties(AuraProperty PROPERTIES
#   IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraProperty.dll.a"
#   IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "QT${QT_VERSION_MAJOR}::Core"
#   IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/AuraProperty.dll"
#   )

# list(APPEND _cmake_import_check_targets AuraProperty )
# list(APPEND _cmake_import_check_files_for_AuraProperty "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraProperty.dll.a" "${CMAKE_CURRENT_LIST_DIR}/bin/AuraProperty.dll" )

# Import target "AuraAlgorithm" for configuration "Release"
# set_property(TARGET AuraAlgorithm APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
# set_target_properties(AuraAlgorithm PROPERTIES
#   IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraAlgorithm.dll.a"
#   IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "QT${QT_VERSION_MAJOR}::Core;QT${QT_VERSION_MAJOR}::Gui"
#   IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/AuraAlgorithm.dll"
#   )

# list(APPEND _cmake_import_check_targets AuraAlgorithm )
# list(APPEND _cmake_import_check_files_for_AuraAlgorithm "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraAlgorithm.dll.a" "${CMAKE_CURRENT_LIST_DIR}/bin/AuraAlgorithm.dll" )
# Import target "AuraAlgorithm" for configuration "Release"
set_property(TARGET AuraTool APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(AuraTool PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraTool.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "QT${QT_VERSION_MAJOR}::Core;QT${QT_VERSION_MAJOR}::Gui"
  IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/AuraTool.dll"
  )

list(APPEND _cmake_import_check_targets AuraTool )
list(APPEND _cmake_import_check_files_for_AuraTool "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraTool.dll.a" "${CMAKE_CURRENT_LIST_DIR}/bin/AuraTool.dll" )

# Import target "Aura2DChart" for configuration "Release"
set_property(TARGET Aura2DChart APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Aura2DChart PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libAura2DChart.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "QT${QT_VERSION_MAJOR}::Widgets;QT${QT_VERSION_MAJOR}::PrintSupport;QT${QT_VERSION_MAJOR}::Core;QT${QT_VERSION_MAJOR}::Gui"
  IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/Aura2DChart.dll"
  )

list(APPEND _cmake_import_check_targets Aura2DChart )
list(APPEND _cmake_import_check_files_for_Aura2DChart "${CMAKE_CURRENT_LIST_DIR}/arc/libAura2DChart.dll.a" "${CMAKE_CURRENT_LIST_DIR}/bin/Aura2DChart.dll" )

# Import target "AuraLibrary" for configuration "Release"
list (APPEND AuraLibrary_Link_release 
"QT${QT_VERSION_MAJOR}::Widgets;QT${QT_VERSION_MAJOR}::PrintSupport;QT${QT_VERSION_MAJOR}::Core;QT${QT_VERSION_MAJOR}::Gui;SARibbon;QCustomPlot;AuraUIWidget;Aura3DGraphics;AuraTool"
 )
 if(${QT_VERSION_MAJOR} EQUAL 6)
 list (APPEND AuraLibrary_Link_release 
 "QT${QT_VERSION_MAJOR}::OpenGLWidgets"
 "QT${QT_VERSION_MAJOR}::OpenGL"
 )
 else()
 list (APPEND AuraLibrary_Link_release 
 "QT${QT_VERSION_MAJOR}::OpenGL"
 )
 endif()
set_property(TARGET AuraLibrary APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(AuraLibrary PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraLibrary.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "${AuraLibrary_Link_release}"
  #"QT${QT_VERSION_MAJOR}::Widgets;QT${QT_VERSION_MAJOR}::PrintSupport;QT${QT_VERSION_MAJOR}::Core;QT${QT_VERSION_MAJOR}::Gui;QT${QT_VERSION_MAJOR}::OpenGL;SARibbon;QCustomPlot;AuraUIWidget;Aura3DGraphics;AuraPixture;AuraProperty;AuraAlgorithm"
  IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/bin/AuraLibrary.dll"
  )

list(APPEND _cmake_import_check_targets AuraLibrary )
list(APPEND _cmake_import_check_files_for_AuraLibrary "${CMAKE_CURRENT_LIST_DIR}/arc/libAuraLibrary.dll.a" "${CMAKE_CURRENT_LIST_DIR}/bin/AuraLibrary.dll" )

# Import target "AuraLibraryStatic" for configuration "Release"
set_property(TARGET AuraLibraryStatic APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(AuraLibraryStatic PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_LIST_DIR}/lib/AuraLibrary.a"
  )

list(APPEND _cmake_import_check_targets AuraLibraryStatic )
list(APPEND _cmake_import_check_files_for_AuraLibraryStatic "${CMAKE_CURRENT_LIST_DIR}/lib/AuraLibrary.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
