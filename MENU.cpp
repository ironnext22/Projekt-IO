//
// Created by Mateusz on 21.11.2022.
//
#include "MENU.h"

/// cosntr / destr
MENU::MENU() {
    this->initialize_variables();
    this->initialize_window();
    this->initialize_texts();
}
MENU::~MENU() {
    delete this->window;

}

/// public functions
void MENU::update_mouse_position() {
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
    this->text1.setString("X5555555555555555555555555555D");
    this->text1.setFillColor(sf::Color::Cyan);
    this->text1.setCharacterSize(50);
    this->text1.setPosition(100.f,100.f);
    this->text1.setScale(sf::Vector2f(0.5f ,0.5f));

    font1.loadFromFile("../arial.ttf");
    this->text1.setFont(font1);

    this->test.setPosition(10.f,10.f);
    this->test.setSize(sf::Vector2f(100.f,100.f));
    this->test.setScale(sf::Vector2f(0.5f ,0.5f));
    this->test.setFillColor(sf::Color::Cyan);





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
    this->text1.setString(std::to_string(MousePosWindow.y));

}
void MENU::render_texts(){
    this->window->draw(text1);
    this->window->draw(test);
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