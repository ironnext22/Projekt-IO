#include "../includes/Finanse.h"
Finanse::Finanse()
{
    XLDocument doc;
    doc.open("finanse.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> pomocniczy;
    for (auto& row : wks.rows())
    {
        for(auto& cell : row.cells())
        {
            pomocniczy.push_back(static_cast<std::string>((cell.value())));
        }
        Tranzakcja* pom = new Tranzakcja;
        pom->set_ID(pomocniczy[0]);
        pom->set_data(pomocniczy[1]);
        pom->set_kwota(pomocniczy[2]);
        finanse.push_back(*pom);
        pomocniczy.clear();
        delete pom;
    }
    doc.close();
}

void Finanse::aktualizuj_tranzakcje()
{
    XLDocument doc;
    doc.open("finanse.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> pomocniczy;
    for (auto& row : wks.rows())
    {
        for(auto& cell : row.cells())
        {
            pomocniczy.push_back(static_cast<std::string>((cell.value())));
        }
        Tranzakcja* pom = new Tranzakcja;
        pom->set_ID(pomocniczy[0]);
        pom->set_data(pomocniczy[1]);
        pom->set_kwota(pomocniczy[2]);
        finanse.push_back(*pom);
        pomocniczy.clear();
        delete pom;
    }
    doc.close();
}
void Finanse::dodaj_tranzakcje(std::string data, std::string kwota)
{
    XLDocument doc;
    doc.open("finanse.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    int count = 0;
    count=wks.rowCount();
    std::string ID = std::to_string(count+1);
    wks.row(count+1).values() = std::vector<std::string>{ID,data, kwota};
    Tranzakcja* pom = new Tranzakcja;
    pom->set_ID(ID);
    pom->set_data(data);
    pom->set_kwota(kwota);
    finanse.push_back(*pom);
    delete pom;
    doc.save();
    doc.close();
}
int Finanse::suma()
{
    int suma=0;
    std::vector<int> tab;
    for(auto a : finanse)
    {
        bool pom = true;
        for(auto b : a.get_kwota())
        {
            if(!(b>47 and b<58))pom= false;
        }
        if(pom==true)tab.push_back(stoi(a.get_kwota()));
    }
    for(auto a : tab)
    {
        suma+=a;
    }
    return suma;
}
std::vector<Tranzakcja> Finanse::get_tranzakcje() {return finanse;}