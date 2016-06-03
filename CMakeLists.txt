CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT("ui-qtlike")

ADD_DEFINITIONS("-std=c++11")

FIND_LIBRARY(UI_LIBRARY ui HINTS ${CMAKE_CURRENT_SOURCE_DIR}/libui)

ADD_EXECUTABLE (main-window
    examples/main-window/main.cpp
    libui-qtlike/libui-qtlike.cpp
)

TARGET_LINK_LIBRARIES(main-window PUBLIC ${UI_LIBRARY})
