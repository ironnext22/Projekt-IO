#ifndef PROJEKT_IO_TRANZAKCJA_H
#define PROJEKT_IO_TRANZAKCJA_H
#include <string>
class Tranzakcja
{
    std::string ID;
    std::string data;
    std::string kwota;
public:
    void set_ID(std::string ID){ this->ID=ID;};
    void set_data(std::string data){ this->data=data;};
    void set_kwota(std::string kowta){ this->kwota=kowta;};
    std::string get_data(){return data;};
    std::string get_ID(){return ID;};
    std::string get_kwota(){return kwota;};
};
#endif //PROJEKT_IO_TRANZAKCJA_H
