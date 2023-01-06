#ifndef PROJEKT_IO_PRACOWNIK_H
#define PROJEKT_IO_PRACOWNIK_H
#include <string>
#include "Osoba.h"
enum class Funkcje {Asystentka,Dentysta,Administrator};
class Pracownik:public Osoba
{
    std::string login;
    std::string haslo;
    Funkcje funkcja;
public:
    Pracownik(std::string imie,std::string nazwisko,std::string login, std::string haslo, Funkcje fuckacja)
    {
        this->imie=imie;
        this->nazwisko=nazwisko;
        this->login=login;
        this->haslo=haslo;
        this->funkcja=fuckacja;
    }
};
#endif //PROJEKT_IO_PRACOWNIK_H
