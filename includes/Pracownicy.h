#ifndef PROJEKT_IO_PRACOWNICY_H
#define PROJEKT_IO_PRACOWNICY_H
#include "Pracownik.h"
#include "vector"
#include <iostream>
#include <OpenXLSX.hpp>
using namespace OpenXLSX;
class Pracownicy
{
std::vector<Pracownik> pracownicy;
public:
    Pracownicy();
    ~Pracownicy();
    void disp()
    {
        for(auto a : pracownicy)
        {
            std::cout<<a.imie<<" "<<a.nazwisko<<" "<<a.login<<" "<<a.haslo<<" "<<static_cast<int>(a.funkcja)<<" "<<a.mail<<std::endl;
        }
    }
    void dodaj_pracownika(std::string imie,std::string nazwisko,std::string login, std::string haslo,std::string funkcja,std::string mail);
};
#endif //PROJEKT_IO_PRACOWNICY_H
