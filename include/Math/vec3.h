#pragma once
class Vec3
{
public:
    float x;
    float y;
    float z;

    public:
    Vec3()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    Vec3(float xi, float yi, float zi)
    {
        x = xi;
        y = yi;
        z = zi;
    }
};