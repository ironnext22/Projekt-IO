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
    void dodaj_do_magazynu(std::string nazwa,std::string id,std::string ilosc);
    std::vector<Inwentarz> get_magazyn();
    bool ID_Exist(std::string ID);
    void set_nazwa(std::string nazwa,std::string ID);
    void set_ilosc(std::string ilosc,std::string ID);
};


#endif //PROJEKT_IO_MAGAZYN_H
