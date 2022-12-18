cmake_minimum_required(VERSION 3.20)
project(Projekt-IO)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projekt-IO main.cpp MENU.cpp MENU.h)


set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(Projekt-IO sfml-system sfml-window sfml-graphics sfml-audio)

