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
std::vector<Pracownik> Pracownicy::get_worker()
{
    return pracownicy;
}