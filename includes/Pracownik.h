#ifndef PROJEKT_IO_PRACOWNIK_H
#define PROJEKT_IO_PRACOWNIK_H
#include <string>
#include "Osoba.h"
enum class Funkcje {Asystentka=0,Dentysta=1,Administrator=2,Error=3};
class Pracownik:public Osoba
{
public:
    std::string login;
    std::string haslo;
    Funkcje funkcja;
public:
    Pracownik(std::string imie,std::string nazwisko,std::string login, std::string haslo,std::string funkcja,std::string mail)
    {
        this->imie=imie;
        this->nazwisko=nazwisko;
        this->login=login;
        this->mail=mail;
        this->haslo=haslo;
            if(funkcja=="Asystentka")this->funkcja=Funkcje::Asystentka;
            else if(funkcja=="Dentysta")this->funkcja=Funkcje::Dentysta;
            else if(funkcja=="Administrator")this->funkcja=Funkcje::Administrator;
            else this->funkcja=Funkcje::Error;
    }
    std::string get_imie();
    std::string get_nazwisko();
    std::string get_mail();
    std::string get_funkcja();
};
#endif //PROJEKT_IO_PRACOWNIK_H
