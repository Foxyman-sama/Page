cmake_minimum_required(VERSION 3.5)

project(Page VERSION 0.2)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_HEADERS
    include/mainwindow.hpp
    include/libs.hpp)
set(PROJECT_SOURCES
    src/main.cpp
    src/mainwindow.cpp)

add_executable(Page
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES})

target_include_directories(Page PRIVATE
    include)
target_link_libraries(Page PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Scrap)

add_subdirectory(libs/Scrap)
