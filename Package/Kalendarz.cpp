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
        pomocnicza->set_pacjent(pom[0],pom[1],pom[2],pom[5]);
        pomocnicza->set_data(pom[3]);
        pomocnicza->set_godzina(pom[4]);
        pomocnicza->set_ID(pom[6]);
        wizyty.push_back(*pomocnicza);
        delete pomocnicza;
        pom.clear();
    }
    doc.close();
}

void Kalendarz::dodal_wizyte(std::string imie, std::string nazwisko, std::string pesel, std::string data, std::string godzina,std::string mail)
{
    XLDocument doc;
    doc.open("wizyty.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    int count=wks.rowCount();
    wks.row(count+1).values() = std::vector<std::string>{imie,nazwisko,pesel,data,godzina,mail,std::to_string(wks.rowCount()+1)};
    auto pom = new Wizyta;
    pom->set_pacjent(imie,nazwisko,pesel,mail);
    pom->set_data(data);
    pom->set_godzina(godzina);
    pom->set_ID(std::to_string(wks.rowCount()+1));
    delete pom;
    doc.save();
    doc.close();
}

std::vector<Wizyta> Kalendarz::get_wizyty()
{
    return wizyty;
}

void Kalendarz::set_data(std::string data,std::string ID)
{
    XLDocument doc;
    doc.open("wizyty.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> v;
    int count=1;
    for(auto a : wks.rows())
    {
        for(auto b: a.cells())
        {
            v.push_back(static_cast<std::string>(b.value()));
        }
        if(v[6]==ID)
        {
            break;
        }
        count++;
        v.clear();
    }
    v[3]=data;
    wks.row(count).values() = v;
    doc.save();
    doc.close();
}
void Kalendarz::set_godzina(std::string godzina,std::string ID)
{
    XLDocument doc;
    doc.open("wizyty.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> v;
    int count=1;
    for(auto a : wks.rows())
    {
        for(auto b: a.cells())
        {
            v.push_back(static_cast<std::string>(b.value()));
        }
        if(v[6]==ID)
        {
            break;
        }
        count++;
        v.clear();
    }
    v[4]=godzina;
    wks.row(count).values() = v;
    doc.save();
    doc.close();
}

Pacjent Kalendarz::find_pacjet(std::string pesel)
{
    Pacjent pom;
    for(auto a : wizyty)
    {
        if(a.get_pacjent().get_pesel()==pesel)pom=a.get_pacjent();
    }
    return pom;
}

bool Kalendarz::ID_is_in_data_base(std::string ID)
{
    bool pom=false;
    for(auto a : wizyty)
    {
        if(a.get_ID()==ID)pom= true;
    }
    return pom;
}