#ifndef PROJEKT_IO_PRACOWNICY_H
#define PROJEKT_IO_PRACOWNICY_H
#include "Pracownik.h"
#include "vector"
#include <iostream>
#include <OpenXLSX.hpp>
using namespace OpenXLSX;

enum class user_data_type{
    name = 1,
    surname = 2,
    mail = 3,
    password = 4,
    position = 5,
    login =6

};

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


    void set_attribute(user_data_type type,std::string user_login,std::string new_value);
    std::string get_login_with_mail(std::string mail);

};
#endif //PROJEKT_IO_PRACOWNICY_H
