#ifndef PROJEKT_IO_ASSISTANT_H
#define PROJEKT_IO_ASSISTANT_H
#include "Pracownik.h"
#include "Kalendarz.h"
#include "Finanse.h"
class Assistant:public Pracownik
{
Kalendarz kalendarz;
Finanse finanse;
public:
     Kalendarz get_kalendars();
     Assistant(std::string login,std::string haslo): Pracownik(login,haslo){}
     Finanse get_finanse();
};
#endif //PROJEKT_IO_ASSISTANT_H
