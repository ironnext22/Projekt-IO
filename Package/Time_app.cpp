//
// Created by Mateusz on 07.01.2023.
//
#include "../includes/Time_app.h"



std::string Time_app::currentDateTime() {

    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::string new_string = std::ctime(&end_time);
    return new_string;
};

Time_app::Time_app() {

}

std::string Time_app::Yesterday()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    rawtime += 86400; // adding 86400 seconds (1 day)
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d.%m.%Y",timeinfo);
    std::string str(buffer);

    return str;
}