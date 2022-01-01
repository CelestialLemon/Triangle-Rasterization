#include<iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "include/Draw/DrawLine.h"
#include "include/Draw/DrawTriangle.h"
#include "include/Draw/DrawPoint.h"
#include "include/camera.h"


int main()
{
    srand (static_cast <unsigned> (time(0)));
    sf::RenderWindow window(sf::VideoMode(600, 600), "Triangle Rasterization");
    
    Camera cam(0.5f, 1.0f, 1.0f);
    
    std::vector<Vec3> points;
    
    Vec3 a(-1, 1, 4); 
    Vec3 b(1, 1, 4);
    Vec3 c(-1, -1, 4);
    Vec3 d(1, -1, 4);
    Vec3 e(-1, 1, 8); 
    Vec3 f(1, 1, 8);
    Vec3 g(-1, -1, 8);
    Vec3 h(1, -1, 8);

    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    points.push_back(d);
    points.push_back(e);
    points.push_back(f);
    points.push_back(g);
    points.push_back(h);

    float moveSpeed = 0.005f;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            for(int i=0; i < points.size(); i++)
            {
                points[i].x -= moveSpeed;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            for(int i=0; i < points.size(); i++)
            {
                points[i].x += moveSpeed;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            for(int i=0; i < points.size(); i++)
            {
                points[i].y += moveSpeed;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            for(int i=0; i < points.size(); i++)
            {
                points[i].y -= moveSpeed;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            for(int i=0; i < points.size(); i++)
            {
                points[i].z += moveSpeed;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            for(int i=0; i < points.size(); i++)
            {
                points[i].z -= moveSpeed;
            }
        }
        
        for(int i=0; i < points.size(); i++)
        {
            DrawPoint(cam.Transform(points[i]), sf::Color::Red, &window);
        }

        // DrawLine(cam.Transform(points[0]), cam.Transform(points[1]), sf::Color::Red, &window);
        // DrawLine(cam.Transform(points[1]), cam.Transform(points[5]), sf::Color::Red, &window);
        // DrawLine(cam.Transform(points[5]), cam.Transform(points[4]), sf::Color::Red, &window);
        // DrawLine(cam.Transform(points[4]), cam.Transform(points[0]), sf::Color::Red, &window);

        // DrawLine(cam.Transform(points[0]), cam.Transform(points[2]), sf::Color::Red, &window);
        // DrawLine(cam.Transform(points[1]), cam.Transform(points[3]), sf::Color::Red, &window);
        // DrawLine(cam.Transform(points[5]), cam.Transform(points[7]), sf::Color::Red, &window);
        // DrawLine(cam.Transform(points[4]), cam.Transform(points[6]), sf::Color::Red, &window);

        // DrawLine(cam.Transform(points[2]), cam.Transform(points[3]), sf::Color::Red, &window);
        // DrawLine(cam.Transform(points[3]), cam.Transform(points[7]), sf::Color::Red, &window);
        // DrawLine(cam.Transform(points[7]), cam.Transform(points[6]), sf::Color::Red, &window);
        // DrawLine(cam.Transform(points[6]), cam.Transform(points[2]), sf::Color::Red, &window);

        sf::Vertex line1[] = {
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[0]))),
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[1])))
        };

        sf::Vertex line2[] = {
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[1]))),
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[5])))
        };

        sf::Vertex line3[] = {
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[5]))),
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[4])))
        };

        sf::Vertex line4[] = {
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[4]))),
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[0])))
        };
        //////////

        sf::Vertex line5[] = {
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[0]))),
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[2])))
        };

        sf::Vertex line6[] = {
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[1]))),
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[3])))
        };

        sf::Vertex line7[] = {
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[5]))),
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[7])))
        };

        sf::Vertex line8[] = {
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[4]))),
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[6])))
        };

        ///////////////

        sf::Vertex line9[] = {
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[2]))),
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[3])))
        };

        sf::Vertex line10[] = {
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[3]))),
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[7])))
        };

        sf::Vertex line11[] = {
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[7]))),
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[6])))
        };

        sf::Vertex line12[] = {
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[6]))),
            sf::Vertex(cam.ConvertWorldToScreen(cam.Transform(points[2])))
        };

        window.draw(line1, 2, sf::Lines);
        window.draw(line2, 2, sf::Lines);
        window.draw(line3, 2, sf::Lines);
        window.draw(line4, 2, sf::Lines);
        window.draw(line5, 2, sf::Lines);
        window.draw(line6, 2, sf::Lines);
        window.draw(line7, 2, sf::Lines);
        window.draw(line8, 2, sf::Lines);
        window.draw(line9, 2, sf::Lines);
        window.draw(line10, 2, sf::Lines);
        window.draw(line11, 2, sf::Lines);
        window.draw(line12, 2, sf::Lines);

        //DrawPoint(cam.Transform(a), sf::Color::Red, &window);
        window.display();
    }

    std::cin.get();
    return 0;
}