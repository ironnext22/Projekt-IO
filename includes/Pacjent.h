#ifndef PROJEKT_IO_PACJENT_H
#define PROJEKT_IO_PACJENT_H
#include <string>
#include "Osoba.h"
class Pacjent:public Osoba
{
    std::string pesel;
public:
    void set_pesel(std::string pesel);
    std::string get_pesel();
};
#endif //PROJEKT_IO_PACJENT_H
