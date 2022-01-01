#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Math/vec2.h"

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 600


void DrawPoint(Vec2 pos, sf::Color color, sf::RenderWindow* window)
{
    sf::RectangleShape point;

    float posOnScreenX = (pos.x + 1.0f) * (SCREEN_WIDTH / 2);
    float posOnScreenY = (pos.y + 1.0f) * (SCREEN_HEIGHT / 2);

    point.setFillColor(color);
    point.setPosition(sf::Vector2f(posOnScreenX, SCREEN_HEIGHT - posOnScreenY));
    point.setSize(sf::Vector2f(1.0f, 1.0f));

    window->draw(point);
}
