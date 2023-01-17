#include "../includes/Kartoteka.h"
Kartoteka::Kartoteka()
{
    XLDocument doc;
    doc.open("historia.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> pomocniczy;
    for (auto& row : wks.rows())
    {
        for (auto &cell: row.cells())
        {
            pomocniczy.push_back(static_cast<std::string>(cell.value()));
        }
        Historia* pom = new Historia;
        pom->wczytaj_historie(pomocniczy[0],pomocniczy[1]);
        kartoteka.push_back(*pom);
        pomocniczy.clear();
        delete pom;
    }
    doc.close();
}
void Kartoteka::dodaj_pacjeta(std::string pesel, std::string historia)
{
    if(!pacjet_exist(pesel))
    {
        XLDocument doc;
        doc.open("historia.xlsx");
        auto wks = doc.workbook().worksheet("Sheet1");
        int count = wks.rowCount();
        std::string ID = std::to_string(count + 1);
        wks.row(count + 1).values() = std::vector<std::string>{pesel, historia};
        Historia *pom = new Historia;
        pom->wczytaj_historie(pesel, historia);
        kartoteka.push_back(*pom);
        delete pom;
        doc.save();
        doc.close();
    }
    else
    {
        find_pacjet(pesel)->dodaj_wizyte(historia);
    }
}
bool Kartoteka::pacjet_exist(std::string pesel)
{
    bool pom= false;
    XLDocument doc;
    doc.open("historia.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> pomocnicza;
    for(auto x : wks.rows())
    {
        for(auto y : x.cells())
        {
            pomocnicza.push_back(static_cast<std::string>(y.value()));
        }
        if(pomocnicza[0]==pesel)
        {
            pom = true;
            pomocnicza.clear();
            break;
        }
        pomocnicza.clear();
    }
    return pom;
}

Historia *Kartoteka::find_pacjet(std::string pesel)
{
    Historia* x = new Historia;
    int count=0;
    for(auto a : kartoteka)
    {
        if(a.get_pesel()==pesel)
        {
            break;
        }
        count++;
    }
    x=&kartoteka[count];
    return x;
}