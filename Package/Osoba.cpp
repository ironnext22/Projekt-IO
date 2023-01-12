#include "../includes/Osoba.h"
std::string Osoba::get_name() {return imie;}
std::string Osoba::get_surname() {return nazwisko;}
std::string Osoba::get_mail() {return mail;}

void Osoba::set_name(std::string name) {this->imie=name;}

void Osoba::set_surname(std::string surname) {this->nazwisko=surname;}

void Osoba::set_mail(std::string mail) {this->mail=mail;}