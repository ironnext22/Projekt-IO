#ifndef PROJEKT_IO_PRACOWNICY_H
#define PROJEKT_IO_PRACOWNICY_H
#include "Pracownik.h"
#include "vector"
#include <iostream>
#include <OpenXLSX.hpp>
using namespace OpenXLSX;
class Pracownicy
{
private:
std::vector<Pracownik> pracownicy;
public:
    Pracownicy();
    ~Pracownicy();
    void dodaj_pracownika(std::string imie,std::string nazwisko,std::string login, std::string haslo,std::string funkcja,std::string mail);
    std::vector<Pracownik> get_worker();

    Pracownik create_pracownik(Pracownik& prac);
};
#endif //PROJEKT_IO_PRACOWNICY_H
