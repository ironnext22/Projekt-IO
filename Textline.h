//
// Created by Mateusz on 03.01.2023.
//
#include "SFML/Graphics.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#ifndef PROJEKT_IO_TEXTLINE_H
#define PROJEKT_IO_TEXTLINE_H


class Textline {
private:
    int x,y;
    std::string text;
    int Charakter_size;
    sf::Font *font;
    sf::Color text_color;
    sf::Text text_to_be_displayed;

public:
    void Textline_set(float x, float y, std::string text, int Charakter_size,sf::Font *font,sf::Color text_color);
    void render(sf::RenderTarget* target);
};




#endif //PROJEKT_IO_TEXTLINE_H
