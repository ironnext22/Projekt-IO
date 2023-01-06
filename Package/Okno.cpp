//
// Created by Mateusz on 21.11.2022.
//
#include "../includes/Okno.h"
#include <thread>
#include <chrono>
/// cosntr / destr
Okno::Okno() {  /// initializes on the start
    this->initialize_variables();
    this->initialize_window();
    site = 0;
    font1.loadFromFile("../arial.ttf");
    background_photo.loadFromFile("../stuff/background.png");
    sprite.setTexture(background_photo);
}
Okno::~Okno() {
    delete this->window;

}
void Okno::clear_site(){
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    b1.button_set(0,0,0,0,&font1,"",sf::Color::White,sf::Color::White,sf::Color::White);
    b2.button_set(0,0,0,0,&font1,"",sf::Color::White,sf::Color::White,sf::Color::White);
    b3.button_set(0,0,0,0,&font1,"",sf::Color::White,sf::Color::White,sf::Color::White);
    b4.button_set(0,0,0,0,&font1,"",sf::Color::White,sf::Color::White,sf::Color::White);
    b5.button_set(0,0,0,0,&font1,"",sf::Color::White,sf::Color::White,sf::Color::White);
    text1.Textline_set(0,0,"",0,&font1,sf::Color::White);
    text2.Textline_set(0,0,"",0,&font1,sf::Color::White);
    text3.Textline_set(0,0,"",0,&font1,sf::Color::White);
    text4.Textline_set(0,0,"",0,&font1,sf::Color::White);
    text5.Textline_set(0,0,"",0,&font1,sf::Color::White);
    input_bar1.set_Input_bar(0,0,0,sf::Color::White,false,&font1);
    input_bar2.set_Input_bar(0,0,0,sf::Color::White,false,&font1);
}

/// initializes the window
void Okno::initialize_window() {
    this->video_mode.height = 800;
    this->video_mode.width = 1400;

    // this->video_mode.getDesktopMode(); // this can give you the parametres of your screen to your window
    this->window = new RenderWindow(this->video_mode,"Proba nr 1.",Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(60);
}

/// public functions
void Okno::update_mouse_position() { /// updates mouse position to vector2i
    this->MousePosWindow = sf::Mouse::getPosition(*this->window);
}



void Okno::poll_events() { /// checks if something was done eg. key pressed

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
                else if(input_bar1.get_is_selected()){
                    input_bar1.typed_on(ev);
                }
                else if(input_bar2.get_is_selected()){
                    input_bar2.typed_on(ev);
                }
                else if(input_bar3.get_is_selected()){
                    input_bar3.typed_on(ev);
                }
                else if(input_bar4.get_is_selected()){
                    input_bar4.typed_on(ev);
                }




        }
    }
}


/// First: updates the values, then renders them.

void Okno::render() { // renders things
    this->window->clear(Color::White);
    this->window->draw(sprite);


    switch(site) {
        case 0: /// start
        {

            b1.button_set(600,600,100,300,&font1,"EXIT",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b1.update(get_mous_pos());
            if(b1.is_pressed()){this->window->close();}
            b1.render(this->window);

            b1.button_set(600,400,100,300,&font1,"Zaloguj",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b1.update(get_mous_pos());
            if(b1.is_pressed()){site=1;  clear_site();}
            b1.render(this->window);

            b1.button_set(600,500,100,300,&font1,"Credits",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b1.update(get_mous_pos());
            if(b1.is_pressed()){site=2;  clear_site();}
            b1.render(this->window);

            b1.button_set(600,500,100,300,&font1,"Credits",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b1.update(get_mous_pos());
            if(b1.is_pressed()){site=2;  clear_site();}
            b1.render(this->window);

            break;
        }
        case 1:/// Login screen
        {

            input_bar1.set_limit(true,15);
            input_bar2.set_limit(true,15);



            b1.button_set(600,400,100,700,&font1,"Login: " + input_bar1.get_text(),sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b1.update(get_mous_pos());
            if(b1.is_pressed()){input_bar1.set_selected(true); input_bar2.set_selected(false); }
            b1.render(this->window);

            password="";
            for (int i =0; i<input_bar2.get_text().length();i++){
                password+="*";
            }
            b2.button_set(600,500,100,700,&font1,"Password: " + password,sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b2.update(get_mous_pos());
            if(b2.is_pressed()){input_bar2.set_selected(true); input_bar1.set_selected(false); }
            b2.render(this->window);

            b3.button_set(600,600,100,350,&font1,"Log in",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b3.update(get_mous_pos());
            if(b3.is_pressed()){site=4;clear_site();}
            b3.render(this->window);


            b4.button_set(20, 20, 100, 150, &font1, "BACK", sf::Color::Magenta, sf::Color::Cyan, sf::Color::Blue);
            b4.update(get_mous_pos());
            if (b4.is_pressed()){
                site=0;
                clear_site();}
            b4.render(this->window);

            b5.button_set(950,600,100,350,&font1,"Register",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b5.update(get_mous_pos());
            if(b5.is_pressed()){site=3;clear_site();}
            b5.render(this->window);

            b5.button_set(600,700,100,700,&font1,"Forgot Password",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b5.update(get_mous_pos());
            if(b5.is_pressed()){site=7;clear_site();}
            b5.render(this->window);

            break;

        }

        case 2: /// Credits
        {
            clear_site();
            text1.Textline_set(200,200,"Wykonali:",40,&font1,sf::Color::White);
            text2.Textline_set(200,250,"Mateusz Kuzera",40,&font1,sf::Color::White);
            text3.Textline_set(200,300,"Wiktor Kowalski:",40,&font1,sf::Color::White);
            text4.Textline_set(200,350,"Mateusz Lugowski",40,&font1,sf::Color::White);
            text5.Textline_set(200,400,"Projekt Gabinetu Dentystycznego, grupa labolatoryjna 3.",40,&font1,sf::Color::White);

            text1.render(this->window);
            text2.render(this->window);
            text3.render(this->window);
            text4.render(this->window);
            text5.render(this->window);

            b1.button_set(20, 20, 100, 150, &font1, "BACK", sf::Color::Magenta, sf::Color::Cyan, sf::Color::Blue);
            b1.update(get_mous_pos());
            if (b1.is_pressed()){
                site=0; clear_site(); }
            b1.render(this->window);
            break;

        }
        case 3: /// Register
        {

            input_bar1.set_limit(true,15);
            input_bar2.set_limit(true,15);
            input_bar3.set_limit(true,25);

            b1.button_set(20, 20, 100, 150, &font1, "BACK", sf::Color::Magenta, sf::Color::Cyan, sf::Color::Blue);
            b1.update(get_mous_pos());
            if (b1.is_pressed()){site=1; clear_site();}
            b1.render(this->window);

            b1.button_set(600,200,100,700,&font1,"Login: " + input_bar1.get_text(),sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b1.update(get_mous_pos());
            if(b1.is_pressed()){input_bar3.set_selected(false); input_bar2.set_selected(false);input_bar1.set_selected(true);input_bar4.set_selected(false); }
            b1.render(this->window);

            password="";
            for (int i =0; i<input_bar2.get_text().length();i++){
                password+="*";
            }
            b2.button_set(600,300,100,700,&font1,"Password: " + password,sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b2.update(get_mous_pos());
            if(b2.is_pressed()){input_bar2.set_selected(true); input_bar1.set_selected(false);input_bar3.set_selected(false);input_bar4.set_selected(false); }
            b2.render(this->window);
            password_confirm="";
            for (int i =0; i<input_bar3.get_text().length();i++){
                password_confirm+="*";
            }
            b3.button_set(600,400,100,700,&font1,"Repeat Password: " + password_confirm,sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b3.update(get_mous_pos());
            if(b3.is_pressed()){input_bar3.set_selected(true); input_bar2.set_selected(false);input_bar1.set_selected(false);input_bar4.set_selected(false); }
            b3.render(this->window);

            b4.button_set(600,500,100,700,&font1,"Email: " + input_bar4.get_text(),sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b4.update(get_mous_pos());
            if(b4.is_pressed()){input_bar3.set_selected(false); input_bar1.set_selected(false);input_bar2.set_selected(false); input_bar4.set_selected(true);}
            b4.render(this->window);

            b5.button_set(600,600,100,700,&font1,"Register",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b5.update(get_mous_pos());
            if(b5.is_pressed()){/// TO DO SEND COMUNICAT IF ALL IS CORECT//

            }
            b5.render(this->window);
            break;






        }
        case 4: /// Logged in menu
        {
            b1.button_set(20, 20, 100, 150, &font1, "BACK", sf::Color::Magenta, sf::Color::Cyan, sf::Color::Blue);
            b1.update(get_mous_pos());
            if (b1.is_pressed())site=0;
            b1.render(this->window);

            b2.button_set(600,400,100,300,&font1,"Calendar",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b2.update(get_mous_pos());
            if(b2.is_pressed()){site=5;  clear_site();}
            b2.render(this->window);

            b3.button_set(600,300,100,300,&font1,"Magazine",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b3.update(get_mous_pos());
            if(b3.is_pressed()){site=6;  clear_site();}
            b3.render(this->window);

            b2.button_set(600,500,100,300,&font1,"Log out",sf::Color::Magenta,sf::Color::Cyan,sf::Color::Blue);
            b2.update(get_mous_pos());
            if(b2.is_pressed()){site=0;  clear_site();}
            b2.render(this->window);



            break;
        }
        case 5: /// Calendar
        {
            b1.button_set(20, 20, 100, 150, &font1, "BACK", sf::Color::Magenta, sf::Color::Cyan, sf::Color::Blue);
            b1.update(get_mous_pos());
            if (b1.is_pressed())site=4;
            b1.render(this->window);

        }

        case 6: /// Magazine
        {
            b1.button_set(20, 20, 100, 150, &font1, "BACK", sf::Color::Magenta, sf::Color::Cyan, sf::Color::Blue);
            b1.update(get_mous_pos());
            if (b1.is_pressed())site=4;
            b1.render(this->window);

        }
        case 7: /// Password reset
        {
            b1.button_set(20, 20, 100, 150, &font1, "BACK", sf::Color::Magenta, sf::Color::Cyan, sf::Color::Blue);
            b1.update(get_mous_pos());
            if (b1.is_pressed()){site=1;clear_site();}
            b1.render(this->window);

        }

    }




    this->window->display();

}

void Okno::update() { // checks for changes
    this->poll_events();
    this->update_mouse_position();
}




/// accessors

const bool Okno::get_window_is_open() const
{
    return this->window->isOpen();
}


/// Inirializing some staff like texts, buttons.

void Okno::initialize_variables() {
    this->window = nullptr;
}





/// Other staff

sf::Vector2f Okno::get_mous_pos()
{
    return sf::Vector2f(static_cast<float>(this->MousePosWindow.x), static_cast<float>(this->MousePosWindow.y));

}