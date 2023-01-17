#ifndef PROJEKT_IO_HISTORIA_H
#define PROJEKT_IO_HISTORIA_H
#include <string>
class Historia
{
    std::string pesel;
    std::string tekst;
public:
    std::string get_tekst(){return tekst;}
    void dodaj_wizyte(std::string wizyta);
    void set_wizyta(std::string tekst){this->tekst=tekst;}
    void wczytaj_historie(std::string pesel,std::string tekst);
    std::string get_pesel(){return pesel;}
};
#endif //PROJEKT_IO_HISTORIA_H
