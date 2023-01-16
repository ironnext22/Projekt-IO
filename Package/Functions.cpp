//
// Created by Mateusz on 13.01.2023.
//
#include "../includes/Functions.h"
#include <string>
#include <iostream>


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
#include <string>
std::string get_nice_looking_DDMMYYYY_format(std::string input_from_the_input_bar){
    std::string newstr,str2;
    if(input_from_the_input_bar == ""){return "DD.MM.YYYY";}

    else if(input_from_the_input_bar.length() == 1){
        str2 = input_from_the_input_bar[0];
        newstr.append(str2);
        newstr.append("D.MM.YYYY");
        return newstr;
    }
    else if (input_from_the_input_bar.length() == 2){
        str2 = input_from_the_input_bar[0];
        newstr.append(str2);
        str2 = input_from_the_input_bar[1];
        newstr.append(str2);
        newstr.append(".MM.YYYY");
        return newstr;
    }

    else if (input_from_the_input_bar.length() == 3){
        str2 = input_from_the_input_bar[0];
        newstr.append(str2);
        str2 = input_from_the_input_bar[1];
        newstr.append(str2);
        newstr.append(".");
        str2 = input_from_the_input_bar[2];
        newstr.append(str2);
        newstr.append("M.YYYY");
        return newstr;
    }
    else if (input_from_the_input_bar.length() == 4){
        str2 = input_from_the_input_bar[0];
        newstr.append(str2);
        str2 = input_from_the_input_bar[1];
        newstr.append(str2);
        newstr.append(".");
        str2 = input_from_the_input_bar[2];
        newstr.append(str2);
        str2 = input_from_the_input_bar[3];
        newstr.append(str2);
        newstr.append(".YYYY");
        return newstr;
    }
    else if (input_from_the_input_bar.length() == 5){
        str2 = input_from_the_input_bar[0];
        newstr.append(str2);
        str2 = input_from_the_input_bar[1];
        newstr.append(str2);
        newstr.append(".");
        str2 = input_from_the_input_bar[2];
        newstr.append(str2);
        str2 = input_from_the_input_bar[3];
        newstr.append(str2);
        newstr.append(".");
        str2 = input_from_the_input_bar[4];
        newstr.append(str2);
        newstr.append("YYY");

        return newstr;

    }

    else if (input_from_the_input_bar.length() == 6){
        str2 = input_from_the_input_bar[0];
        newstr.append(str2);
        str2 = input_from_the_input_bar[1];
        newstr.append(str2);
        newstr.append(".");
        str2 = input_from_the_input_bar[2];
        newstr.append(str2);
        str2 = input_from_the_input_bar[3];
        newstr.append(str2);
        newstr.append(".");
        str2 = input_from_the_input_bar[4];
        newstr.append(str2);
        str2 = input_from_the_input_bar[5];
        newstr.append(str2);
        newstr.append("YY");
        return newstr;


    }
    else if (input_from_the_input_bar.length() == 7){
        str2 = input_from_the_input_bar[0];
        newstr.append(str2);
        str2 = input_from_the_input_bar[1];
        newstr.append(str2);
        newstr.append(".");
        str2 = input_from_the_input_bar[2];
        newstr.append(str2);
        str2 = input_from_the_input_bar[3];
        newstr.append(str2);
        newstr.append(".");
        str2 = input_from_the_input_bar[4];
        newstr.append(str2);
        str2 = input_from_the_input_bar[5];
        newstr.append(str2);
        str2 = input_from_the_input_bar[6];
        newstr.append(str2);
        newstr.append("Y");

        return newstr;


    }
    else if (input_from_the_input_bar.length() == 8){
        str2 = input_from_the_input_bar[0];
        newstr.append(str2);
        str2 = input_from_the_input_bar[1];
        newstr.append(str2);
        newstr.append(".");
        str2 = input_from_the_input_bar[2];
        newstr.append(str2);
        str2 = input_from_the_input_bar[3];
        newstr.append(str2);
        newstr.append(".");
        str2 = input_from_the_input_bar[4];
        newstr.append(str2);
        str2 = input_from_the_input_bar[5];
        newstr.append(str2);
        str2 = input_from_the_input_bar[6];
        newstr.append(str2);
        str2 = input_from_the_input_bar[7];
        newstr.append(str2);

        return newstr;

    }
    else return "";
}

std::string get_nice_looking_HHMM_format(std::string input_from_the_input_bar){

    std::string newstr ="",str2;
    if(input_from_the_input_bar == ""){return "HH.MM";}

    else if(input_from_the_input_bar.length() == 1){
        str2 = input_from_the_input_bar[0];
        newstr.append(str2);
        newstr.append("H.MM");
        return newstr;
    }
    else if (input_from_the_input_bar.length() == 2){
        str2 = input_from_the_input_bar[0];
        newstr.append(str2);
        str2 = input_from_the_input_bar[1];
        newstr.append(str2);
        newstr.append(".MM");
        return newstr;
    }

    else if (input_from_the_input_bar.length() == 3){
        str2 = input_from_the_input_bar[0];
        newstr.append(str2);
        str2 = input_from_the_input_bar[1];
        newstr.append(str2);
        newstr.append(".");
        str2 = input_from_the_input_bar[2];
        newstr.append(str2);
        newstr.append("M");
        return newstr;
    }
    else if (input_from_the_input_bar.length() == 4){
        str2 = input_from_the_input_bar[0];
        newstr.append(str2);
        str2 = input_from_the_input_bar[1];
        newstr.append(str2);
        newstr.append(".");
        str2 = input_from_the_input_bar[2];
        newstr.append(str2);
        str2 = input_from_the_input_bar[3];
        newstr.append(str2);
        return newstr;
    }

}

