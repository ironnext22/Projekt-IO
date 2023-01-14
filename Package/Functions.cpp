//
// Created by Mateusz on 13.01.2023.
//
#include "../includes/Functions.h"
#include <string>


Date2 get_day_of_year(int dayOfYear, int year) {
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        monthDays[1] = 29;
    }
    int month = 0;
    while (dayOfYear > monthDays[month]) {
        dayOfYear -= monthDays[month];
        month++;
    }
    return {dayOfYear, month + 1, year};
}


#include <ctime>
using namespace std;

// Function to find the day number of the first Monday of the year
int firstMonday(int year) {
    tm first_day = { 0, 0, 0, 1, 0, year - 1900 };
    time_t first_day_timestamp = mktime(&first_day);
    tm* ptm = localtime(&first_day_timestamp);
    int day_count = 0;

    while (ptm->tm_wday != 1) {
        first_day_timestamp += 24 * 60 * 60;
        ptm = localtime(&first_day_timestamp);
        day_count++;
    }
    return day_count+1;
}

// Function to find the day number of the last Monday of the year
int lastMonday(int year) {
    tm last_day = { 0, 0, 0, 31, 11, year - 1900 };
    time_t last_day_timestamp = mktime(&last_day);
    tm* ptm = localtime(&last_day_timestamp);
    int day_count = 365;

    while (ptm->tm_wday != 1) {
        last_day_timestamp -= 24 * 60 * 60;
        ptm = localtime(&last_day_timestamp);
        day_count--;
    }
    return day_count;
}

std::string get_day_from_DMY_format(std::string DMY){
    if(DMY == ""){return "";}
    std::cout<<DMY.substr(0,2) <<"/";
    return DMY.substr(0,2);
}
std::string get_month_from_DMY_format(std::string DMY){
    if(DMY == ""){return "";}
    std::cout<<DMY.substr(3,2) <<"/";
    return DMY.substr(3,2);

}
std::string get_year_from_DMY_format(std::string DMY){
    if(DMY == ""){return "";}
    std::cout<<DMY.substr(6,4) <<"/";
    return DMY.substr(6,4);

}

std::string get_hour_from_HM_format(std::string HM){
    if(HM == ""){return "";}
    return HM.substr(0,2);

}
std::string get_minute_from_HM_format(std::string HM){
    if(HM == ""){return "";}
  //  return HM.substr(3-4);

}