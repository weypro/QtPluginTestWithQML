cmake_minimum_required(VERSION 3.16)

project(helloplugin VERSION 0.1 LANGUAGES CXX)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()


add_library (helloplugin SHARED basictoolsplugin.cpp basictoolsplugin.h)
qt_add_qml_module(helloplugin
        URI helloplugin
        VERSION 1.0
        QML_FILES main.qml
        RESOURCES
        SOURCES
        SOURCES hellopluginviewcontroller.h hellopluginviewcontroller.cpp
        QML_FILES purewindow.qml
        QML_FILES QtStyleButton.qml
)


target_sources(helloplugin
  PRIVATE
    main.qml
)

target_include_directories(helloplugin PRIVATE
    ../../include
)

target_link_libraries(helloplugin PRIVATE
    Qt6::Core
    Qt6::Quick
    modulecore
)
