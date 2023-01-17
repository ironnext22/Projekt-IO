#include "../includes/Historia.h"

void Historia::dodaj_wizyte(std::string wizyta)
{
    this->tekst= tekst + "\n" +wizyta;
}

void Historia::wczytaj_historie(std::string pesel, std::string tekst)
{
    this->pesel=pesel;
    this->tekst=tekst;
}