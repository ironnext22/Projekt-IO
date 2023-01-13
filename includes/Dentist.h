#ifndef PROJEKT_IO_DENTIST_H
#define PROJEKT_IO_DENTIST_H
#include "Assistant.h"
class Dentist:public Assistant
{
public:
    Dentist(std::string login,std::string haslo): Assistant(login,haslo){}
};
#endif //PROJEKT_IO_DENTIST_H
