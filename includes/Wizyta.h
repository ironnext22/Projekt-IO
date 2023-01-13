#ifndef PROJEKT_IO_WIZYTA_H
#define PROJEKT_IO_WIZYTA_H
#include <string>
#include "Pacjent.h"
class Wizyta
{
    Pacjent pacjent;
    std::string data;
    std::string godzina;
public:
    Pacjent get_pacjent();
    std::string get_data(); // 20.01.2022
    std::string get_godzina(); // format 16.1
    void set_pacjent(std::string imie,std::string nazwisko,std::string pesel);
    void set_data(std::string data);
    void set_godzina(std::string godzina);
};
#endif //PROJEKT_IO_WIZYTA_H
