//
// Created by Mateusz on 04.01.2023.
//

#include "../includes/Input_bar.h"
Input_bar::Input_bar(){

}
void Input_bar::set_Input_bar(float posX,float posY,int size, sf::Color color, bool selected,sf::Font *font){
    sf_text_inputed.setCharacterSize(size);
    sf_text_inputed.setFillColor(color);
    is_selected = selected;
    this->font = font;
    sf_text_inputed.setFont(*this->font);
    sf_text_inputed.setPosition(static_cast<float>(posX),static_cast<float>(posY));


    if(is_selected){
        sf_text_inputed.setString("_");
    }
    else{
        sf_text_inputed.setString("");
    }


}

void Input_bar::set_Input_bar(float posX,float posY,int size, sf::Color color,sf::Font *font){
    sf_text_inputed.setCharacterSize(size);
    sf_text_inputed.setFillColor(color);

    this->font = font;
    sf_text_inputed.setFont(*this->font);
    sf_text_inputed.setPosition(static_cast<float>(posX),static_cast<float>(posY));


    if(is_selected){
        sf_text_inputed.setString("_");
    }
    else{
        sf_text_inputed.setString("");
    }


}

void Input_bar::clear(){
    sf_text_inputed.setString("");
    text.str("");


}

void Input_bar::input_logic(int char_typed) {
    if (char_typed != DELETE_KEY && char_typed != ESCAPE_KEY && char_typed != ENTER_KEY) {
        text << static_cast<char>(char_typed);

    } else if (char_typed == DELETE_KEY) {
        if (text.str().length() > 0) {
            delete_last_letter();
        }
    }
    else if (char_typed == ENTER_KEY) {
        set_selected(false);
    }
    sf_text_inputed.setString(text.str() +"_");
}

void Input_bar::delete_last_letter(){
    std::string t = text.str();
    std::string new_string = "";
    for(int i = 0; i <t.length()-1;i++){
        new_string+=t[i];
    }
    text.str("");
    text<<new_string;
    sf_text_inputed.setString(text.str());

}

void Input_bar::set_limit(bool has_limit_ToF){
    has_limit = has_limit_ToF;

}
void Input_bar::set_limit(bool has_limit_ToF, int limit){
    has_limit = has_limit_ToF;
    this->limit = limit;

}
void Input_bar::set_selected(bool selected) {
    is_selected = selected;
    if(!is_selected){
        std::string t = text.str();
        std::string new_string = "";
        for(int i = 0; i <t.length();i++){
            new_string+=t[i];
        }
        sf_text_inputed.setString(new_string);
    }
}

std::string Input_bar::get_text() {
    return text.str();

}

void Input_bar::render(sf::RenderTarget* target){
    target->draw(this->sf_text_inputed);
}


void Input_bar::typed_on(sf::Event input) {
    if(is_selected){
        int charTyped = input.text.unicode;

        std::cout<<charTyped;
        if(charTyped<128){
            if(has_limit){
                if(text.str().length() <= limit){
                    input_logic(input.text.unicode);
                }
                else if (text.str().length() > limit && charTyped == DELETE_KEY){
                    delete_last_letter();
                }
            }
            else {
                input_logic(charTyped);
            }
        }
    }
}



bool Input_bar::get_is_selected(){
    return is_selected;
}