#include "../includes/Kalendarz.h"
Kalendarz::Kalendarz()
{
    XLDocument doc;
    doc.open("wizyty.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> pom;
    for(auto& row : wks.rows())
    {
        for(auto& cell : row.cells())
        {
            pom.push_back(static_cast<std::string>(cell.value()));
        }
        auto* pomocnicza = new Wizyta;
        pomocnicza->set_pacjent(pom[0],pom[1],pom[2]);
        pomocnicza->set_data(pom[3]);
        pomocnicza->set_godzina(pom[4]);
        wizyty.push_back(*pomocnicza);
        delete pomocnicza;
        pom.clear();
    }
    doc.close();
}

void Kalendarz::dodal_wizyte(std::string imie, std::string nazwisko, std::string pesel, std::string data, std::string godzina)
{
    XLDocument doc;
    doc.open("wizyty.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    int count=wks.rowCount();
    wks.row(count+1).values() = std::vector<std::string>{imie,nazwisko,pesel,data,godzina};
    auto pom = new Wizyta;
    pom->set_pacjent(imie,nazwisko,pesel);
    pom->set_data(data);
    pom->set_godzina(godzina);
    delete pom;
    doc.save();
    doc.close();
}

std::vector<Wizyta> Kalendarz::get_wizyty()
{
    return wizyty;
}