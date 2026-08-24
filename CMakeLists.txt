cmake_minimum_required(VERSION 3.16)

project(fetch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(fetch
    src/main.cpp
    src/system.cpp
    src/config.cpp
    src/oslogo.cpp
)

target_include_directories(fetch PRIVATE
    include
)