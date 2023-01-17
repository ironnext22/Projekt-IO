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
    void dodal_wizyte(std::string imie, std::string nazwisko, std::string pesel, std::string data, std::string godzina,std::string mail);
    std::vector<Wizyta> get_wizyty();
    void set_data(std::string data,std::string ID);
    void set_godzina(std::string godzina,std::string ID);
    Pacjent find_pacjet(std::string pesel);
    bool ID_is_in_data_base(std::string ID);
    void reload();
};
#endif //PROJEKT_IO_KALENDARZ_H
