#ifndef PROJEKT_IO_OSOBA_H
#define PROJEKT_IO_OSOBA_H
#include <string>
class Osoba
{
protected:
    std::string imie;
    std::string nazwisko;
    std::string mail;
public:
    std::string get_name();
    std::string get_surname();
    std::string get_mail();
    void set_name(std::string name);
    void set_surname(std::string surname);
    void set_mail(std::string mail);
};
#endif //PROJEKT_IO_OSOBA_H
