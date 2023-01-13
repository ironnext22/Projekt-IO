#ifndef PROJEKT_IO_ADMIN_H
#define PROJEKT_IO_ADMIN_H
#include "Dentist.h"
class Admin:public Dentist
{
public:
void set_function(std::string login,std::string funkcja);
Admin(std::string login,std::string haslo): Dentist(login,haslo){}
};
#endif //PROJEKT_IO_ADMIN_H
