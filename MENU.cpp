//
// Created by Mateusz on 21.11.2022.
//
#include "MENU.h"

/// cosntr / destr
MENU::MENU() {  /// initializes on the start
    this->initialize_variables();
    this->initialize_window();
    this->initialize_texts();
    this->initialize_buttons();
    font1.loadFromFile("../arial.ttf");
}
MENU::~MENU() {
    delete this->window;

}

/// initializes the window
void MENU::initialize_window() {

    this->video_mode.height = 800;
    this->video_mode.width = 1400;
    background_photo.loadFromFile("../stuff/background.png");

    // this->video_mode.getDesktopMode(); // this can give you the parametres of your screen to your window
    this->window = new RenderWindow(this->video_mode,"Aplication for professional people with degree",Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(60);
}

/// public functions
void MENU::update_mouse_position() { /// updates mouse position to vector2i
    this->MousePosWindow = sf::Mouse::getPosition(*this->window);
}

void MENU::poll_events() { /// checks if something was done eg. key pressed

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


/// First: updates the values, then renders them.

void MENU::render() { // renders things
    this->window->clear(Color::White);
    this->window->draw(sf::Sprite(background_photo));
    this->render_texts();
    this->render_button();
    this->window->display();
}

void MENU::update() { // checks for changes
    this->poll_events();
    this->update_mouse_position();
    this->update_texts();
    this->update_button();
}




/// accessors

const bool MENU::get_window_is_open() const
{
    return this->window->isOpen();
}


/// Inirializing some staff like texts, buttons.

void MENU::initialize_variables() {
    this->window = nullptr;
}
void MENU::initialize_buttons(){
    b1.button_set(250,100,100,300,&font1,"button 1",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
}
void MENU::initialize_texts(){
    text1.Textline_set(100,100,"LOL",50,&font1,sf::Color::Cyan);


}

/// Texts
void MENU::update_texts() {

    text1.Textline_set(100,100,std::to_string(MousePosWindow.y),50,&font1,sf::Color::Cyan);

}
void MENU::render_texts(){

    text1.render(this->window);

}

/// Buttons
void MENU::update_button()
{

    b1.update(get_mous_pos());
}

void MENU::render_button()
{
b1.render(this->window);
}



/// Other staff

sf::Vector2f MENU::get_mous_pos()
{
    return sf::Vector2f(static_cast<float>(this->MousePosWindow.x), static_cast<float>(this->MousePosWindow.y));

}