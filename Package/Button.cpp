//
// Created by Mateusz on 02.01.2023.
//
#define     idle_color       0xB8D8D8FF
#define     hover_color      0x7A9E9FFF
#define     active_color     0x4F6467FF
#define     text_color       0xFFFFFFFF
#define     out_line_color   0x000000FF


#include "../includes/Button.h"
/// constr / destr
void Button::button_set(float x, float y, float height, float width, sf::Font* font,std::string text){
    button_photo.loadFromFile("../stuff/button.png");

    this->button_state = BUTTON_IDLE;
    this->shape.setPosition(sf::Vector2f(x,y));
    this->shape.setSize(sf::Vector2f(width,height));
    this->shape.setTexture(&button_photo);
    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color{text_color});
    this->text.setOutlineThickness(4);
    this->text.setOutlineColor(sf::Color{out_line_color});
    this->text.setCharacterSize(40);

    this->text.setPosition( // sets the position of TEXT into the button
            this->shape.getPosition().x + this->shape.getSize().x/1.8- this->text.getCharacterSize()*text.length()/3.0,
            this->shape.getPosition().y + (this->shape.getSize().y/1.5) - this->text.getCharacterSize()
    );



    this->shape.setFillColor(sf::Color{idle_color});
}
Button::~Button(){


}

/// Accessors

const bool Button::is_pressed() const{
    if(this->button_state == BUTTON_ACTIVE){return true;}
    return false;
}


/// functions

void Button::render(sf::RenderTarget *target) {
    target->draw(this->shape);
    target->draw(this->text);
}

void Button::update(const sf::Vector2f mousePos){
    /// update the booleans for hover and pressed

    /// idle
    this->button_state = BUTTON_IDLE;
    if(shape.getGlobalBounds().contains(mousePos))
    {
        /// hovered
        this->button_state = BUTTON_HOVER;

        /// pressed
        if(sf::Mouse::isButtonPressed( sf::Mouse::Left))
        {
            this->button_state= BUTTON_ACTIVE;
        }

    }
    switch(this->button_state){ // changes the colour of the button in case of the state of  mouse
        case BUTTON_IDLE:
            this->shape.setFillColor(sf::Color{idle_color});
            break;
        case BUTTON_ACTIVE:
            this->shape.setFillColor(sf::Color{active_color});
            break;
        case BUTTON_HOVER:
            this->shape.setFillColor(sf::Color{hover_color});
            break;
        default:
            this->shape.setFillColor(sf::Color::Red);
            break;
    }

}