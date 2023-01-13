#ifndef PROJEKT_IO_PACJENT_H
#define PROJEKT_IO_PACJENT_H
#include <string>
#include "../includes/Osoba.h"
class Pacjent:public Osoba
{
private:
    std::string pesel;
public:
    void set_pesel(std::string pesel){this->pesel=pesel;}
};
#endif //PROJEKT_IO_PACJENT_H
