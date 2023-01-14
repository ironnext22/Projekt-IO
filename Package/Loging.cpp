#include "../includes/Loging.h"

bool Loging::check_if_email_is_in_data_base(std::string email_from_user)
{
    for(auto a : login_list.get_worker())
    {
        if(a.get_mail()==email_from_user)return true;
    }
    return false;
}
bool Loging::check_if_login_exists(std::string login)
{
    for(auto a : login_list.get_worker())
    {
        if(a.get_login()==login)return true;
    }
    return false;
}
bool Loging::check_if_password_is_correct(std::string login,std::string password)
{
    if(!check_if_login_exists(login))return false;
    Pracownik* konto;
    for(auto a : login_list.get_worker())
    {
        std::cout<<a.get_login()<<" "<<login<<std::endl;
        if(a.get_login()==login)
        {
            konto = &a;
            break;
        }
    }
    if(konto== nullptr)return false;
    //std::cout<<konto->login<<" "<<password<<std::endl;
    if(konto->get_password()==password)return true;
    else return false;
}
bool Loging::log_in(std::string login,std::string password)
{
    return check_if_password_is_correct(login,password);
}
std::string Loging::register_new_user(std::string mail,std::string login, std::string haslo)
{
    if(check_if_email_is_in_data_base(mail))return "Mail already exist";
    if(check_if_login_exists(login))return "Login already exist";
    login_list.dodaj_pracownika("unknown","unknown",login,haslo,"brak",mail);
return "Poprawne";
}
