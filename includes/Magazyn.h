#ifndef PROJEKT_IO_MAGAZYN_H
#define PROJEKT_IO_MAGAZYN_H
#include "Inwentarz.h"
#include <vector>
#include <OpenXLSX.hpp>
using namespace OpenXLSX;
class Magazyn {
    std::vector<Inwentarz> magazyn;
public:
    Magazyn();
    void dodaj_do_magazynu();
};


#endif //PROJEKT_IO_MAGAZYN_H
