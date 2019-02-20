#include <iostream>
#include "eventmanager.h"
#include "drawmanager.h"

void ReadFile(std::string filename, HackerTyper* hackertyper)
{
    std::ifstream DATABASE(filename);
    while (!DATABASE.eof()) {std::string str; std::getline(DATABASE, str); hackertyper->AppText += str; hackertyper->AppText += "\n";}

}


void Scroll(sf::RenderWindow* window, sf::View* view, int Edge, float Velocity)
{

    sf::Vector2i localPosition = sf::Mouse::getPosition(*window);

    if (localPosition.y > window->getSize().y - Edge) {view->move(0, Velocity); }
    if (localPosition.y < Edge) {view->move(0, -Velocity); }

}

void TransformText(int* counter, int* indicator, std::string* AppText, std::string* TmpText)
{

    if (*indicator == 0)
    {
        for (int j = 0; j < 4; j++)
        {
            if ((*AppText)[j + *(counter)*4] == *"\0")
            {
                *indicator = 1;
                break;
            }
            else
            {
                *TmpText += (*AppText)[j + (*counter)*4];
            }
        }
        if(*indicator == 0){(*counter)++;}

    }

    fflush(0);


}



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

