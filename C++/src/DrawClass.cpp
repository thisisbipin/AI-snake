#ifndef INCLUDED
#include <iostream>
#include <math.h>
#include <utility>
#include "../SFML/include/SFML/Graphics.hpp"
using namespace sf;
using namespace std;
#endif

#include "./cell/Cell.cpp"

class Player : public Cell
{
    int width, height;
    float prevtime = 0;

public:
    Player(float x, float y, float width = 100, float height = 100) : Cell(x, y, width, height)
    {
        this->width = width;
        this->height = height;
        element.setFillColor(Color::Red);
    }
    void update(Vector2u window_size, Event &event, float x)
    {
        pair<float, float> direction{0, 0};
        if (x - prevtime < 0.075)
            return;
        prevtime = x;
        if (Keyboard::isKeyPressed(Keyboard::Left))
            direction.first = -1.f;
        if (Keyboard::isKeyPressed(Keyboard::Right))
            direction.first = 1.f;
        if (Keyboard::isKeyPressed(Keyboard::Up))
            direction.second = -1.f;
        if (Keyboard::isKeyPressed(Keyboard::Down))
            direction.second = 1.f;
        element.move(direction.first * width, direction.second * height);
        Vector2f position = element.getPosition();

        window_size.x -= (element.getSize().x);
        window_size.y -= (element.getSize().y);

        if (position.x < 0)
            position.x = 0;
        else if (position.x > window_size.x)
            position.x = window_size.x;
        if (position.y < 0)
            position.y = 0;
        else if (position.y > window_size.y)
            position.y = window_size.y;
        element.setPosition(position);
    }
    ~Player()
    {
    }
};

class DrawClass
{
    Cell *ground[10][10];
    Player *player;
    Clock *clock = NULL; // starts the clock

public:
    DrawClass() { setup(); }
    void setup()
    {
        int offset = 10;
        player = new Player(offset, offset);
        clock = new Clock();
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
            {
                ground[i][j] = new Cell(i * 100 + offset, j * 100 + offset, 100, 100);
                ground[i][j]->element.setFillColor(Color(10, i * 10, j * 10));
            }
    }
    void update(RenderWindow &window, Event &event)
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                window.draw(ground[i][j]->element);
        player->update(window.getSize(), event, clock->getElapsedTime().asSeconds());
        window.draw(player->element);
    }
    ~DrawClass()
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                delete (ground[i][j]);
        delete (player);
        delete (clock);
    }
};