#include "../includes/Pracownicy.h"
Pracownicy::Pracownicy() {
    XLDocument doc;
    doc.open("loginy.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> pomocniczy;
    for (auto& row : wks.rows())
    {
        for(auto& cell : row.cells())
        {
            pomocniczy.push_back(static_cast<std::string>((cell.value())));
        }
        Pracownik* pom = new Pracownik(pomocniczy[0],pomocniczy[1],pomocniczy[2],pomocniczy[3],pomocniczy[4],pomocniczy[5]);
        pracownicy.push_back(*pom);
        pomocniczy.clear();
        delete pom;
    }
    doc.close();
}

void Pracownicy::reload()
{
    pracownicy.clear();
    XLDocument doc;
    doc.open("loginy.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> pomocniczy;
    for (auto& row : wks.rows())
    {
        for(auto& cell : row.cells())
        {
            pomocniczy.push_back(static_cast<std::string>((cell.value())));
        }
        Pracownik* pom = new Pracownik(pomocniczy[0],pomocniczy[1],pomocniczy[2],pomocniczy[3],pomocniczy[4],pomocniczy[5]);
        pracownicy.push_back(*pom);
        pomocniczy.clear();
        delete pom;
    }
    doc.close();
}
void Pracownicy::dodaj_pracownika(std::string imie,std::string nazwisko,std::string login, std::string haslo,std::string funkcja,std::string mail)
{
    XLDocument doc;
    doc.open("loginy.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    int count = 0;
    count=wks.rowCount();
    wks.row(count+1).values() = std::vector<std::string>{imie,nazwisko,login,haslo,funkcja,mail};
    Pracownik* pom = new Pracownik(imie,nazwisko,login,haslo,funkcja,mail);
    pracownicy.push_back(*pom);
    delete pom;
    doc.save();
    doc.close();
}
std::vector<Pracownik> Pracownicy::get_worker()
{
    return pracownicy;
}

std::string Pracownicy::get_login_with_mail(std::string mail){
    std::string login;
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
        if(v[5]==mail)
        {
            break;
        }
        count++;
        v.clear();
    }
    login = v[2];
    wks.row(count).values() = v;
    doc.save();
    doc.close();
    return login;

}

void Pracownicy::set_attribute(user_data_type type,std::string user_login,std::string new_value){

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
        if(v[2]==user_login)
        {
            break;
        }
        count++;
        v.clear();
    }
    switch(type){
        case user_data_type::name:{
            v[0]=new_value;
            pracownicy[count-1].set_name(new_value);
            break;
        }
        case user_data_type::surname:{
            v[1]=new_value;
            pracownicy[count-1].set_surname(new_value);
            break;
        }
        case user_data_type::login:{
            v[2]=new_value;
            pracownicy[count-1].set_login(new_value);
            break;
        }
        case user_data_type::password:{
            v[3]=new_value;
            pracownicy[count-1].set_password(new_value);
            break;
        }
        case user_data_type::mail:{
            v[5]=new_value;
            pracownicy[count-1].set_mail(new_value);
            break;
        }
        case user_data_type::position:{ ///Asystentka=0,Dentysta=1,Administrator=2,No_function=3
            if(new_value == "0"){
                v[4]="Asystentka";
            }
            else if(new_value == "1"){
                v[4]="Dentysta";
            }
            else if(new_value == "2"){
                v[4]="Administrator";
            }
            else {
                v[4]="No_function";
            }

            break;
        }
    }
    wks.row(count).values() = v;
    doc.save();
    doc.close();

}