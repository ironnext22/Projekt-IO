//
// Created by Mateusz on 07.01.2023.
//

#ifndef PROJEKT_IO_TIME_APP_H
#include <iostream>
#include <chrono>
#include <ctime>
#define PROJEKT_IO_TIME_APP_H

class Time_app {
public:
    Time_app();
    std::string currentDateTime();
    std::string Yesterday();
};

#endif //PROJEKT_IO_TIME_APP_H
