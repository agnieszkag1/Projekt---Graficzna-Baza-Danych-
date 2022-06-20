cmake_minimum_required(VERSION 3.0)
project(Baza_Przychodnia)

set(CMAKE_CXX_STANDARD 23)

add_executable(Baza_Przychodnia main.cpp Osoba.cpp Osoba.h Lekarz.cpp Lekarz.h Pacjent.cpp Pacjent.h Pielegniarka.cpp Pielegniarka.h Aplikacja.cpp Aplikacja.h Logowanie.cpp Logowanie.h Szukanie.cpp Szukanie.h Dodawanie.cpp Dodawanie.h Sprawdzanie.cpp Sprawdzanie.h)


set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(Baza_Przychodnia sfml-system sfml-window sfml-graphics sfml-audio sfml-network)