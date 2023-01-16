#ifndef PROJEKT_IO_PACJECI_H
#define PROJEKT_IO_PACJECI_H
#include "Pacjent.h"
#include <vector>
#include <OpenXLSX.hpp>
using namespace OpenXLSX;
class Pacjeci
{
    std::vector<Pacjent> pacjęci;
public:
    Pacjeci();
    void dodaj_pacjęt(std::string imie,std::string nazwisko,std::string pesel,std::string email);
    std::vector<Pacjent> get_pacjeci();
};
#endif //PROJEKT_IO_PACJECI_H
