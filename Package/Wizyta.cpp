#include "../includes/Wizyta.h"

Pacjent Wizyta::get_pacjent() {return pacjent;}

std::string Wizyta::get_data() {return data;}

std::string Wizyta::get_godzina() {return godzina;}

std::string Wizyta::get_ID() {return ID;}

void Wizyta::set_pacjent(std::string imie, std::string nazwisko, std::string pesel,std::string mail)
{
    pacjent.set_mail(mail);
    pacjent.set_name(imie);
    pacjent.set_surname(nazwisko);
    pacjent.set_pesel(pesel);
}

void Wizyta::set_data(std::string data) {this->data=data;}

void Wizyta::set_godzina(std::string godzina) {this->godzina=godzina;}

void Wizyta::set_ID(std::string ID) {this->ID=ID;}