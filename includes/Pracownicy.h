#ifndef PROJEKT_IO_PRACOWNICY_H
#define PROJEKT_IO_PRACOWNICY_H
#include "Pracownik.h"
#include "vector"
#include <iostream>
#include <OpenXLSX.hpp>
using namespace OpenXLSX;
class Pracownicy
{
public:
std::vector<Pracownik> pracownicy;
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
    void zmien_haslo(std::string login,std::string nowe_haslo);
    void zmien_imie(std::string login,std::string nowe_imie);
    void zmien_nazwisko(std::string login,std::string nowe_nazwisko);
};
#endif //PROJEKT_IO_PRACOWNICY_H
