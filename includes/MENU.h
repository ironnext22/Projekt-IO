// Created by Mateusz on 21.11.2022.
/*
 * Class acts like an engine.
 */
#define Background_color color(240,246,235,255)
#pragma once
#ifndef PROJEKT_IO_MENU_H
#define PROJEKT_IO_MENU_H
#include "SFML/Graphics.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Button.h"
#include "Textline.h"
#include "Input_bar.h"

using namespace sf;
class MENU {
public:

private:
    void initialize_variables();
    void initialize_window();
    void initialize_texts();
    void initialize_input_bar();
    RenderWindow* window;
    Event ev;
    VideoMode video_mode;
    sf::Vector2i MousePosWindow;
    sf::Font font1;
    /// window objects test
    Textline text1;
    sf::RectangleShape test;
    Button b1,b2,b3,b4;
    sf::Texture background_photo;
    sf::Sprite sprite;
    Input_bar input_bar1;


public:

    /// Contructor / destructor
    MENU();
    virtual ~MENU();
    /// accessors
    const bool get_window_is_open() const;

    ///functions
    void update_mouse_position();
    void poll_events();
    void update();
    void render();
    void update_texts();
    void render_texts();
    void render_button();
    void update_button();
    void initialize_buttons();
    sf::Vector2f get_mous_pos();

    void update_input_bar();
    void render_input_bar();
};

#endif
