#include "drawmanager.h"
#include <SFML/Graphics.hpp>


void DrawTmpText(sf::RenderWindow* window, std::string fontPath, std::string TmpText)
{
    sf::Font font;
    font.loadFromFile(fontPath);

    sf::Text text(TmpText, font, 15);

    text.setOutlineColor(sf::Color::Red);
    text.setFillColor(sf::Color::Red);

    text.setPosition(0, 0);



    window->draw(text);

}
