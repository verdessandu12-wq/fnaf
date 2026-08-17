cmake_minimum_required(VERSION 3.15)
project(fnaf CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
)
FetchContent_MakeAvailable(raylib)

# Colectează fișierele sursă .cpp
file(GLOB SOURCES
    "src/*.cpp"
    "src/animatronics/*.cpp"
)

# Creează executabilul proiectului
add_executable(${PROJECT_NAME} ${SOURCES})

# Adaugă directoarele include pentru ca #include "animatronic.h" să meargă simplu
target_include_directories(${PROJECT_NAME} PRIVATE
    src
    src/animatronics
)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)