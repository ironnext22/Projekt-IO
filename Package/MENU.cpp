//
// Created by Mateusz on 21.11.2022.
//
#include "../includes/MENU.h"

/// cosntr / destr
MENU::MENU() {  /// initializes on the start
    this->initialize_variables();
    this->initialize_window();
    this->initialize_texts();
    this->initialize_buttons();
    this->initialize_input_bar();
    font1.loadFromFile("../arial.ttf");
    background_photo.loadFromFile("../stuff/background.png");
    sprite.setTexture(background_photo);
}
MENU::~MENU() {
    delete this->window;

}

/// initializes the window
void MENU::initialize_window() {
    this->video_mode.height = 800;
    this->video_mode.width = 1400;

    // this->video_mode.getDesktopMode(); // this can give you the parametres of your screen to your window
    this->window = new RenderWindow(this->video_mode,"Proba nr 1.",Style::Titlebar | Style::Close);
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
            case Event::TextEntered:
                if(this->ev.key.code == Keyboard::Escape) {
                    this->window->close();
                    break;
                }
                else if(input_bar1.get_is_selected())
                {

                    input_bar1.typed_on(ev);
                    break;
                }
        }
    }
}


/// First: updates the values, then renders them.

void MENU::render() { // renders things
    this->window->clear(Color::White);
    this->window->draw(sprite);
    this->render_texts();
    this->render_button();
    this->render_input_bar();
    this->window->display();

}

void MENU::update() { // checks for changes
    this->poll_events();
    this->update_mouse_position();
    this->update_texts();
    this->update_button();
    this->update_input_bar();
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
    b1.button_set(550,600,100,300,&font1,"EXIT",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
    b2.button_set(550,500,100,300,&font1,"Archiwum",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
    b3.button_set(550,400,100,300,&font1,"Magazyn",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
    b4.button_set(550,300,100,300,&font1,"Wizyty",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
}
void MENU::initialize_texts(){
    text1.Textline_set(100,100,"LOL",50,&font1,sf::Color::Cyan);
}
void MENU::initialize_input_bar() {
    input_bar1.set_Input_bar(200,200,50,sf::Color::Magenta,true,&font1);
    input_bar1.set_limit(true,10);
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
    if(b1.is_pressed())this->window->close();
    b2.update(get_mous_pos());
    b3.update(get_mous_pos());
    b4.update(get_mous_pos());
}

void MENU::render_button()
{
b1.render(this->window);
b2.render(this->window);
b3.render(this->window);
b4.render(this->window);
}
/// Input bar

void MENU::render_input_bar() {
    input_bar1.render(this->window);

}

void MENU::update_input_bar() {


}


/// Other staff

sf::Vector2f MENU::get_mous_pos()
{
    return sf::Vector2f(static_cast<float>(this->MousePosWindow.x), static_cast<float>(this->MousePosWindow.y));

}