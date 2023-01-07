#include "../includes/Pracownik.h"
std::string Pracownik::get_imie(){return imie;}
std::string Pracownik::get_nazwisko(){return nazwisko;}
std::string Pracownik::get_mail() {return mail;}
std::string Pracownik::get_login() {return login;}
std::string Pracownik::get_funkcja() {
    std::string fun;
    if(funkcja==Funkcje::Asystentka)fun="Asysystentka";
    if(funkcja==Funkcje::Dentysta)fun="Dentysta";
    if(funkcja==Funkcje::Administrator)fun="Administrator";
    if(funkcja==Funkcje::Error)fun="Error";
    return fun;
}
Pracownik::Pracownik(std::string login, std::string haslo)
{
    XLDocument doc;
    doc.open("loginy.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    bool br = false;
    int c1=0,c2 = 0;
    for(auto a : wks.rows())
    {
        c1++;
         for(auto b : a.cells())
         {
             c2++;
             if(c2==3)
             {
                if(static_cast<std::string>(b.value())==login)br= true;
                 break;
             }
         }
         if(br)break;
    }
    std::vector<std::string> v;
    for(auto a : wks.row(c1).cells())
    {
        v.push_back(static_cast<std::string>(a.value()));
    }
    this->imie = v[0];
    this->nazwisko = v[1];
    this->login = v[2];
    this->haslo = v[3];
    this->mail = v[5];
    if(v[4]=="Asystentka")this->funkcja=Funkcje::Asystentka;
    else if(v[4]=="Dentysta")this->funkcja=Funkcje::Dentysta;
    else if(v[4]=="Administrator")this->funkcja=Funkcje::Administrator;
    else this->funkcja=Funkcje::Error;
}
