#include "../includes/Pacjeci.h"
Pacjeci::Pacjeci()
{
    XLDocument doc;
    doc.open("pacjeci.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> pomm;
    for(auto& row : wks.rows())
    {
        for(auto& cell : row.cells())
        {
            pomm.push_back(static_cast<std::string>(cell.value()));
        }
        auto* pom = new Pacjent;
        pom->set_name(pomm[0]);
        pom->set_surname(pomm[1]);
        pom->set_pesel(pomm[2]);
        pom->set_mail(pomm[3]);
        pacjęci.push_back(*pom);
        delete pom;
        pomm.clear();
    }
    doc.close();
}

std::vector<Pacjent> Pacjeci::get_pacjeci() {return pacjęci;}

void Pacjeci::dodaj_pacjęt(std::string imie, std::string nazwisko, std::string pesel, std::string email)
{
    if(pacjet_exist(pesel))return;
    XLDocument doc;
    doc.open("pacjeci.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    int count=wks.rowCount();
    wks.row(count+1).values() = std::vector<std::string>{imie,nazwisko,pesel,email};
    auto pom = new Pacjent;
    pom->set_name(imie);
    pom->set_surname(nazwisko);
    pom->set_pesel(pesel);
    pom->set_mail(email);
    delete pom;
    doc.save();
    doc.close();
}

bool Pacjeci::pacjet_exist(std::string pesel)
{
    bool pom= false;
    XLDocument doc;
    doc.open("pacjeci.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> pomocnicza;
    for(auto x : wks.rows())
    {
        for(auto y : x.cells())
        {
            pomocnicza.push_back(static_cast<std::string>(y.value()));
        }
        if(pomocnicza[2]==pesel)
        {
            pom = true;
            pomocnicza.clear();
            break;
        }
        pomocnicza.clear();
    }
    return pom;
}