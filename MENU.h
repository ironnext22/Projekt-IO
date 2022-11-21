//
// Created by Mateusz on 21.11.2022.
//

#ifndef PROJEKT_IO_MENU_H
#define PROJEKT_IO_MENU_H
#include "SFML/Graphics.hpp"


#pragma once
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEM 3

class MENU {
public:
    MENU(float width, float height);
    ~MENU();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem(){return selectedItemIndex;}
private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text Menu[MAX_NUMBER_OF_ITEM];
};

#endif //PROJEKT_IO_MENU_H
