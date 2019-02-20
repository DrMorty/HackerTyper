#include <iostream>
#include <SFML/Graphics.hpp>
#include "eventmanager.h"
#include "drawmanager.h"
#include "eventhandler.h"
#include <map>

int main()
{

    HackerTyper MainWindow(1600, 900, "Hahakektyper");
    ReadFile("hack.txt", &MainWindow);
    MainWindow.AppRun();

    return 0;
}
