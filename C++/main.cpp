#define INCLUDED
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
#include "src/DrawClass.cpp"

int main()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8.0;

    RenderWindow window(VideoMode(1200, 1200), "Snake", Style::Default, settings);
    window.setVerticalSyncEnabled(true); // call it once, after creating the window  -- to control framerate

    Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;

    DrawClass d;
    float x = 1.f;
    float endx = 0, endy = 0;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        d.update(window, event);
        window.display();
    }

    return 0;
}