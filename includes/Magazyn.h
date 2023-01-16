#ifndef PROJEKT_IO_MAGAZYN_H
#define PROJEKT_IO_MAGAZYN_H
#include "Inwentarz.h"
#include <vector>
class Magazyn {
    std::vector<Inwentarz> magazyn;
public:
    Magazyn();
    void dodaj_do_magazynu();
};


#endif //PROJEKT_IO_MAGAZYN_H
