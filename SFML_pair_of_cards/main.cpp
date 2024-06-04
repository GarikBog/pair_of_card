#ifndef SF_GRAFIC
#include <SFML/Graphics.hpp>
#define SF_GRAFIC
#endif

#ifndef OBJECT
#include "object.h"
#define OBJECT
#endif




void Draw_Main_Menu(sf::RenderWindow& window);

void Draw_Game(sf::RenderWindow& window);
auto Do_smf = [](sf::RenderWindow& window) {
};



auto Game_start = [](sf::RenderWindow& window) {
    window.clear();
    Draw_Game(window);
};

auto Exit = [](sf::RenderWindow& window) {
    window.close();
};

void Draw_Game(sf::RenderWindow& window) {
    const unsigned int size_card = 175;

    Object bg(0, 0, 800, 800, "textures/game_bg.jpg");
    TextButton return_to_menu(450, 650, 300, "textures/test_texture.jpg", Do_smf, "menu", "fonts/ARIAL.TTF");

    TextButton exit(50, 650, 300, "textures/test_texture.jpg", Exit, "exit", "fonts/ARIAL.TTF");


    Button* cards[4][3];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 3; ++j) {
            Button* test = new Button(27 + (size_card + 15) * i, 50 + (size_card + 15) * j,size_card,size_card, "textures/error.jpg", Do_smf);
            cards[i][j] = test;
        }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                for (int i =0;i<4;++i)
                    for(int j =0;j<3;++j){
                        delete cards[i][j];
                    }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                int mx = sf::Mouse::getPosition(window).x, my = sf::Mouse::getPosition(window).y;
                exit.Do(mx, my, window);
                if (return_to_menu.Mouse_on(mx, my)) {
                    return;
                }
                for (int i = 0; i < 4; ++i)
                    for (int j = 0; j < 3; ++j) {
                        cards[i][j]->Do(mx, my, window);
                    }

            }
        }

        window.clear();
        bg.Draw(window);
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 3; ++j) {
                cards[i][j]->Draw(window);
            }
        exit.Draw(window, sf::Mouse::getPosition(window));
        return_to_menu.Draw(window, sf::Mouse::getPosition(window));

        window.display();
    }
}
void Draw_Main_Menu(sf::RenderWindow& window) {
    
    Object bg(0, 0, 800, 800, "textures/bg.jpg");
    TextButton start(150,150, 500, "textures/test_texture.jpg",Game_start, "start", "fonts/ARIAL.TTF");
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

        Draw_Main_Menu(window);
    }
    catch(std::exception ex){
    }
    return 0;
}
