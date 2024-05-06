cmake_minimum_required(VERSION 3.5.0)

project(Blueteeth VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)


set(CMAKE_PREFIX_PATH "C:/Qt/6.4.3/msvc2019_64")
message("123444")

find_package(Qt6 COMPONENTS Core Widgets Bluetooth REQUIRED)
#qt_standard_project_setup()


#include_directories(src/shared)

#add_subdirectory(src/shared)
add_subdirectory(src/app)
