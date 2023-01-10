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
    void set_imie();
    void set_nazwisko();
    void set_pesel();
    void set_data();
    void set_godzina();
};
#endif //PROJEKT_IO_KALENDARZ_H
