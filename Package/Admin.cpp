#include "../includes/Admin.h"
void Admin::set_function(std::string login,std::string funkcja)
{
    XLDocument doc;
    doc.open("loginy.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");
    std::vector<std::string> v;
    int count=1;
    for(auto a : wks.rows())
    {
        for(auto b: a.cells())
        {
            v.push_back(static_cast<std::string>(b.value()));
        }
        if(v[2]==login)
        {
            break;
        }
        count++;
        v.clear();
    }
    v[4]= funkcja;
    wks.row(count).values() = v;
    doc.save();
    doc.close();
}