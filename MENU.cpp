//
// Created by Mateusz on 21.11.2022.
//
#include "MENU.h"

/// cosntr / destr
MENU::MENU() {  /// initializes on the start
    this->initialize_variables();
    this->initialize_window();
    this->initialize_texts();
    font1.loadFromFile("../arial.ttf");
}
MENU::~MENU() {
    delete this->window;

}

/// public functions
void MENU::update_mouse_position() { /// updates mouse position to vector2i
    this->MousePosWindow = sf::Mouse::getPosition();
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


/// private functions

void MENU::initialize_variables() {
    this->window = nullptr;
}
/// initialize texts, to do: class to automatically creates text to display
void MENU::initialize_texts(){
    text1.Textline_set(100,100,"LOL",50,&font1,sf::Color::Cyan);


}

/// initializes the window
void MENU::initialize_window() {
    this->video_mode.height = 800;
    this->video_mode.width = 600;

    // this->video_mode.getDesktopMode(); // this can give you the parametres of your screen to your window
    this->window = new RenderWindow(this->video_mode,"Proba nr 1.",Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(60);
}
/// to do in future


/// text based things
void MENU::update_texts() {

    text1.Textline_set(100,100,std::to_string(MousePosWindow.y),50,&font1,sf::Color::Cyan);



}
void MENU::render_texts(){

    text1.render(this->window);

}


void MENU::render_button()
{
b1.render(this->window);
}


void MENU::update_button()
{
    b1.button_set(250,100,100,300,&font1,"button 1",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
    b1.update(get_mous_pos());
}


sf::Vector2f MENU::get_mous_pos()
{
    return sf::Vector2f(static_cast<float>(this->MousePosWindow.x), static_cast<float>(this->MousePosWindow.y));

}