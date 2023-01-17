#include "../includes/Magazyn.h"
Magazyn::Magazyn()
{
    XLDocument doc;
    doc.open("magazyn.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> pomocniczy;
    int count = 0;
    for(auto& row : wks.rows())
    {
        if(count==0)
        {
            count++;
            continue;
        }
        std::cout<<row.cellCount()<<std::endl;
        for(auto& cell : row.cells())
        {
            std::cout<<cell.value().typeAsString()<<" ";
            pomocniczy.push_back(cell.value().typeAsString());
        }
        Inwentarz *pom = new Inwentarz;
        pom->set_nazwa(pomocniczy[0]);
        pom->set_id(pomocniczy[1]);
        bool p = true;
        for (auto a: pomocniczy[2]) {
            if (!(a > 47 and a < 58))p = false;
        }
        if (p)pom->set_ilosc(pomocniczy[2]);
        else pom->set_ilosc("0");
        magazyn.push_back(*pom);
        delete pom;
        pomocniczy.clear();
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
        XLDocument doc;
        doc.open("magazyn.xlsx");
        auto wks = doc.workbook().worksheet("Sheet1");
        std::vector<std::string> v;
        int count=1;
        for(auto a : wks.rows())
        {
            for(auto b: a.cells())
            {
                v.push_back(static_cast<std::string>(b.value()));
            }
            if(v[1]==id)
            {
                break;
            }
            count++;
            v.clear();
        }
        v[2]=std::to_string(stoi(v[2])+stoi(ilosc));
        wks.row(count).values()=v;
        doc.save();
        doc.close();
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

void Magazyn::set_nazwa(std::string nazwa,std::string ID)
{
    XLDocument doc;
    doc.open("magazyn.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> v;
    int count=1;
    for(auto a : wks.rows())
    {
        for(auto b: a.cells())
        {
            v.push_back(static_cast<std::string>(b.value()));
        }
        if(v[1]==ID)
        {
            break;
        }
        count++;
        v.clear();
    }
    v[0]=nazwa;
    wks.row(count).values() = v;
    doc.save();
    doc.close();
}

void Magazyn::set_ilosc(std::string ilosc, std::string ID)
{
    XLDocument doc;
    doc.open("magazyn.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> v;
    int count=1;
    for(auto a : wks.rows())
    {
        for(auto b: a.cells())
        {
            v.push_back(static_cast<std::string>(b.value()));
        }
        if(v[1]==ID)
        {
            break;
        }
        count++;
        v.clear();
    }
    v[2]=ilosc;
    wks.row(count).values() = v;
    doc.save();
    doc.close();
}