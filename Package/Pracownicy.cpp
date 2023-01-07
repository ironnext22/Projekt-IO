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
Pracownicy::~Pracownicy()
{

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
void Pracownicy::zmien_haslo(std::string login, std::string nowe_haslo)
{
    XLDocument doc;
    doc.open("loginy.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    Pracownik* pom;
    int count = 0;
    for(auto a : pracownicy)
    {
        count++;
        if(a.login==login)
        {
            pom = &a;
        }
    }
    pom->haslo=nowe_haslo;
    std::vector<std::string> v;
    for(auto a : wks.row(count).cells())
    {
        v.push_back(static_cast<std::string>(a.value()));
    }
    v[3]=nowe_haslo;
    wks.row(count).values() = v;
    doc.save();
    doc.close();
}
void Pracownicy::zmien_imie(std::string login, std::string nowe_imie)
{
    XLDocument doc;
    doc.open("loginy.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    Pracownik* pom;
    int count = 0;
    for(auto a : pracownicy)
    {
        count++;
        if(a.login==login)
        {
            pom = &a;
        }
    }
    pom->imie=nowe_imie;
    std::vector<std::string> v;
    for(auto a : wks.row(count).cells())
    {
        v.push_back(static_cast<std::string>(a.value()));
    }
    v[0]=nowe_imie;
    wks.row(count).values() = v;
    doc.save();
    doc.close();
}
void Pracownicy::zmien_nazwisko(std::string login, std::string nowe_nazwisko)
{
    XLDocument doc;
    doc.open("loginy.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    Pracownik* pom;
    int count = 0;
    for(auto a : pracownicy)
    {
        count++;
        if(a.login==login)
        {
            pom = &a;
        }
    }
    pom->imie=nowe_nazwisko;
    std::vector<std::string> v;
    for(auto a : wks.row(count).cells())
    {
        v.push_back(static_cast<std::string>(a.value()));
    }
    v[1]=nowe_nazwisko;
    wks.row(count).values() = v;
    doc.save();
    doc.close();
}