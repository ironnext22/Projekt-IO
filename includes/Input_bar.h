//
// Created by Mateusz on 04.01.2023.
//
#include <iostream>
#include <sstream>
#ifndef PROJEKT_IO_INPUT_BAR_H
#define PROJEKT_IO_INPUT_BAR_H

#include "../SFML/Graphics.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Input_bar {
public:
    Input_bar();

    void set_Input_bar(float posX,float posY,int size, sf::Color color, bool selected,sf::Font *font);
    void set_Input_bar(float posX,float posY,int size, sf::Color color,sf::Font *font);
    void set_limit(bool has_limit);
    void set_limit(bool has_limit, int limit);
    void set_selected(bool selected);
    std::string get_text();
    void render(sf::RenderTarget* target);
    void typed_on(sf::Event input);
    bool get_is_selected();
    void typed_on_key();
private:
    sf::Text sf_text_inputed;
    std::ostringstream text;
    bool is_selected = false;
    bool has_limit = false;
    int limit;
    sf::Font *font;

    void input_logic(int char_typed);
    void delete_last_letter();


};


#endif //PROJEKT_IO_INPUT_BAR_H
