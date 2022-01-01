#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include "../Math/vec3.h"
#include "../Math/triangle.h"

class Model3D
{
    public:
    std::vector<Vec3> vertices;
    std::vector<Triangle> triangles;

    Model3D()
    {
       //default contructor 
    }

    void LoadFromFile(std::string filepath)
    {
        std::ifstream readStream(filepath);

        //text stores the text read from each line while reading file
        std::string text;
        while(getline(readStream, text))
        {
            //if line starts with a v it is a vertex
            if(text.rfind("v ", 0) == 0)
            {
                std::vector<std::string> words;
                
                std::string splitter = " ";
                size_t pos = 0;

                //split the line text at a " " i.e space
                while ((pos = text.find(splitter)) != std::string::npos) {
                words.push_back(text.substr(0, pos));
                text.erase(0, pos + splitter.length());
                }

                //the position of the vertex is given by 1st 2nd and 3rd segements of the splitted string
                float x = std::stof(words[1]);
                float y = std::stof(words[2]);
                float z = std::stof(words[3]);
                
                //push the vertex into array of model
                vertices.push_back(Vec3(x, y, z));
            }

            //if the line begins with f then the info is about a face
            if(text.rfind("f ", 0) == 0)
            {
                std::vector<std::string> words;
                
                std::string splitter = " ";
                size_t pos = 0;

                //split the line by " " i.e space
                while ((pos = text.find(splitter)) != std::string::npos) {
                words.push_back(text.substr(0, pos));
                text.erase(0, pos + splitter.length());
                }

                /*
                The face data is in form of line
                f v/vn/vt v/vn/vt v/vn/vt
                where,  
                first v is index of first vertex in triangle
                second v is index of second vertex in triangle
                third v is index of third vertex in triangle

                So first split the main string by space
                then split the substrings by / and take the first segment to get indices of all the 
                vertexes in the triangle
                */

               //tvi stands for triange vertex
                std::vector<std::string> tvi;

                tvi.push_back(words[1].substr(0, words[1].find("/")));
                tvi.push_back(words[2].substr(0, words[1].find("/")));
                tvi.push_back(words[3].substr(0, words[1].find("/")));

                //push the triangle data into array
                triangles.push_back(Triangle(stoi(tvi[0]), stoi(tvi[1]), stoi(tvi[2])));
            }


        }
        printf("Read total of %d vertices\n", vertices.size());
        printf("Read total of %d triangle\n", triangles.size());
    }

    void PrintVertices()
    {
        for(int i=0; i < vertices.size(); i++)
        {
            printf("Vertex x : %.2f y : %.2f z : %.2f \n", vertices[i].x, vertices[i].y, vertices[i].z);
        }
    }
 
};