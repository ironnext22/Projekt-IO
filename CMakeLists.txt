Cmake_minimum_required(VERSION 3.21)
project(Projekt-IO)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projekt-IO main.cpp Package/Button.cpp includes/Button.h Package/Textline.cpp includes/Textline.h Package/Input_bar.cpp includes/Input_bar.h includes/Pracownik.h includes/Osoba.h includes/Pracownicy.h Package/Pracownicy.cpp Package/Okno.cpp includes/Loging.h Package/Loging.cpp Package/Pracownik.cpp includes/Time_app.h Package/Time_app.cpp includes/Assistant.h includes/Dentist.h includes/Admin.h Package/Admin.cpp includes/Mail.h Package/Mail.cpp includes/Kalendarz.h includes/Wizyta.h includes/Pacjent.h Package/Wizyta.cpp Package/Kalendarz.cpp Package/Osoba.cpp Package/Assistant.cpp includes/Functions.h Package/Functions.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ./SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(./SFML-2.5.1/include)
target_link_libraries(Projekt-IO sfml-system sfml-window sfml-graphics sfml-audio)

add_subdirectory(OpenXLSX)
target_link_libraries(Projekt-IO OpenXLSX::OpenXLSX)
