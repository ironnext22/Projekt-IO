#ifndef PROJEKT_IO_KALENDARZ_H
#define PROJEKT_IO_KALENDARZ_H
#include "Wizyta.h"
#include <vector>
#include <OpenXLSX.hpp>
using namespace OpenXLSX;
class Kalendarz
{
std::vector<Wizyta> wizyty;
public:
    Kalendarz();
    void dodal_wizyte(std::string imie, std::string nazwisko, std::string pesel, std::string data, std::string godzina);
    std::vector<Wizyta> get_wizyty();
    void set_data(std::string data,std::string pesel);
    void set_godzina(std::string godzina,std::string pesel);
    Pacjent find_pacjet(std::string pesel);
};
#endif //PROJEKT_IO_KALENDARZ_H
