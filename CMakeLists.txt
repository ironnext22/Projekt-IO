cmake_minimum_required(VERSION 3.21)
project(Projekt-IO)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projekt-IO main.cpp MENU.cpp MENU.h)


set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ./SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(./SFML-2.5.1/include)
target_link_libraries(Projekt-IO sfml-system sfml-window sfml-graphics sfml-audio)

