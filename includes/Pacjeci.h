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
    void dodaj_pacjent(std::string imie, std::string nazwisko, std::string pesel, std::string email);
    std::vector<Pacjent> get_pacjeci();
    bool pacjent_exist(std::string pesel);
};
#endif //PROJEKT_IO_PACJECI_H
