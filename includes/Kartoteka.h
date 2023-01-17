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
    bool pacjet_exist(std::string pesel);
    Historia* find_pacjet(std::string pesel);
};
#endif //PROJEKT_IO_KARTOTEKA_H
