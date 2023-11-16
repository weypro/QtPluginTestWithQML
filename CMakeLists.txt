cmake_minimum_required(VERSION 3.16)

project(pluginhellotest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

list(APPEND QML_DIRS "${CMAKE_SOURCE_DIR}/qmlplugins")

set(QML_IMPORT_PATH "${QML_DIRS}" CACHE STRING "qml import paths")


add_subdirectory(modulecore)
add_subdirectory(plugins)
add_subdirectory(qmlplugins)
add_subdirectory(appcore)

qt_add_executable(apppluginhellotest
        main.cpp
)

qt_add_qml_module(apppluginhellotest
        URI pluginhellotest
        VERSION 1.0
        QML_FILES Main.qml
#        RESOURCES plugins/CMakeLists.txt
        SOURCES pluginviewcontroller.h pluginviewcontroller.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(apppluginhellotest PROPERTIES
        #    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.apppluginhellotest
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(apppluginhellotest
        PRIVATE Qt6::Quick
#        helloplugin
        modulecore
        appcore
)

target_include_directories(apppluginhellotest PUBLIC include)

add_dependencies(apppluginhellotest helloplugin)
add_dependencies(apppluginhellotest chartsplugin)
add_dependencies(apppluginhellotest UserQMLPlugin)

include(GNUInstallDirs)
install(TARGETS apppluginhellotest
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
