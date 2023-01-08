#include "../includes/Pracownik.h"
 std::string Pracownik::get_name() {return imie;}
 std::string Pracownik::get_surname() {return nazwisko;}
 std::string Pracownik::get_mail() {return mail;}
 std::string Pracownik::get_login() {return login;}
 std::string Pracownik::get_password() {return haslo;}
 std::string Pracownik::get_function() {
     std::string fun;
    if(funkcja==Funkcje::Asystentka)fun="Asysystentka";
    if(funkcja==Funkcje::Dentysta)fun="Dentysta";
    if(funkcja==Funkcje::Administrator)fun="Administrator";
    if(funkcja==Funkcje::No_function)fun="No Function";
    return fun;
}
Pracownik::Pracownik(std::string login, std::string haslo)
{
    XLDocument doc;
    doc.open("loginy.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> v;
    for(auto a : wks.rows())
    {
        for(auto b: a.cells())
        {
            v.push_back(static_cast<std::string>(b.value()));
        }
        if(v[2]==login and v[3]==haslo)break;
        v.clear();
    }
    this->imie = v[0];
    this->nazwisko = v[1];
    this->login = v[2];
    this->haslo = v[3];
    this->mail = v[5];
    if(v[4]=="Asystentka")this->funkcja=Funkcje::Asystentka;
    else if(v[4]=="Dentysta")this->funkcja=Funkcje::Dentysta;
    else if(v[4]=="Administrator")this->funkcja=Funkcje::Administrator;
    else this->funkcja=Funkcje::No_function;
}
void Pracownik::set_name(std::string imie)
{
    this->imie=imie;
    XLDocument doc;
    doc.open("loginy.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> v;
    int count=1;
    for(auto a : wks.rows())
    {
        for(auto b: a.cells())
        {
            v.push_back(static_cast<std::string>(b.value()));
        }
        if(v[2]==login and v[3]==haslo)
        {
            break;
        }
        count++;
        v.clear();
    }
    v[0]=imie;
    wks.row(count).values() = v;
    doc.save();
    doc.close();
}
void Pracownik::set_surname(std::string nazwisko)
{
    this->nazwisko=nazwisko;
    XLDocument doc;
    doc.open("loginy.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> v;
    int count=1;
    for(auto a : wks.rows())
    {
        for(auto b: a.cells())
        {
            v.push_back(static_cast<std::string>(b.value()));
        }
        if(v[2]==login and v[3]==haslo)
        {
            break;
        }
        count++;
        v.clear();
    }
    v[1]= this->nazwisko;
    wks.row(count).values() = v;
    doc.save();
    doc.close();
}
void Pracownik::set_mail(std::string mail)
{
    this->mail=mail;
    XLDocument doc;
    doc.open("loginy.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> v;
    int count=1;
    for(auto a : wks.rows())
    {
        for(auto b: a.cells())
        {
            v.push_back(static_cast<std::string>(b.value()));
        }
        if(v[2]==login and v[3]==haslo)
        {
            break;
        }
        count++;
        v.clear();
    }
    v[5]=this->mail;
    wks.row(count).values() = v;
    doc.save();
    doc.close();
}
void Pracownik::set_password(std::string haslo) {
    this->haslo=haslo;
    XLDocument doc;
    doc.open("loginy.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> v;
    int count=1;
    for(auto a : wks.rows())
    {
        for(auto b: a.cells())
        {
            v.push_back(static_cast<std::string>(b.value()));
        }
        if(v[2]==login)
        {
            break;
        }
        count++;
        v.clear();
    }
    v[3]=this->haslo;
    wks.row(count).values() = v;
    doc.save();
    doc.close();
}