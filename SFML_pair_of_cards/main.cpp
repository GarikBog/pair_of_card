#ifndef SF_GRAFIC
#include <SFML/Graphics.hpp>
#define SF_GRAFIC
#endif

#ifndef OBJECT
#include "object.h"
#define OBJECT
#endif




int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 800), "Pair of cards");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}