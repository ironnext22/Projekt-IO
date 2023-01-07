// Created by Mateusz on 21.11.2022.
/*
 * Class acts like an engine.
 */
#define Background_color color(240,246,235,255)
#pragma once
#ifndef PROJEKT_IO_MENU_H
#include "SFML/Graphics.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Button.h"
#include "Textline.h"
#include "Input_bar.h"
#include "Loging.h"
#include "Pracownik.h"
#include "Time_app.h"
#define PROJEKT_IO_MENU_H
enum class sites{
    start_site = 0,
    login_screen_site = 1,
    credits_site = 2,
    register_site = 3,
    logged_in_site = 4,
    calendar_site =5,
    magazine_site=6,
    password_reset_site =7,
    calendar_display_site=8,
    account_management_site =9,
    password_changing_site=10,
    admin_start_site = 11,
    admin_site_employee_managent_site = 12,
    admin_magazine_site = 13,




};

using namespace sf;
class Okno {
public:

private:
    void initialize_variables();
    void initialize_window();
    void change_site(sites sites);
    void clear_site_and_wait();
    void generate_code();
    sf::Vector2f get_mous_pos();
    void make_input_bar_active(int which_one);

    Loging logging_menu;
    RenderWindow* window;
    Event ev;
    VideoMode video_mode;
    sf::Vector2i MousePosWindow;
    sf::Font font1;
    /// window objects test
    Textline text1,text2,text3,text4,text5;
    sf::RectangleShape test;
    Button b1,b2,b3,b4,b5,b6,b7;
    sf::Texture background_photo;
    sf::Sprite sprite;
    Input_bar input_bar1,input_bar2,input_bar3,input_bar4,input_bar5;
    sites site;
    std::string login,password,password_confirm;
    std::string verification_code = "000000";
    Pracownik* logged_user = nullptr;

    /// auxiliary variables
    bool email_sent = false;
    bool created_ac = false;
    bool is_currently_changing_password = false;
    bool is_logged = false;
    Time_app timer;
    /// debug and bugfixing
    bool admin = true;


    ///

public:

    /// Contructor / destructor
    Okno();
    virtual ~Okno();
    /// accessors
    const bool get_window_is_open() const;

    ///functions
    void update_mouse_position();
    void poll_events();
    void update();
    void render();




};

#endif
