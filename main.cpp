#include <iostream>
#include <SFML/Graphics.hpp>
#include "eventmanager.h"
#include "drawmanager.h"
#include "eventhandler.h"
#include <map>

int main()
{

    HackerTyper MainWindow(1600, 900, "GuseTyper");
    ReadFile("hack.txt", &MainWindow);
    MainWindow.AppStart();

    return 0;
}
