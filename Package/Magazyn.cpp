#include "../includes/Magazyn.h"
Magazyn::Magazyn()
{
    XLDocument doc;
    doc.create("magazyn.xlsx");
    doc.close();
}