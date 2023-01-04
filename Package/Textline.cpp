//
// Created by Mateusz on 03.01.2023.
//

#include "../includes/Textline.h"


void Textline::Textline_set(float x, float y, std::string text, int Charakter_size, sf::Font *font, sf::Color text_color) {
    this->text_to_be_displayed.setString(text);
    this->font = font;
    this->text_to_be_displayed.setFont(*this->font);
    this->text_to_be_displayed.setFillColor(text_color);
    this->text_to_be_displayed.setCharacterSize(Charakter_size);
    this->text_to_be_displayed.setPosition(x,y);
    this->text_to_be_displayed.setScale(sf::Vector2f(0.5f ,0.5f));
    this->text_to_be_displayed.setOutlineColor(sf::Color::Black);
    this->text_to_be_displayed.setOutlineThickness(10);


}
void Textline::render(sf::RenderTarget *target) {
    target->draw(this->text_to_be_displayed);
}