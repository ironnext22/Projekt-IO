//
// Created by Mateusz on 06.01.2023.
//

#ifndef PROJEKT_IO_LOGING_H
#define PROJEKT_IO_LOGING_H
#include <iostream>
#endif //PROJEKT_IO_LOGING_H


class Loging{
private:
    bool check_if_email_is_in_data_base(std::string email_from_user);

    bool check_if_password_is_correct(std::string password);

    bool check_if_login_exists(std::string login);

    bool log_in(std::string login,std::string password);




public:

};



