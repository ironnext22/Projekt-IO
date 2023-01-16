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

std::string get_day_from_DMY_format(std::string DMY);
std::string get_month_from_DMY_format(std::string DMY);
std::string get_year_from_DMY_format(std::string DMY);

std::string get_hour_from_HM_format(std::string HM);
std::string get_minute_from_HM_format(std::string HM);

std::string get_nice_looking_DDMMYYYY_format(std::string input_from_the_input_bar);
std::string get_nice_looking_HHMM_format(std::string input_from_the_input_bar);



#endif //PROJEKT_IO_FUNCTIONS_H
