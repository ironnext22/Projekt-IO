#ifndef PROJEKT_IO_PACJENT_H
#define PROJEKT_IO_PACJENT_H
#include <string>
#include "Osoba.h"
class Pacjent:public Osoba
{
    std::string pesel;
public:
    void set_imie(std::string imie);
    void set_nazwisko(std::string nazwisko);
    void set_pesel(std::string pesel);
    void set_mail(std::string mail);
    std::string get_imie();
    std::string get_nazwisko();
    std::string get_pesel();
};
#endif //PROJEKT_IO_PACJENT_H
