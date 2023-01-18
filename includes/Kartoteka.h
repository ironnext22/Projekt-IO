#ifndef PROJEKT_IO_KARTOTEKA_H
#define PROJEKT_IO_KARTOTEKA_H
#include "Historia.h"
#include <vector>
#include <OpenXLSX.hpp>
using namespace OpenXLSX;
class Kartoteka
{
    std::vector<Historia> kartoteka;
public:
    Kartoteka();
    void dodaj_pacjeta(std::string pesel, std::string historia);
    Historia get_historia(std::string pesel);
    bool pacjent_exist(std::string pesel);
    Historia* find_pacjent(std::string pesel);
    std::vector<Historia> get_kartoteka(){return kartoteka;}
    void add_tekst(std::string pesel, std::string tekst);
};
#endif //PROJEKT_IO_KARTOTEKA_H
