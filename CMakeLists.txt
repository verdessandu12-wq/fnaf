cmake_minimum_required(VERSION 3.10)

# Numele proiectului tău
project(JoculMeuRaylib CXX)

# Setăm standardul C++ (de exemplu C++17 sau C++20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3. Colectăm toate fișierele .cpp din folderul src
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE SOURCES "src/animatronics/*.cpp")
# 4. Definim executabilul final (numele jocului și fișierele sursă)
add_executable(${PROJECT_NAME} ${SOURCES})

# 5. Linkăm Raylib și librăriile de sistem necesare pentru Windows
if(WIN32)
    target_link_libraries(${PROJECT_NAME} raylib opengl32 gdi32 winmm)
else()
    # Pentru colegii care poate folosesc Linux/Mac în viitor
    target_link_libraries(${PROJECT_NAME} raylib)
endif()