#include <iostream>
#include <SFML/Graphics.hpp>
int main()
{
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString("Siema mati lubi natalke");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(250,270);
    sf::RenderWindow oknoAplikacji( sf::VideoMode( 800, 600, 32 ), "Kurs SFML - http://cpp0x.pl" );
    oknoAplikacji.setVerticalSyncEnabled(true);
    while( oknoAplikacji.isOpen())
    {
        oknoAplikacji.clear(sf::Color(sf::Color::White));
        oknoAplikacji.draw(text);
        oknoAplikacji.display();
        sf::Event event;
        while (oknoAplikacji.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                oknoAplikacji.close();
        }
    }
    return 0;
}

