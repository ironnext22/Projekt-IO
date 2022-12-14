//
// Created by Mateusz on 21.11.2022.
//
#include "../includes/Okno.h"
#include <thread>
#include <chrono>
#define MAX_PASSWORD_CHARACTERS 20
#define MAX_LOGIN_CHARACTERS 20
#define MAX_EMAIL_CHARACTERS 25
#define MAX_NAME_SURNAME_CHARACTERS 20




Okno::Okno() {  /// initializes on the start
    this->initialize_variables();
    this->initialize_window();
    site = sites::start_site;
    font1.loadFromFile("../arial.ttf");
    background_photo.loadFromFile("../stuff/background.png");
    sprite.setTexture(background_photo);
}
Okno::~Okno() {
    delete this->window;

}

void Okno::change_site(sites sites){ /// changes sites , also cleaning up staff before changing.
    clear_site_and_wait();
    site = sites;
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
                else if(input_bar5.get_is_selected()){
                    input_bar5.typed_on(ev);
                }




        }
    }
}



/// renders
void Okno::render() {
    this->window->clear(Color::White);
    this->window->draw(sprite);

    switch(site) {
        case sites::start_site: {

            b1.button_set(600, 600, 100, 300, &font1, "Exit");
            b1.update(get_mous_pos());
            if (b1.is_pressed()) { this->window->close(); }
            b1.render(this->window);

            b1.button_set(600, 400, 100, 300, &font1, "Log in");
            b1.update(get_mous_pos());
            if (b1.is_pressed()) { change_site(sites::login_screen_site); }
            b1.render(this->window);


            b1.button_set(600, 500, 100, 300, &font1, "Credits");
            b1.update(get_mous_pos());
            if (b1.is_pressed()) { change_site(sites::credits_site); }
            b1.render(this->window);

            break;
        }
        case sites::login_screen_site: {

            input_bar1.set_limit(true, MAX_LOGIN_CHARACTERS);
            input_bar2.set_limit(true, MAX_PASSWORD_CHARACTERS);


            b1.button_set(600, 400, 100, 700, &font1, "Login: " + input_bar1.get_text());
            b1.update(get_mous_pos());
            if (b1.is_pressed()) { make_input_bar_active(1); }
            b1.render(this->window);

            password = "";
            for (int i = 0; i < input_bar2.get_text().length(); i++) {
                password += "*";
            }
            b2.button_set(600, 500, 100, 700, &font1, "Password: " + password);
            b2.update(get_mous_pos());
            if (b2.is_pressed()) { make_input_bar_active(2); }
            b2.render(this->window);

            b3.button_set(600, 600, 100, 350, &font1, "Log in");
            b3.update(get_mous_pos());
            if (b3.is_pressed()) {

                if (input_bar1.get_text() == "" || input_bar2.get_text() == "") {
                    text1.Textline_set(650, 350, "No login or password entered!", 50, &font1);

                } else if (logging_menu.log_in(input_bar1.get_text(), input_bar2.get_text())) {
                    logged_user= new Pracownik(input_bar1.get_text(),input_bar2.get_text());

                    is_logged = true;
                    if(logged_user->get_function() == "Administrator"){change_site(sites::admin_start_site);}
                    else {
                        change_site(sites::logged_in_site);
                    }

                } else if (!logging_menu.log_in(input_bar1.get_text(), input_bar2.get_text())) {
                    text1.Textline_set(650, 350, "Invalid login or password!", 50, &font1);
                }

            }
            text1.render(this->window);
            b3.render(this->window);


            b4.button_set(20, 20, 100, 150, &font1, "Back");
            b4.update(get_mous_pos());
            if (b4.is_pressed()) { change_site(sites::start_site); }
            b4.render(this->window);

            b5.button_set(950, 600, 100, 350, &font1, "Register");
            b5.update(get_mous_pos());
            if (b5.is_pressed()) { change_site(sites::register_site); }
            b5.render(this->window);

            b5.button_set(600, 700, 100, 700, &font1, "Forgot Password");
            b5.update(get_mous_pos());
            if (b5.is_pressed()) { change_site(sites::password_reset_site); }
            b5.render(this->window);

            break;

        }
        case sites::credits_site: {
            clear_site_and_wait();
            text1.Textline_set(200, 200, "Wykonali:", 40, &font1);
            text2.Textline_set(200, 250, "Mateusz Kuzera", 40, &font1);
            text3.Textline_set(200, 300, "Wiktor Kowalski:", 40, &font1);
            text4.Textline_set(200, 350, "Mateusz Lugowski", 40, &font1);
            text5.Textline_set(200, 400, "Projekt Gabinetu Dentystycznego, grupa labolatoryjna 3.", 40, &font1);

            text1.render(this->window);
            text2.render(this->window);
            text3.render(this->window);
            text4.render(this->window);
            text5.render(this->window);

            b1.button_set(20, 20, 100, 150, &font1, "Back");
            b1.update(get_mous_pos());
            if (b1.is_pressed()) { change_site(sites::start_site); }
            b1.render(this->window);
            break;

        }
        case sites::register_site: {
            if (!email_sent) {

                input_bar1.set_limit(true, MAX_LOGIN_CHARACTERS);
                input_bar2.set_limit(true, MAX_PASSWORD_CHARACTERS);
                input_bar3.set_limit(true, MAX_PASSWORD_CHARACTERS);
                input_bar3.set_limit(true, MAX_EMAIL_CHARACTERS);

                b1.button_set(20, 20, 100, 150, &font1, "Back");
                b1.update(get_mous_pos());
                if (b1.is_pressed()) { change_site(sites::login_screen_site); }
                b1.render(this->window);

                b1.button_set(600, 200, 100, 700, &font1, "Login: " + input_bar1.get_text());
                b1.update(get_mous_pos());
                if (b1.is_pressed()) { make_input_bar_active(1); }
                b1.render(this->window);

                password = "";
                for (int i = 0; i < input_bar2.get_text().length(); i++) {
                    password += "*";
                }

                b2.button_set(600, 300, 100, 700, &font1, "Password: " + password);
                b2.update(get_mous_pos());
                if (b2.is_pressed()) { make_input_bar_active(2); }
                b2.render(this->window);


                password_confirm = "";
                for (int i = 0; i < input_bar3.get_text().length(); i++) {
                    password_confirm += "*";
                }

                b3.button_set(600, 400, 100, 700, &font1, "Repeat Password: " + password_confirm);
                b3.update(get_mous_pos());
                if (b3.is_pressed()) { make_input_bar_active(3); }
                b3.render(this->window);


                b4.button_set(600, 500, 100, 700, &font1, "Email: " + input_bar4.get_text());
                b4.update(get_mous_pos());
                if (b4.is_pressed()) { make_input_bar_active(4); }
                b4.render(this->window);

                b5.button_set(600, 600, 100, 700, &font1, "Register");
                b5.update(get_mous_pos());
                if (b5.is_pressed()) {
                    if (input_bar1.get_text() == "" || input_bar2.get_text() == "" || input_bar3.get_text() == "" ||
                        input_bar4.get_text() == "") {
                        text1.Textline_set(650, 150, "All tiles need to be filled", 50, &font1);

                    } else if (input_bar2.get_text() != input_bar3.get_text()) {
                        text1.Textline_set(650, 150, "Passwords aren't the same", 50, &font1);
                    }
                    /// HERE ADD IF THAT ACCOUNT ALREADY EXISTS

                        ///  else if(!logging_menu.check_if_email_is_in_data_base(input_bar4.get_text())){
                        ///      text1.Textline_set(650,150,"There are no accounts with this email.",50,&font1);
                        ///
                        ///   }

                    else if (/*logging_menu.check_if_email_is_in_data_base(input_bar4.get_text())*/ !email_sent) {
                        /// also add


                        if(!email_sent){ generate_code();mailbox.send_mail_with_verification_code(input_bar1.get_text(),verification_code);}
                        std::cout << std::endl << verification_code << " -ver code"<< std::endl;
                        email_sent = true;
                        text1.Textline_set(650, 150, "Verification code has been sent", 50, &font1);

                    }



                    break;
                }
                text1.render(this->window);
                b5.render(this->window);

            }
            else if(email_sent) {


                text1.Textline_set(650,150,"Enter verification code - sent on email "+ input_bar4.get_text(),50,&font1);
                b1.button_set(20, 20, 100, 150, &font1, "Back");
                b1.update(get_mous_pos());
                if (b1.is_pressed()) { change_site(sites::login_screen_site); }
                b1.render(this->window);


                b3.button_set(600, 200, 100, 700, &font1, "Ver. code: "+input_bar5.get_text());
                b3.update(get_mous_pos());
                if (b3.is_pressed()) { make_input_bar_active(5); }


                b4.button_set(600, 300, 100, 700, &font1, "Check" );
                b4.update(get_mous_pos());

                if (b4.is_pressed() && created_ac==false) {
                    if(verification_code == input_bar5.get_text()){
                        logging_menu.register_new_user(input_bar4.get_text(),input_bar1.get_text(),input_bar2.get_text());
                        text2.Textline_set(650,120,"Created account",50,&font1);
                        created_ac = true;

                    }
                    else if(created_ac){
                        text1.Textline_set(650,150,"Account is created",50,&font1);
                    }
                    else if(verification_code != input_bar5.get_text()){

                        text1.Textline_set(650,150,"Invalid code",50,&font1);
                    }


                }
                b3.render(this->window);
                b4.render(this->window);
                text1.render(this->window);
                text2.render(this->window);

            }

            break;
    }
        case sites::logged_in_site:
        {


            b2.button_set(1000,400,100,400,&font1,"Calendar");
            b2.update(get_mous_pos());
            if(b2.is_pressed()){change_site(sites::calendar_site);}
            b2.render(this->window);

            b3.button_set(1000,300,100,400,&font1,"Magazine");
            b3.update(get_mous_pos());
            if(b3.is_pressed()){change_site(sites::magazine_site);}
            b3.render(this->window);

            b2.button_set(1000,600,100,400,&font1,"Log out");
            b2.update(get_mous_pos());
            if(b2.is_pressed()){
                is_logged = false;
                change_site(sites::start_site);}
            b2.render(this->window);

            b3.button_set(1000,500,100,400,&font1,"My account:");
            b3.update(get_mous_pos());
            if(b3.is_pressed()){change_site(sites::account_management_site);}
            b3.render(this->window);

            text1.Textline_set(100,100,"Logged as: " +logged_user->get_login() + "\n\n"+logged_user->get_name()+
            " "+logged_user->get_surname()+"\n\nPosition: "+logged_user->get_function()+"\n\nEmail: "+logged_user->get_mail()
            +"\n\nToday is: "+timer.currentDateTime()+"\n\nHave a good day",50,&font1);
            text1.render(this->window);

            /// HERE ADD INFORMATION ABOUT ACCOUNT LOGGED IN



            break;
        }
        case sites::calendar_site:
        {
            b1.button_set(20, 20, 100, 150, &font1, "Back");
            b1.update(get_mous_pos());
            if (b1.is_pressed()){change_site(sites::logged_in_site);};
            b1.render(this->window);
            break;

        }
        case sites::magazine_site:
        {
            b1.button_set(20, 20, 100, 150, &font1, "Back");
            b1.update(get_mous_pos());
            if (b1.is_pressed()){change_site(sites::logged_in_site);}
            b1.render(this->window);
            break;

        }
        case sites::password_reset_site:
        {

            if(!is_currently_changing_password) {



                input_bar1.set_limit(true, MAX_EMAIL_CHARACTERS);

                text1.Textline_set(650, 550, "Enter email. Verification key will be sent on this address", 50, &font1);
                b1.button_set(20, 20, 100, 150, &font1, "Back");
                b1.update(get_mous_pos());
                if (b1.is_pressed()) { change_site(sites::login_screen_site); }
                b1.render(this->window);

                b1.button_set(600, 600, 100, 700, &font1, "Email: " + input_bar1.get_text());
                b1.update(get_mous_pos());
                if (b1.is_pressed()) {make_input_bar_active(1);}
                b1.render(this->window);

                b4.button_set(600, 700, 100, 700, &font1, "Send verification email");
                b4.update(get_mous_pos());
                if (b4.is_pressed() && logging_menu.check_if_email_is_in_data_base(input_bar1.get_text())) {


                    if(!email_sent){  generate_code();mailbox.send_mail_with_verification_code(input_bar1.get_text(),verification_code);}
                    email_sent = true;


                    text1.Textline_set(650, 550, "Verification code is sent to this address", 50, &font1);

                } else if (b4.is_pressed() && !logging_menu.check_if_email_is_in_data_base(input_bar1.get_text())) {
                    text1.Textline_set(650, 550, "Invalid email", 50, &font1);

                }
                if (email_sent == true && is_currently_changing_password == false) {
                    input_bar2.set_limit(true, 3); // ver code is 4 characters long
                    text1.Textline_set(650, 550, "Verification code is sent to this address", 50, &font1);

                    b2.button_set(600, 300, 100, 700, &font1, "Ver. code: " + input_bar2.get_text());
                    b2.update(get_mous_pos());
                    if (b2.is_pressed()) {make_input_bar_active(2);}
                    b2.render(this->window);


                    b3.button_set(600, 400, 100, 700, &font1, "Check");
                    b3.update(get_mous_pos());
                    if (b3.is_pressed()) {
                        std::cout << "ver code " << verification_code << " your" << input_bar2.get_text();
                        if (input_bar2.get_text() == verification_code) {
                            text1.Textline_set(650, 550, "Verification code is correct", 50, &font1);
                            is_currently_changing_password = true;
                        }


                    }
                    b3.render(this->window);

                }
                b1.render(this->window);
                b4.render(this->window);
                text1.render(this->window);
            }else if(is_currently_changing_password){



                text1.Textline_set(650, 250, "Enter new password", 50, &font1);

                b1.button_set(20, 20, 100, 150, &font1, "Back");
                b1.update(get_mous_pos());
                if (b1.is_pressed()) { change_site(sites::login_screen_site); }
                b1.render(this->window);

                input_bar4.set_limit(true,MAX_PASSWORD_CHARACTERS);
                input_bar3.set_limit(true,MAX_PASSWORD_CHARACTERS);


                password="";
                for (int i =0; i<input_bar4.get_text().length();i++){
                    password+="*";
                }

                b4.button_set(600,300,100,700,&font1,"Password: " + password);
                b4.update(get_mous_pos());
                if(b4.is_pressed()){make_input_bar_active(4);}


                password_confirm="";
                for (int i =0; i<input_bar3.get_text().length();i++){
                    password_confirm+="*";
                }

                b3.button_set(600,400,100,700,&font1,"Repeat Password: " + password_confirm);
                b3.update(get_mous_pos());
                if(b3.is_pressed()){make_input_bar_active(3);}



                b5.button_set(600,500,100,700,&font1,"Change");
                b5.update(get_mous_pos());
                if(b5.is_pressed()){
                    if(input_bar3.get_text() != input_bar4.get_text())
                    {
                        text1.Textline_set(650, 250, "Passwords are not the same!", 50, &font1);

                    }
                    else if(input_bar3.get_text() == input_bar4.get_text()){
                        text1.Textline_set(650, 250, "Password changed!", 50, &font1);
                        worker_list.set_attribute(user_data_type::password,worker_list.get_login_with_mail(input_bar1.get_text()),input_bar3.get_text());


                    }

                }

                b4.render(this->window);
                b3.render(this->window);
                text1.render(this->window);
                b5.render(this->window);



            }


            break;



        }
        case sites::account_management_site:
        {

            input_bar1.set_limit(true,MAX_NAME_SURNAME_CHARACTERS);
            input_bar2.set_limit(true,MAX_NAME_SURNAME_CHARACTERS);
            input_bar3.set_limit(true,MAX_PASSWORD_CHARACTERS);
            input_bar4.set_limit(true,MAX_EMAIL_CHARACTERS);


            b1.button_set(20, 20, 100, 150, &font1, "Back");
            b1.update(get_mous_pos());
            if (b1.is_pressed()){change_site(sites::logged_in_site);};
            b1.render(this->window);
            text1.Textline_set(400, 200, "Your account", 50, &font1);



            b2.button_set(100,300,100,500,&font1,"Change Name");
            b2.update(get_mous_pos());
            b3.button_set(600,300,100,750,&font1,"New Name:" + input_bar1.get_text());
            b3.update(get_mous_pos());
            if(b3.is_pressed()){make_input_bar_active(1);}
            if(b2.is_pressed()){
                if(input_bar1.get_text() == "")
                {
                    text1.Textline_set(400, 200, "Name cannot be empty", 50, &font1);
                }
                else{
                    worker_list.set_attribute(user_data_type::name,logged_user->get_login(),input_bar1.get_text());
                    text1.Textline_set(400, 200, "Name changed", 50, &font1);
                }
            }


            b4.button_set(100,400,100,500,&font1,"Change Last Name");
            b4.update(get_mous_pos());
            b5.button_set(600,400,100,750,&font1,"New Last Name:" + input_bar2.get_text());
            b5.update(get_mous_pos());
            if(b5.is_pressed()){
                make_input_bar_active(2);
            }
            if(b4.is_pressed()){
                if(input_bar2.get_text() == "")
                {
                    text1.Textline_set(400, 200, "Last Name cannot be empty", 50, &font1);
                }
                else{
                    worker_list.set_attribute(user_data_type::surname,logged_user->get_login(),input_bar2.get_text());
                    text1.Textline_set(400, 200, "Last Name changed", 50, &font1);
                }
            }
            password="";
            for (int i =0; i<input_bar3.get_text().length();i++){
                password+="*";
            }

            b6.button_set(100,500,100,500,&font1,"Change Password");
            b6.update(get_mous_pos());
            b7.button_set(600,500,100,750,&font1,"New Password:" + password);
            b7.update(get_mous_pos());
            if(b7.is_pressed()){make_input_bar_active(3);}
            if(b6.is_pressed()){
                if(input_bar3.get_text() == "")
                {
                    text1.Textline_set(400, 200, "Password cannot be empty", 50, &font1);
                }
                else{
                    text1.Textline_set(400, 200, "Password changed", 50, &font1);
                    worker_list.set_attribute(user_data_type::password,logged_user->get_login(),input_bar3.get_text());



                }
            }

            b8.button_set(100,600,100,500,&font1,"Change Email");
            b8.update(get_mous_pos());
            b9.button_set(600,600,100,750,&font1,"New Email:" + input_bar4.get_text());
            b9.update(get_mous_pos());
            if(b9.is_pressed()){make_input_bar_active(4);}
            if(b8.is_pressed()){
                if(input_bar4.get_text() == "")
                {
                    text1.Textline_set(400, 200, "Email cannot be empty", 50, &font1);
                }
                else{
                    text1.Textline_set(400, 200, "Email changed", 50, &font1);
                    worker_list.set_attribute(user_data_type::mail,logged_user->get_login(),input_bar4.get_text());


                }
            }


            text1.render(this->window);
            b1.render(this->window);
            b2.render(this->window);
            b3.render(this->window);
            b4.render(this->window);
            b5.render(this->window);
            b6.render(this->window);
            b7.render(this->window);
            b8.render(this->window);
            b9.render(this->window);



            break;
        }
        case sites::calendar_display_site:
        {

            break;
        }
        case sites::admin_start_site:{

            b1.button_set(1000,600,100,400,&font1,"Log out");
            b1.update(get_mous_pos());
            if(b1.is_pressed()){
                is_logged = false;
                change_site(sites::start_site);}
            b1.render(this->window);

            b2.button_set(1000,500,100,400,&font1,"Employees");
            b2.update(get_mous_pos());
            if(b2.is_pressed()){change_site(sites::admin_site_employee_managent_site);}
            b2.render(this->window);

            b3.button_set(1000,400,100,400,&font1,"Magazine");
            b3.update(get_mous_pos());
            if(b3.is_pressed()){}
            b3.render(this->window);

            b4.button_set(1000,300,100,400,&font1,"Calendar");
            b4.update(get_mous_pos());
            if(b4.is_pressed()){}
            b4.render(this->window);
            break;
        }
        case sites::admin_site_employee_managent_site:{
            text2.Textline_set(0, 0, "", 50, &font1);
            switch(selected){
                case 0:
                    selected_string = "Login";
                    input_bar2.set_limit(true,MAX_LOGIN_CHARACTERS);
                    break;
                case 1:
                    selected_string = "Name";
                    input_bar2.set_limit(true,MAX_NAME_SURNAME_CHARACTERS);
                    break;
                case 2:
                    selected_string = "Surname";
                    input_bar2.set_limit(true,MAX_NAME_SURNAME_CHARACTERS);
                    break;
                case 3:
                    selected_string = "Email";
                    input_bar2.set_limit(true,MAX_EMAIL_CHARACTERS);
                    break;
                case 4:
                    selected_string = "Password";
                    input_bar2.set_limit(true,MAX_PASSWORD_CHARACTERS);
                    break;
                case 5:
                    selected_string = "Remove";
                    input_bar2.set_limit(true,MAX_PASSWORD_CHARACTERS);
                    break;
                case 6:
                    selected_string = "Position";
                    input_bar2.set_limit(true,1);
                    text2.Textline_set(920, 260, "Asystentka=0,Dentysta=1,Administrator=2,No_function=3", 35, &font1);
                    break;

            };


            b1.button_set(20, 20, 100, 150, &font1, "Back");
            b1.update(get_mous_pos());
            if (b1.is_pressed()) { change_site(sites::admin_start_site); }
            b1.render(this->window);
            int count = 0;
            std::string line = "";
            for (auto a : worker_list.get_worker()){
                if(count != 0 && count < 20) {


                 text1.Textline_set(10, 100 + (count * 20), set_table_line_for_admin_site(a.get_login(),a.get_name(),a.get_surname(),a.get_mail(),a.get_function()),30,&font1);
                 text1.render(this->window);

                }
                count++;
            }
            input_bar1.set_limit(true,MAX_LOGIN_CHARACTERS);

            text1.Textline_set(180, 50, "Select employee by nickname, choose type and enter value to change", 50, &font1);


            b2.button_set(900,300,100,500,&font1,"Enter login:" + input_bar1.get_text());
            b2.update(get_mous_pos());
            if(b2.is_pressed()){make_input_bar_active(1);}

            b3.button_set(900,400,100,500,&font1,"Selected: " + selected_string);
            b3.update(get_mous_pos());
            if(b3.is_pressed()){
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                selected++;
                if(selected > 6){selected = 0;}
                input_bar2.clear();

            }

            b4.button_set(900,500,100,500,&font1,"New:" + input_bar2.get_text());
            b4.update(get_mous_pos());
            if(b4.is_pressed()){make_input_bar_active(2);}

            b5.button_set(900,600,100,500,&font1,"Change!");
            b5.update(get_mous_pos());
            if(b5.is_pressed()){
                if(!logging_menu.check_if_login_exists(input_bar1.get_text())){
                    text2.Textline_set(920, 260, "No user with that login", 50, &font1);
                }
                else if(selected == 5 && input_bar1.get_text() == "" ){
                    /// REMOVE PERSON
                    text1.Textline_set(920, 220, "Removed!", 50, &font1);
                }
                else if(input_bar2.get_text() == "" || input_bar1.get_text() == "" )
                {
                    text2.Textline_set(920, 260, "Data or Login cannot be empty", 50, &font1);
                }
                else{
                    switch(selected){
                        case 0: /// CHANGE login
                            worker_list.set_attribute(user_data_type::login,input_bar1.get_text(),input_bar2.get_text());

                            break;
                        case 1:/// CHANGE NAME
                            worker_list.set_attribute(user_data_type::name,input_bar1.get_text(),input_bar2.get_text());
                            break;
                        case 2:
                            /// CHANGE SURNAME
                            worker_list.set_attribute(user_data_type::surname,input_bar1.get_text(),input_bar2.get_text());

                            break;
                        case 3:
                            /// CHANGE EMAIL
                            worker_list.set_attribute(user_data_type::mail,input_bar1.get_text(),input_bar2.get_text());

                            break;
                        case 4:
                            /// CHANGE PASSWORD
                            worker_list.set_attribute(user_data_type::password,input_bar1.get_text(),input_bar2.get_text());

                            break;
                        case 5:/// REMOVE
                            break;

                        case 6:
                            /// CHANGE POSITION
                            worker_list.set_attribute(user_data_type::position,input_bar1.get_text(),input_bar2.get_text());
                            break;


                    }

                    text3.Textline_set(920, 220, "Changed: " + selected_string + " to " + input_bar2.get_text(), 50, &font1);


                }
            }
            text1.render(this->window);
            text2.render(this->window);
            text3.render(this->window);
            b1.render(this->window);
            b2.render(this->window);
            b3.render(this->window);
            b4.render(this->window);
            b5.render(this->window);
            break;

        }
    }
    this->window->display();
}

/// to fix
std::string Okno::set_table_line_for_admin_site(std::string login,std::string name , std::string surname ,std::string mail,std::string fun){

    std::stringstream a_stream;
    a_stream << std::setiosflags ( std::ios_base::internal)
    << std::setw ( 30 ) <<login <<"\t"  << std::setw ( 30 )<<name<<"\t"  << std::setw ( 30 )<<surname<<"\t"  << std::setw ( 30 )<<mail<<"\t"  << std::setw ( 30 )<<fun;
    std::string the_string = a_stream.str();
    return the_string;

}

void Okno::update() { // checks for changes
    this->poll_events();
    this->update_mouse_position();
}

const bool Okno::get_window_is_open() const
{
    return this->window->isOpen();
}

void Okno::initialize_variables() {
    this->window = nullptr;
}

sf::Vector2f Okno::get_mous_pos()
{
    return sf::Vector2f(static_cast<float>(this->MousePosWindow.x), static_cast<float>(this->MousePosWindow.y));

}

void Okno::clear_site_and_wait(){ /// Makes breaks between jumping through sites and clears all drawable variables
    std::this_thread::sleep_for(std::chrono::milliseconds(20));

    b1.button_set(0,0,0,0,&font1,"");
    b2.button_set(0,0,0,0,&font1,"");
    b3.button_set(0,0,0,0,&font1,"");
    b4.button_set(0,0,0,0,&font1,"");
    b5.button_set(0,0,0,0,&font1,"");
    b6.button_set(0,0,0,0,&font1,"");
    b7.button_set(0,0,0,0,&font1,"");
    b8.button_set(0,0,0,0,&font1,"");
    b9.button_set(0,0,0,0,&font1,"");

    text1.Textline_set(0,0,"",0,&font1);
    text2.Textline_set(0,0,"",0,&font1);
    text3.Textline_set(0,0,"",0,&font1);
    text4.Textline_set(0,0,"",0,&font1);
    text5.Textline_set(0,0,"",0,&font1);

    input_bar1.set_Input_bar(0,0,0,sf::Color::White,false,&font1);
    input_bar2.set_Input_bar(0,0,0,sf::Color::White,false,&font1);
    input_bar3.set_Input_bar(0,0,0,sf::Color::White,false,&font1);
    input_bar4.set_Input_bar(0,0,0,sf::Color::White,false,&font1);

    input_bar1.clear();
    input_bar2.clear();
    input_bar3.clear();
    input_bar4.clear();
    /// also changes some staff to be reseted
    verification_code = "000000";
    email_sent =false;
    selected = 0;
    created_ac = false;
    std::string selected_string = "";
    is_currently_changing_password = false;
}

void Okno::generate_code() { /// generates verification code
    verification_code = std::to_string( 1000+rand()%9000);
}

void Okno::make_input_bar_active(int which_one){
    switch (which_one){

        case 1:{
            input_bar1.set_selected(true);
            input_bar2.set_selected(false);
            input_bar3.set_selected(false);
            input_bar4.set_selected(false);
            input_bar5.set_selected(false);
            break;
        }
        case 2:{
            input_bar1.set_selected(false);
            input_bar2.set_selected(true);
            input_bar3.set_selected(false);
            input_bar4.set_selected(false);
            input_bar5.set_selected(false);
            break;
        }
        case 3:{
            input_bar1.set_selected(false);
            input_bar2.set_selected(false);
            input_bar3.set_selected(true);
            input_bar4.set_selected(false);
            input_bar5.set_selected(false);
            break;
        }
        case 4:{
            input_bar1.set_selected(false);
            input_bar2.set_selected(false);
            input_bar3.set_selected(false);
            input_bar4.set_selected(true);
            input_bar5.set_selected(false);
            break;

        }

        case 5:{
            input_bar1.set_selected(false);
            input_bar2.set_selected(false);
            input_bar3.set_selected(false);
            input_bar4.set_selected(false);
            input_bar5.set_selected(true);
            break;

        }
       default:{
            input_bar1.set_selected(false);
            input_bar2.set_selected(false);
            input_bar3.set_selected(false);
            input_bar4.set_selected(false);
            break;
        }

    }



}