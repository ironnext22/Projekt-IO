//
// Created by Mateusz on 16.01.2023.
//

#ifndef PROJEKT_IO_MONEY_SAFE_H
#include <string>


#define PROJEKT_IO_MONEY_SAFE_H

/// trzeba dodac plik money.xlsx w ktory mbedzie historia platnosci tzn:
/// 1. kolumna wplata , 2. kolumna ID wizyty za ktora jest ta wplata , 3. Data wizyty
/// getmoney - funkcja ktora podliczy cala money z bazki

void add_money(std::string money, std::string ID,std::string Data); // to do
std::string get_money(); // to do

#endif //PROJEKT_IO_MONEY_SAFE_H
