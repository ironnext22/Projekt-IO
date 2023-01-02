// Created by Mateusz on 21.11.2022.
/*
 * Class acts like an engine.
 */

#pragma once
#ifndef PROJEKT_IO_MENU_H
#define PROJEKT_IO_MENU_H
#include "SFML/Graphics.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Button.h"

using namespace sf;
class MENU {
public:

private:
    void initialize_variables();
    void initialize_window();
    RenderWindow* window;
    Event ev;
    VideoMode video_mode;

    sf::Vector2i MousePosWindow;

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
    void updateMousePos();



};

#endif
