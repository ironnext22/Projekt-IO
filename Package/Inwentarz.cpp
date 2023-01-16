#include "../includes/Inwentarz.h"

void Inwentarz::set_nazwa(std::string nazwa) {this->nazwa=nazwa;}
void Inwentarz::set_id(std::string id) {this->id=id;}
void Inwentarz::set_ilosc(std::string ilosc) {this->ilosc= std::stoi(ilosc);}
void Inwentarz::set_stan(std::string stan)
{
if(stan=="Brak")this->stan=Zapas::Brak;
else if(stan=="Brakuje")this->stan=Zapas::Brakuje;
else if(stan=="Wystarczajaco")this->stan=Zapas::Wystarczajaco;
else if(stan=="Full")this->stan=Zapas::Full;
else this->stan==Zapas::Error;
}