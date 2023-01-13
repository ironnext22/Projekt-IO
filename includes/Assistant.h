#ifndef PROJEKT_IO_ASSISTANT_H
#define PROJEKT_IO_ASSISTANT_H
#include "Pracownik.h"
#include "Kalendarz.h"
class Assistant:public Pracownik
{
Kalendarz kalendarz;
public:
     Kalendarz get_kalendars();
     Assistant(std::string login,std::string haslo): Pracownik(login,haslo){}
};
#endif //PROJEKT_IO_ASSISTANT_H
