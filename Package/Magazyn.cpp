#include "../includes/Magazyn.h"
Magazyn::Magazyn()
{
    XLDocument doc;
    doc.open("magazyn.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> pomocniczy;
    for (auto& row : wks.rows())
    {
        for(auto& cell : row.cells())
        {
            pomocniczy.push_back(static_cast<std::string>((cell.value())));
        }
        Inwentarz* pom = new Inwentarz;
        pom->set_nazwa(pomocniczy[0]);
        pom->set_id(pomocniczy[1]);
        pom->set_ilosc(pomocniczy[2]);
        magazyn.push_back(*pom);
        pomocniczy.clear();
        delete pom;
    }
    doc.close();
}

std::vector<Inwentarz> Magazyn::get_magazyn() {return magazyn;}
void Magazyn::dodaj_do_magazynu(std::string nazwa,std::string id,std::string ilosc)
{
    if(ID_Exist(id))
    {
        for(auto a : magazyn)
        {
            if(a.get_ID()==id)a.set_ilosc(ilosc);
        }
    }
    else
    {
        XLDocument doc;
        doc.open("magazyn.xlsx");
        auto wks = doc.workbook().worksheet("Sheet1");
        int count = 0;
        count=wks.rowCount();
        wks.row(count+1).values() = std::vector<std::string>{nazwa,id,ilosc};
        Inwentarz* pom = new Inwentarz;
        pom->set_nazwa(nazwa);
        pom->set_id(id);
        pom->set_ilosc(ilosc);
        magazyn.push_back(*pom);
        delete pom;
        doc.save();
        doc.close();

    }
}

bool Magazyn::ID_Exist(std::string ID)
{
    bool pom = false;
    for(auto a : magazyn)
    {
        if(a.get_ID()==ID)pom=true;
    }
    return pom;
}