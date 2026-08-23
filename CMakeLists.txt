cmake_minimum_required(VERSION 3.16)

project(grape VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools Svg)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools Svg)
include(FetchContent)
FetchContent_Declare(
    LIEF
    GIT_REPOSITORY https://github.com/lief-project/LIEF.git
    GIT_TAG 1.0.0
)
FetchContent_MakeAvailable(LIEF)
add_subdirectory(libs/simpleini)

set(TS_FILES lang/grape_en_US.ts)

set(PROJECT_SOURCES
        main.cpp
        # widgets (components)
        ui/widgets/grpropertypanel.h ui/widgets/grpropertypanel.cpp
        ui/widgets/grpropertypanelmgr.h ui/widgets/grpropertypanelmgr.cpp
        ui/widgets/grproject.h ui/widgets/grproject.cpp
        ui/widgets/grprojecttree.h ui/widgets/grprojecttree.cpp
        ui/widgets/grwidget.h ui/widgets/grwidget.cpp
        ui/widgets/grstatusbar.h ui/widgets/grstatusbar.cpp
        ui/widgets/grcanvasworkspace.h ui/widgets/grcanvasworkspace.cpp
        ui/widgets/grcheckbox.h ui/widgets/grcheckbox.cpp
        ui/widgets/grspinner.h ui/widgets/grspinner.cpp
        ui/widgets/grlangtablebrowser.h ui/widgets/grlangtablebrowser.cpp
        ui/widgets/grlineedit.h ui/widgets/grlineedit.cpp
        ui/widgets/graltbutton.h ui/widgets/graltbutton.cpp
        ui/widgets/grfiltermenu.h ui/widgets/grfiltermenu.cpp
        ui/widgets/gridselector.h ui/widgets/gridselector.cpp
        ui/widgets/gridselectorpopup.h ui/widgets/gridselectorpopup.cpp
        # views (pages)
        ui/grapew.h ui/grapew.cpp ui/grapew.ui
        ui/grwelcomescreen.h ui/grwelcomescreen.cpp
        ui/grworkspace.h ui/grworkspace.cpp
        # graphics (texture maps)
        graphics/gricon.h graphics/gricon.cpp
        graphics/grtexture.h graphics/grtexture.cpp
        # scanner files (data)
        scanner/grasset.h scanner/grasset.cpp
        scanner/centity.h scanner/centity.cpp
        scanner/cbfunit.h scanner/cbfunit.cpp
        scanner/cztunit.h scanner/cztunit.cpp
        scanner/canimal.h scanner/canimal.cpp
        scanner/cscenery.h scanner/cscenery.cpp
        scanner/cbuilding.h scanner/cbuilding.cpp
        scanner/cfence.h scanner/cfence.cpp
        scanner/cpath.h scanner/cpath.cpp
        scanner/ctankfilter.h scanner/ctankfilter.cpp
        scanner/grdscanner.h scanner/grdscanner.cpp
        # shared sources (misc)
        common/grshared.h
        common/grtreenode.h common/grtreenode.cpp
        common/grini.h common/grini.cpp
        common/grslots.h common/grslots.cpp
        common/grgfx.h common/grgfx.cpp
        common/grpe.h common/grpe.cpp
        resources.qrc
        # models
        models/grprojecttreemodel.h models/grprojecttreemodel.cpp
        models/grlangtablemodel.h models/grlangtablemodel.cpp
        models/grlangfilterproxy.h
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)

qt_add_executable(grape
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

target_include_directories(
    grape PRIVATE
    common
    ui
    ui/widgets
    models
    graphics
    scanner
)
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET grape APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(grape SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(grape
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(grape PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    SimpleIni::SimpleIni
    Qt6::Svg
    LIEF::LIEF
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.grape)
endif()
set_target_properties(grape PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS grape
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(grape)
endif()
