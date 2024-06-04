#ifndef SF_GRAFIC
#include <SFML/Graphics.hpp>
#define SF_GRAFIC
#endif

#ifndef OBJECT
#include "object.h"
#define OBJECT
#endif


bool game_status = 0;

auto Do_smf = []() {
};

auto DrawGame = [](sf::RenderWindow& window) {

    return 0;
};

auto Game_start = [](sf::RenderWindow& window) {

};

auto Exit = [](sf::RenderWindow& window) {

    window.close();
};

void DrawMainMenu(sf::RenderWindow& window) {
    
    Object bg(0, 0, 800, 800, "textures/bg.jpg");
    TextButton start(150, 100, 500, "textures/test_texture.jpg",Game_start, "start", "fonts/ARIAL.TTF");
    TextButton exit(150, 400, 500, "textures/test_texture.jpg",Exit, "exit", "fonts/ARIAL.TTF");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                int mx = sf::Mouse::getPosition(window).x, my = sf::Mouse::getPosition(window).y;
                start.Do(mx, my,window);
                exit.Do(mx, my,window);
            }
        }

        window.clear();
        bg.Draw(window);
        start.Draw(window, sf::Mouse::getPosition(window));
        exit.Draw(window, sf::Mouse::getPosition(window));

        window.display();
    }

}



int main()
{
    try {
        sf::RenderWindow window(sf::VideoMode(800, 800), "Pair of cards");

        DrawMainMenu(window);
    }
    catch(std::exception ex){
    }
    return 0;
}
