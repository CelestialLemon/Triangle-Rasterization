#pragma once
#include "Math/vec3.h"
class Camera
{
    //vs_size denotes vertical size of sensor and hs_size denotes horizontal
    float focalLength;
    float vs_size;
    float hs_size;

    //res_x and res_y denote horiontal and vertical resolutions respectively 
    int res_x;
    int res_y;

    public:
    Camera()
    {
        //default values
        focalLength = 50.0f;
        vs_size = 36.0f;
        hs_size = 64.0f;

    }

    Camera(float fl_input, float vs_input, float hs_input)
    {
        focalLength = fl_input;
        vs_size = vs_input;
        hs_size = hs_input;
    }

    Vec2 Transform(Vec3 vi)
    {
        //takes input of a 3d point and converts it to a 2d camera space point
        //y is multiplied by -1 to invert the image on y axis
        Vec2 v;
        v.x = (2 * focalLength * vi.x) / (hs_size * (focalLength + vi.z));
        v.y = (2 * focalLength * vi.y) / (hs_size * (focalLength + vi.z));
        return v;
    }

    sf::Vector2f ConvertWorldToScreen(Vec2 pos)
    {
        res_x = 600;
        res_y = 600;

        return sf::Vector2f((pos.x + 1.0f) * (res_x / 2), (pos.y + 1.0f) * (res_y / 2));
    }
};