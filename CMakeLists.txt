cmake_minimum_required(VERSION 3.16)

project(fetch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(fetch
    src/main.cpp
    src/config.cpp
    src/GPU/gpuinfo.cpp
    src/oslogo.cpp
    src/CPU/cpu.cpp
    src/memory/memory.cpp
    src/user/user.cpp
)

target_include_directories(fetch PRIVATE include)


find_package(X11 REQUIRED)
target_link_libraries(fetch PRIVATE X11::X11)
find_library(XRANDR_LIBRARY Xrandr REQUIRED)
target_link_libraries(fetch PRIVATE ${XRANDR_LIBRARY})

