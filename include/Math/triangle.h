#pragma once

#include "./vec3.h"

class Triangle
{
    public:
    //a b c are indices of vertices in vertices array that form the triangle
    //we dont store the actual position of the vertexes are multiple triangles can have the 
    //same vertex and hence we can reference with multiple times by storing it only once
    int a;
    int b;
    int c;

    Triangle(int ai, int bi, int ci)
    {
        a = ai;
        b = bi;
        c = ci;
    }
};