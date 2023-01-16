#ifndef PROJEKT_IO_FINANSE_H
#define PROJEKT_IO_FINANSE_H
#include "Tranzakcja.h"
#include <vector>
#include <OpenXLSX.hpp>
using namespace OpenXLSX;
class Finanse
{
    std::vector<Tranzakcja> finanse;
public:
    Finanse();
    void dodaj_tranzakcje(std::string ID,std::string nazwa,std::string kwota);
    int suma();
    std::vector<Tranzakcja> get_tranzakcje();
};
#endif //PROJEKT_IO_FINANSE_H
