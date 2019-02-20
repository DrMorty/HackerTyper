#include "eventmanager.h"
#include <SFML/Graphics.hpp>
#include "eventhandler.h"


void HackerTyper::AppRun()
{
    sf::RenderWindow window(sf::VideoMode(Resolution.x, Resolution.y), Title);
    sf::View view( sf::FloatRect(0,0,1600,900));




    int counter = 0;
    int indicator = 0;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                TransformText(&counter, &indicator, &AppText, &TmpText);
            }
        }

        float Velocity = 0.05;
        int Edge = 30;

        window.clear();
        DrawTmpText(&window, "arial.ttf", TmpText);
        Scroll(&window, &view, 30, 0.05);


        window.setView(view);

        window.display();


    }

}
