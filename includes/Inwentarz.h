#ifndef PROJEKT_IO_INWENTARZ_H
#define PROJEKT_IO_INWENTARZ_H
#include <string>
class Inwentarz{
    std::string nazwa;
    std::string id;
    std::string ilosc;
public:
    void set_nazwa(std::string nazwa){ this->nazwa=nazwa;};
    void set_id(std::string id){ this->id=id;};
    void set_ilosc(std::string ilosc){ this->ilosc=ilosc;};
    std::string get_nazwa(){return nazwa;}
    std::string get_ID(){return id;};
    std::string get_ilosc(){return ilosc;}
};


#endif //PROJEKT_IO_INWENTARZ_H
