#include "../includes/Loging.h"

bool Loging::check_if_email_is_in_data_base(std::string email_from_user)
{
    for(auto a : login_list.pracownicy)
    {
        if(a.mail==email_from_user)return true;
    }
    return false;
}
bool Loging::check_if_login_exists(std::string login)
{
    for(auto a : login_list.pracownicy)
    {
        if(a.login==login)return true;
    }
    return false;
}
bool Loging::check_if_password_is_correct(std::string login,std::string password)
{
    if(!check_if_login_exists(login))return false;
    Pracownik* konto;
    for(auto a : login_list.pracownicy)
    {
        if(a.login==login)konto = &a;
    }
    if(konto== nullptr)return false;
    if(konto->haslo==password)return true;
    else return false;
}
bool Loging::log_in(std::string login,std::string password)
{
    return check_if_password_is_correct(login,password);
}
bool Loging::register_new_user(std::string imie,std::string nazwisko,std::string mail,std::string login, std::string haslo)
{

}