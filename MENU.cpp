//
// Created by Mateusz on 21.11.2022.
//
#include "MENU.h"

/// cosntr / destr
MENU::MENU() {
    this->initialize_variables();
    this->initialize_window();
}
MENU::~MENU() {
    delete this->window;

}

/// public functions
void MENU::update_mouse_position() {



}
void MENU::poll_events() { // checks if something was done eg. key pressed

    while(this->window->pollEvent(this->ev)) {
        switch(this->ev.type)
        {
            case Event::Closed:
                this->window->close();
                break;
            case Event::KeyPressed:
                if(this->ev.key.code == Keyboard::Escape) {
                    this->window->close();
                    break;
                }


        }

    }
}


void MENU::render() { // renders things
    this->window->clear(Color::White);

    sf::Text tx1;
    tx1.setFillColor(sf::Color::Red);
    tx1.setString("XD");
    tx1.setCharacterSize(10);
    this->window->draw(tx1);


    this->window->display();
}

void MENU::update() { // checks for changes
    this->poll_events();
}




/// accessors

const bool MENU::get_window_is_open() const
{
    return this->window->isOpen();
}


/// private functions

void MENU::initialize_variables() {
    this->window = nullptr;
}

void MENU::initialize_window() {
    this->video_mode.height = 800;
    this->video_mode.width = 600;
    // this->video_mode.getDesktopMode(); // this can give you the parametres of your screen to your window
    this->window = new RenderWindow(this->video_mode,"Proba nr 1.",Style::Titlebar | Style::Close);
}

void updateMousePos(){

}


