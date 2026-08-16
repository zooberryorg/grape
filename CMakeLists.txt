cmake_minimum_required(VERSION 3.16)

project(grape VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools Svg)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools Svg)
add_subdirectory(libs/simpleini)

set(TS_FILES lang/grape_en_US.ts)

set(PROJECT_SOURCES
        main.cpp
        # views
        ui/grapew.h ui/grapew.cpp ui/grapew.ui
        ui/grprojecttree.h ui/grprojecttree.cpp
        ui/grwelcomescreen.h ui/grwelcomescreen.cpp
        ui/grworkspace.h ui/grworkspace.cpp
        # widgets
        #ui/widgets/
        # graphics
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
        # shared sources
        common/grshared.h
        common/grtreenode.h common/grtreenode.cpp
        common/grini.h common/grini.cpp
        common/grslots.h common/grslots.cpp
        common/gricon.h common/gricon.cpp
        resources.qrc
        # models
        models/grprojecttreemodel.h models/grprojecttreemodel.cpp
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
