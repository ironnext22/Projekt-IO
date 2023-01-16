#ifndef PROJEKT_IO_WIZYTA_H
#define PROJEKT_IO_WIZYTA_H
#include <string>
#include "Pacjent.h"
class Wizyta
{
    Pacjent pacjent;
    std::string data;
    std::string godzina;
    std::string ID;
public:
    Pacjent get_pacjent();
    std::string get_data();
    std::string get_godzina();
    void set_pacjent(std::string imie,std::string nazwisko,std::string pesel,std::string mail);
    void set_data(std::string data);
    void set_godzina(std::string godzina);
    void set_ID(std::string ID);
};
#endif //PROJEKT_IO_WIZYTA_H
