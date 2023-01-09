//
// Created by Mateusz on 09.01.2023.
//

#ifndef PROJEKT_IO_MAIL_H
#include <fstream>
#include <iostream>
#define PROJEKT_IO_MAIL_H

class Mail{
public:
    bool send_mail_with_verification_code(std::string address,std::string ver_code);
    bool send_mail_with_reminder();
};




#endif //PROJEKT_IO_MAIL_H
