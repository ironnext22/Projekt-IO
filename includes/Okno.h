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
#include "Functions.h"
#include "Button.h"
#include "Textline.h"
#include "Input_bar.h"
#include "Loging.h"
#include "Pracownik.h"
#include "Time_app.h"
#include "Mail.h"
#include "Assistant.h"
#include "Admin.h"
#include "Dentist.h"
#include "Functions.h"
#include "Pacjeci.h"
#include "Tranzakcja.h"
#include "Finanse.h"
#include "Magazyn.h"
#include "Kartoteka.h"
#include "Sites.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#define PROJEKT_IO_MENU_H


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
    Mail mailbox;
    RenderWindow* window;
    Event ev;
    VideoMode video_mode;
    sf::Vector2i MousePosWindow;
    sf::Font font1;

    Textline text1,text2,text3,text4,text5;

    Button b1,b2,b3,b4,b5,b6,b7,b8,b9;
    sf::Texture background_photo,logo;
    sf::Image icon;
    sf::Sprite sprite,sprite2;
    Input_bar input_bar1,input_bar2,input_bar3,input_bar4,input_bar5,input_bar6,input_bar7;
    sites site;
    std::string password,password_confirm;



    Pracownik* logged_user = nullptr;
    Pacjeci pacient_list;
    Pracownicy worker_list;
    Admin *adm = nullptr;
    Assistant *assistant = nullptr;
    Dentist *dentist = nullptr;
    Kalendarz kalendarz;
    Finanse finanse;
    Magazyn mag;
    Kartoteka kartoteka2;
    Time_app timer;

    /// auxiliary variables // zmienne pomocnicze
    bool email_sent = false;
    bool created_ac = false;
    bool is_currently_changing_password = false;
    int selected = 0;
    std::string selected_string = "";
    int current_day = 2;
    int year = 2023;
    bool is_logged = false;
    std::string ID = "XXXXXX";
    bool added = false;
    std::string verification_code = "000000";
    std::string textpat = "";


public:

    Okno();
    virtual ~Okno();
    const bool get_window_is_open() const;
    void update_mouse_position();
    void poll_events();
    void update();
    void render();


    void clear_buttons();

    void clear_textlines();

    void clear_input_bars();
};

#endif
