#ifndef SF_GRAFIC
#include <SFML/Graphics.hpp>
#define SF_GRAFIC
#endif

#ifndef OBJECT
#include "object.h"
#define OBJECT
#endif



sf::Sprite Bg;
sf::Texture Bg_texture;


auto Do_smf = []() {
};






int main()
{
try {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Pair of cards");

    Bg_texture.loadFromFile("bg.jpg");

    Bg.setTexture(Bg_texture);
    Bg.setPosition(0, 0);
    Bg.setTextureRect(sf::IntRect(0, 0, 800, 800));

    TextButton but1(50,50,700,"textures/test_texture.jpg",Do_smf,"p","fonts/ARIAL.TTF");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(Bg);
        but1.Draw(window, sf::Mouse::getPosition(window));
        window.display();
    }


        }
        catch(std::exception ex){
        }
    return 0;
}