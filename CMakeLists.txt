Cmake_minimum_required(VERSION 3.21)
project(Projekt-IO)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projekt-IO main.cpp Package/Button.cpp includes/Button.h Package/Textline.cpp includes/Textline.h Package/Input_bar.cpp includes/Input_bar.h includes/Pracownik.h includes/Osoba.h includes/Pracownicy.h Package/Pracownicy.cpp Package/Okno.cpp includes/Loging.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ./SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(./SFML-2.5.1/include)
target_link_libraries(Projekt-IO sfml-system sfml-window sfml-graphics sfml-audio)

add_subdirectory(OpenXLSX)
target_link_libraries(Projekt-IO OpenXLSX::OpenXLSX)
