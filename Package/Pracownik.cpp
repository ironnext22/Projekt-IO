#include "../includes/Pracownik.h"
std::string Pracownik::get_imie(){return imie;}
std::string Pracownik::get_nazwisko(){return nazwisko;}
std::string Pracownik::get_mail() {return mail;}
std::string Pracownik::get_funkcja() {
    std::string fun;
    if(funkcja==Funkcje::Asystentka)fun="Asysystentka";
    if(funkcja==Funkcje::Dentysta)fun="Dentysta";
    if(funkcja==Funkcje::Administrator)fun="Administrator";
    if(funkcja==Funkcje::Error)fun="Error";
    return fun;
}
