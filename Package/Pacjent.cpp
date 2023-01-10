#include "../includes/Pacjent.h"

std::string Pacjent::get_imie() {return imie;}
std::string Pacjent::get_nazwisko() {return nazwisko;}
std::string Pacjent::get_pesel() {return pesel;}
void Pacjent::set_imie(std::string imie) { this->imie=imie;}
void Pacjent::set_nazwisko(std::string nazwisko) { this->nazwisko=nazwisko;}
void Pacjent::set_pesel(std::string pesel) { this->pesel=pesel;}