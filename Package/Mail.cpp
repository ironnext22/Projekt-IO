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

bool Mail::send_mail_with_reminder(std::string current_data, std::string data, std::string mail)
{
    if(data==current_data)
    {
        std::ofstream dat;
        dat.open("data.txt");
        if (dat.is_open()) {
            dat << data;
            dat.close();
        }
        std::ofstream m;
        m.open("mail2.txt");
        if (m.is_open()) {
            m << mail;
            m.close();
        } else { return false; }
        int rezultat1 = system("start /b mail2.exe");
    }
}

