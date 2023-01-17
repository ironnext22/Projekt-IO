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
    void dodaj_tranzakcje(std::string data,std::string kwota);
    void aktualizuj_tranzakcje();
    int suma();
    std::vector<Tranzakcja> get_tranzakcje();
};
#endif //PROJEKT_IO_FINANSE_H
