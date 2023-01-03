//
// Created by Mateusz on 02.01.2022
//

//

#include "SFML/Graphics.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <iostream>
#ifndef PROJEKT_IO_BUTTONS_H
#define PROJEKT_IO_BUTTONS_H

enum button_states{BUTTON_IDLE = 0, BUTTON_HOVER, BUTTON_ACTIVE};
class Button {

private:
    short unsigned button_state;

    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;

    sf::Color idle_color;
    sf::Color hover_color;
    sf::Color active_color;

    sf::Texture button_photo;
public:
    /// contr / destr
    void button_set(float x, float y, float height, float width, sf::Font* font,std::string text,
           sf::Color idle_color,sf::Color hover_color,sf::Color active_color);
    ~Button();
    /// Accessors

    const bool is_pressed() const;




    /// functions
    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget* target);



};


#endif //PROJEKT_IO_BUTTONS_H
