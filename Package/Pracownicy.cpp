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
        Pracownik* pom = new Pracownik(pomocniczy[0],pomocniczy[1],pomocniczy[2],pomocniczy[3],pomocniczy[4]);
        pracownicy.push_back(*pom);
        pomocniczy.clear();
        delete pom;
    }
    doc.close();
}
Pracownicy::~Pracownicy()
{

}
void Pracownicy::dodaj_pracownika(std::string imie,std::string nazwisko,std::string login, std::string haslo,std::string funkcja)
{
    XLDocument doc;
    doc.open("loginy.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    int count = 0;
    count=wks.rowCount();
    wks.row(count+1).values() = std::vector<std::string>{imie,nazwisko,login,haslo,funkcja};
    Pracownik* pom = new Pracownik(imie,nazwisko,login,haslo,funkcja);
    pracownicy.push_back(*pom);
    delete pom;
    doc.save();
    doc.close();
}