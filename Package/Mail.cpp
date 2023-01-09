//
// Created by Mateusz on 09.01.2023.
//

#include "../includes/Mail.h"


    bool Mail::send_mail_with_verification_code(std::string address,std::string ver_code){
        std::ofstream kod;
        std::ofstream mail;
        kod.open("kod.txt");
        mail.open("mail.txt");

        if(kod.is_open())
        {
            kod<<ver_code;
            kod.close();
        }
        else{return false;}

        if(mail.is_open())
        {
            mail<<address;
            mail.close();
        }
        else{return false;}

        int rezultat1=system("start /b mail1.exe");

    }

