cmake_minimum_required(VERSION 3.15)
project(fnaf CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

file(GLOB SOURCES
    "src/*.cpp"
    "src/animatronics/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    src
    src/animatronics
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)