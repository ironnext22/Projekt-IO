//
// Created by Mateusz on 21.11.2022.
//

#include "MENU.h"

MENU::MENU(float width, float height)
{
    if(!font.loadFromFile("arial.ttf"))
    {
        //error, bo nie ma czcionki
    }

    Menu[0].setFont(font);
    Menu[0].setFillColor(sf::Color::Red);
    Menu[0].setString("siema_PROBA CZY DZIALA");
    Menu[0].setPosition(sf::Vector2f(width/2,height/(MAX_NUMBER_OF_ITEM+1)*1));

    Menu[1].setFont(font);
    Menu[1].setFillColor(sf::Color::White);
    Menu[1].setString("witaj w mojej");
    Menu[1].setPosition(sf::Vector2f(width/2,height/(MAX_NUMBER_OF_ITEM+1)*2));

    Menu[2].setFont(font);
    Menu[2].setFillColor(sf::Color::White);
    Menu[2].setString("kuchni");
    Menu[2].setPosition(sf::Vector2f(width/2,height/(MAX_NUMBER_OF_ITEM+1)*3));

    selectedItemIndex = 0;
}

MENU::~MENU()
{}

void MENU::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < MAX_NUMBER_OF_ITEM; i++)
    {
        window.draw(Menu[i]);
    }
}

void MENU::MoveUp()
{
    if(selectedItemIndex - 1 >= 0)
    {
        Menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        Menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void MENU::MoveDown()
{
    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEM)
    {
        Menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        Menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

