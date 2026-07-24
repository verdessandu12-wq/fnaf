cmake_minimum_required(VERSION 3.10)
project(fnaf)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Colectăm toate fișierele C++
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/animatronics/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

# Forțăm linkerul de Windows/MinGW să folosească main() standard
if(WIN32)
    target_link_libraries(${PROJECT_NAME} raylib opengl32 gdi32 winmm)
    target_link_options(${PROJECT_NAME} PRIVATE -mconsole -Wl,-subsystem,console)
else()
    target_link_libraries(${PROJECT_NAME} raylib)
endif()