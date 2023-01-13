//
// Created by Mateusz on 13.01.2023.
//

#ifndef PROJEKT_IO_FUNCTIONS_H
#include <iostream>
#define PROJEKT_IO_FUNCTIONS_H



struct Date2 {
    int day;
    int month;
    int year;
};

Date2 get_day_of_year(int dayOfYear, int year);

int lastMonday(int year);
int firstMonday(int year);





#endif //PROJEKT_IO_FUNCTIONS_H
