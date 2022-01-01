#pragma once
#include<SFML/Graphics.hpp>
#include<cmath>
#include <iostream>

#include "../Math/vec2.h"

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 600

float FindNormalizeFactor(float dy, float dx)
{
    float absDy = abs(dy);
    float absDx = abs(dx);
    if (absDy > absDx)
    {
        return absDy;
    }
    else if (absDx > absDy)
    {
        return absDx;
    }
    else
    {
        //since both are same the normalizing factor is dy or dx
        return absDy;
    }
}

void DrawLine(Vec2 a, Vec2 b, sf::Color color, sf::RenderWindow* window)
{
    //using rasterization algorithm
    //converting world points to screen points
    b.y = (b.y + 1.0f) * (SCREEN_HEIGHT / 2);
    b.x = (b.x + 1.0f) * (SCREEN_WIDTH / 2);
    a.y = (a.y + 1.0f) * (SCREEN_HEIGHT / 2);
    a.x = (a.x + 1.0f) * (SCREEN_WIDTH / 2);

    a.x = round(a.x);
    a.y = round(a.y);
    b.x = round(b.x);
    b.y = round(b.y);


    float dy = b.y - a.y;
    float dx = b.x - a.x;

    

    float normalizeFactor = FindNormalizeFactor(dy, dx);

    dy /= normalizeFactor;
    dx /= normalizeFactor;

    Vec2 newPoint(a.x, a.y);

    if(dy == 0 || dx == 0)
    {
        while(newPoint.x != b.x || newPoint.y != b.y)
        {
            sf::RectangleShape pixel;
            
            pixel.setSize(sf::Vector2f(1.0f, 1.0f));
            pixel.setFillColor(color);
            pixel.setPosition(sf::Vector2f(newPoint.x, newPoint.y));
            
            window->draw(pixel);

            newPoint.x += dx;
            newPoint.y += dy;
        }
    }
    else
    {
        while(newPoint.x != b.x && newPoint.y != b.y)
        {
            sf::RectangleShape pixel;
            
            pixel.setSize(sf::Vector2f(1.0f, 1.0f));
            pixel.setFillColor(color);
            pixel.setPosition(sf::Vector2f(newPoint.x, newPoint.y));
            
            window->draw(pixel);

            newPoint.x += dx;
            newPoint.y += dy;
        }
    }
}