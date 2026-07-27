cmake_minimum_required(VERSION 3.15)
project(RaylibGame CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)