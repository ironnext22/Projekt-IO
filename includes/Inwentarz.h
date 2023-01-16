#ifndef PROJEKT_IO_INWENTARZ_H
#define PROJEKT_IO_INWENTARZ_H
#include <string>
enum class Zapas{Brak=0,Brakuje=1,Wystarczajaco=2,Full=3,Error=8};
class Inwentarz{
    std::string nazwa;
    std::string id;
    int ilosc;
    Zapas stan;
public:
    void set_nazwa(std::string nazwa);
    void set_id(std::string id);
    void set_ilosc(std::string ilosc);
    void set_stan(std::string stan);
};


#endif //PROJEKT_IO_INWENTARZ_H
