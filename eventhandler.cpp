void Scroll(sf::RenderWindow* window, sf::View* view, int Edge, float Velocity)
{

    sf::Vector2i localPosition = sf::Mouse::getPosition(*window);

    /*
    if (localPosition.x < edge) {view.move(-vel, 0); }
    if (localPosition.x > window.getSize().x - edge) {view.move(vel, 0); }
    */

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
