set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
include_directories(.)

set(QRC_SOURCE_FILES res.qrc)
qt_add_resources(res.qrc)

add_executable(Blueteeth
  main.cpp
  mainwindow.cpp
        res.qrc
    assets/tray.ico
)

target_link_libraries(Blueteeth PRIVATE Qt6::Widgets)
target_link_libraries(Blueteeth PRIVATE Qt6::Bluetooth)
#target_link_libraries(Blueteeth PRIVATE BlueteethShared)
# set_target_properties(Blueteeth PROPERTIES
#   WIN32_EXECUTABLE ON
#   MACOSX_BUNDLE ON
# )
