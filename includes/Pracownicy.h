#ifndef PROJEKT_IO_PRACOWNICY_H
#define PROJEKT_IO_PRACOWNICY_H
#include "Pracownik.h"
#include "vector"
#include <iostream>
#include <OpenXLSX.hpp>
using namespace OpenXLSX;
class Pracownicy
{
std::vector<Pracownik> pracownicy;
public:
    Pracownicy();
    ~Pracownicy();
};
#endif //PROJEKT_IO_PRACOWNICY_H
