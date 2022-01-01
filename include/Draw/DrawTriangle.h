#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Math/vec2.h"
#include "DrawLine.h"

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 600

float Lerp(float a, float b, float factor)
{
    float result = (float)((b - a) * factor) + a;
    return result;
}

void DrawFlatBottomTriangle(Vec2 a, Vec2 b, Vec2 c, sf::Color color, sf::RenderWindow* window)
{
    float yTopWorld = a.y, yBotWorld = b.y;   //since flat bottom triangle b.y == c.y. Point in world units
    float yTopScreen = (a.y + 1.0f) * (SCREEN_HEIGHT / 2), yBotScreen = (b.y + 1.0f) * (SCREEN_HEIGHT / 2);

    yTopScreen = (int)yTopScreen;
    yBotScreen = (int)yBotScreen;

    float lineABdx = (b.x - a.x) / (a.y - b.y);
    float lineACdx = (c.x - a.x) / (a.y - c.y);

    float xLeft, xRight;
    for(int y = yTopScreen; y >= yBotScreen; y--)
    {
        float lerpFactor = (float)(yTopScreen - y) / (yTopScreen - yBotScreen);

        xLeft = Lerp(a.x, b.x, lerpFactor);
        xRight = Lerp(a.x, c.x, lerpFactor);

        xLeft = (xLeft + 1.0f) * (SCREEN_WIDTH / 2);
        xRight = (xRight + 1.0f) * (SCREEN_WIDTH / 2);       

        DrawLine(Vec2(xLeft, SCREEN_HEIGHT - y), Vec2(xRight, SCREEN_HEIGHT - y), color, window);
    } 

}

void DrawFlatTopTriangle(Vec2 a, Vec2 b, Vec2 c, sf::Color color, sf::RenderWindow* window)
{
    float yTopWorld = b.y, yBotWorld = a.y;   //since flat bottom triangle b.y == c.y. Point in world units
    float yTopScreen = (b.y + 1.0f) * (SCREEN_HEIGHT / 2), yBotScreen = (a.y + 1.0f) * (SCREEN_HEIGHT / 2);

    yTopScreen = (int)yTopScreen;
    yBotScreen = (int)yBotScreen;

    float lineABdx = (b.x - a.x) / (a.y - b.y);
    float lineACdx = (c.x - a.x) / (a.y - c.y);

    float xLeft, xRight;
    for(int y = yBotScreen; y <= yTopScreen; y++)
    {
        float lerpFactor = (float)(y - yBotScreen) / (yTopScreen - yBotScreen);

        xLeft = Lerp(a.x, b.x, lerpFactor);
        xRight = Lerp(a.x, c.x, lerpFactor);

        xLeft = (xLeft + 1.0f) * (SCREEN_WIDTH / 2);
        xRight = (xRight + 1.0f) * (SCREEN_WIDTH / 2);       

        DrawLine(Vec2(xLeft, SCREEN_HEIGHT - y), Vec2(xRight, SCREEN_HEIGHT - y), color, window);
    } 
}

void DrawTriangle(Vec2 a, Vec2 b, Vec2 c, sf::Color color, sf::RenderWindow* window)
{
    //sorting the point so that a is highest b is in middle and c is at bottom.
    //See how a triangle will be in refernce image.
    
    if(c.y > b.y)
    {
        Vec2 temp;
        temp = c;
        c = b;
        b = temp;
    }

    if(b.y > a.y)
    {
        Vec2 temp;
        temp = a;
        a = b;
        b = temp;
    }

    if(c.y > b.y)
    {
        Vec2 temp;
        temp = c;
        c = b;
        b = temp;
    }

    //swap so that b is on left and c on right
    Vec2 d;
    d.y = b.y;

    d.x = (((b.y - c.y)/(c.y - a.y)) * (c.x - a.x)) + c.x;

    DrawFlatBottomTriangle(a, b, d, color, window);
    DrawFlatTopTriangle(c, b , d, color, window);

}