#include<iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "include/Draw/DrawLine.h"
#include "include/Draw/DrawTriangle.h"
#include "include/Draw/DrawPoint.h"
#include "include/3D/Model3D.h"
#include "include/camera.h"


int main()
{
    srand (static_cast <unsigned> (time(0)));
    sf::RenderWindow window(sf::VideoMode(600, 600), "Triangle Rasterization");
    
    Camera cam(1000, 500, 500);

    std::vector<Vec3> points;

    Model3D model;
    model.LoadFromFile("E:\\Temp\\source\\hero042.hero042_mat.shadergraph.obj");
    float moveSpeed = 5.0f;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        

        //control movements
        {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            for(int i=0; i < model.vertices.size(); i++)
            {
                model.vertices[i].x -= moveSpeed;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            for(int i=0; i < model.vertices.size(); i++)
            {
                model.vertices[i].x += moveSpeed;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            for(int i=0; i < model.vertices.size(); i++)
            {
                model.vertices[i].y += moveSpeed;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            for(int i=0; i < model.vertices.size(); i++)
            {
                model.vertices[i].y -= moveSpeed;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            for(int i=0; i < model.vertices.size(); i++)
            {
                model.vertices[i].z += moveSpeed;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            for(int i=0; i < model.vertices.size(); i++)
            {
                model.vertices[i].z -= moveSpeed;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Add))
        {
            for(int i=0; i < model.vertices.size(); i++)
            {
                model.vertices[i].x *= 1.01;
                model.vertices[i].y *= 1.01;
                model.vertices[i].z *= 1.01;

            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Subtract))
        {
            for(int i=0; i < model.vertices.size(); i++)
            {
                model.vertices[i].x *= 0.99;
                model.vertices[i].y *= 0.99;
                model.vertices[i].z *= 0.99;

            }
        }
        }

        window.clear();

        //renders a vertex points only grace
        //renders a barely recognizable mess
        // for(int i=0; i < model.vertices.size(); i++)
        // {
        //     Vec2 transformedPosition = cam.Transform(model.vertices[i]);
            
        //     float onScreenPosX = (transformedPosition.x + 1.0f) * (SCREEN_WIDTH / 2);
        //     float onScreenPosY = (transformedPosition.y + 1.0f) * (SCREEN_HEIGHT / 2);

        //     sf::Vertex v(sf::Vector2f(onScreenPosX, SCREEN_HEIGHT - onScreenPosY));
        //     v.color = sf::Color::Red;

        //     window.draw(&v, 1, sf::Points);
        // }

        /*-----------------------------------------------------------------------*/

        //drawing grace by draw lines between face triangle vertices
        //renders a beautiful wireframe grace
        // for(int i=0; i < model.triangles.size(); i++)
        // {
        //     //printf("Rendering triangles with indices %d %d %d\n", model.triangles[i].a,
        //     //model.triangles[i].b, model.triangles[i].c);

        //     Vec2 transformedA = cam.Transform(model.vertices[model.triangles[i].a - 1]);
        //     Vec2 transformedB = cam.Transform(model.vertices[model.triangles[i].b - 1]);
        //     Vec2 transformedC = cam.Transform(model.vertices[model.triangles[i].c - 1]);

        //     float onScreenPosAX = (transformedA.x + 1.0f) * (SCREEN_WIDTH / 2);
        //     float onScreenPosBX = (transformedB.x + 1.0f) * (SCREEN_WIDTH / 2);
        //     float onScreenPosCX = (transformedC.x + 1.0f) * (SCREEN_WIDTH / 2);

        //     float onScreenPosAY = (transformedA.y + 1.0f) * (SCREEN_HEIGHT / 2);
        //     float onScreenPosBY = (transformedB.y + 1.0f) * (SCREEN_HEIGHT / 2);
        //     float onScreenPosCY = (transformedC.y + 1.0f) * (SCREEN_HEIGHT / 2);

        //     onScreenPosAY = SCREEN_HEIGHT - onScreenPosAY;
        //     onScreenPosBY = SCREEN_HEIGHT - onScreenPosBY;
        //     onScreenPosCY = SCREEN_HEIGHT - onScreenPosCY;

        //     sf::Vertex lineAB[] = {
        //         sf::Vertex(sf::Vector2f(onScreenPosAX, onScreenPosAY)),
        //         sf::Vertex(sf::Vector2f(onScreenPosBX, onScreenPosBY))
        //     };

        //     lineAB[0].color = sf::Color::Red;
        //     lineAB[1].color = sf::Color::Red;


        //     sf::Vertex lineBC[] = {
        //         sf::Vertex(sf::Vector2f(onScreenPosBX, onScreenPosBY)),
        //         sf::Vertex(sf::Vector2f(onScreenPosCX, onScreenPosCY))
        //     };

        //     lineBC[0].color = sf::Color::Red;
        //     lineBC[1].color = sf::Color::Red;


        //     sf::Vertex lineCA[] = {
        //         sf::Vertex(sf::Vector2f(onScreenPosCX, onScreenPosCY)),
        //         sf::Vertex(sf::Vector2f(onScreenPosAX, onScreenPosAY))
        //     };

        //     lineCA[0].color = sf::Color::Red;
        //     lineCA[1].color = sf::Color::Red;

        //     window.draw(lineAB, 2, sf::Lines);
        //     window.draw(lineBC, 2, sf::Lines);
        //     window.draw(lineCA, 2, sf::Lines);


        // }

        /*-----------------------------------------------------------------------*/

        //drawing grace with vertex triangles
        //renders solid grace
        // for(int i=0; i < model.triangles.size(); i++)
        // {
        //     //printf("Rendering triangles with indices %d %d %d\n", model.triangles[i].a,
        //     //model.triangles[i].b, model.triangles[i].c);

        //     Vec2 transformedA = cam.Transform(model.vertices[model.triangles[i].a - 1]);
        //     Vec2 transformedB = cam.Transform(model.vertices[model.triangles[i].b - 1]);
        //     Vec2 transformedC = cam.Transform(model.vertices[model.triangles[i].c - 1]);

        //     float onScreenPosAX = (transformedA.x + 1.0f) * (SCREEN_WIDTH / 2);
        //     float onScreenPosBX = (transformedB.x + 1.0f) * (SCREEN_WIDTH / 2);
        //     float onScreenPosCX = (transformedC.x + 1.0f) * (SCREEN_WIDTH / 2);

        //     float onScreenPosAY = (transformedA.y + 1.0f) * (SCREEN_HEIGHT / 2);
        //     float onScreenPosBY = (transformedB.y + 1.0f) * (SCREEN_HEIGHT / 2);
        //     float onScreenPosCY = (transformedC.y + 1.0f) * (SCREEN_HEIGHT / 2);

        //     onScreenPosAY = SCREEN_HEIGHT - onScreenPosAY;
        //     onScreenPosBY = SCREEN_HEIGHT - onScreenPosBY;
        //     onScreenPosCY = SCREEN_HEIGHT - onScreenPosCY;

        //     sf::Vertex vertexA = sf::Vertex(sf::Vector2f(onScreenPosAX, onScreenPosAY));
        //     sf::Vertex vertexB = sf::Vertex(sf::Vector2f(onScreenPosBX, onScreenPosBY));
        //     sf::Vertex vertexC = sf::Vertex(sf::Vector2f(onScreenPosCX, onScreenPosCY));

        //     vertexA.color = sf::Color::Red;
        //     vertexB.color = sf::Color::Red;
        //     vertexC.color = sf::Color::Red;

        //     std::vector<sf::Vertex> verArr;

        //     verArr.push_back(vertexA);
        //     verArr.push_back(vertexB);
        //     verArr.push_back(vertexC);

        //     window.draw(&verArr[0], verArr.size(), sf::Triangles);
        // }

        /*-----------------------------------------------------------------------*/

        //drawing grace with default triangles
        //renders wild grace with all points attached to one another
        // std::vector<sf::Vertex> verArr;
        // for(int i=0; i < model.vertices.size(); i++)
        // {
        //     Vec2 transformedPosition = cam.Transform(model.vertices[i]);
            
        //     float onScreenPosX = (transformedPosition.x + 1.0f) * (SCREEN_WIDTH / 2);
        //     float onScreenPosY = (transformedPosition.y + 1.0f) * (SCREEN_HEIGHT / 2);

        //     sf::Vertex v = sf::Vertex(sf::Vector2f(onScreenPosX, SCREEN_HEIGHT - onScreenPosY));

        //     verArr.push_back(v);
        //     window.draw(&verArr[0], verArr.size(), sf::Triangles);

        // }

        window.display();
    }

    std::cin.get();
    return 0;
}