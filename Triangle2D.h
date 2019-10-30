#ifndef __Triangle2_H
#define __Triangle2_H

#include <iostream>
#include "Vector2.h"
#include "Color.h"
#include "Matrix.h"
struct Triangle3D {

    Vector4 v0;
    Vector4 v1;
    Vector4 v2;
    Color c0;
    Color c1;
    Color c2;

    Triangle3D();
    Triangle3D(Vector4 v0, Vector4 v1, Vector4 v2,
    		Color c0, Color c1, Color c2);
    void Transform(Matrix4 transform);

};
/////////////////////////////////
struct Triangle2D {

    Vector2 v0;
    Vector2 v1;
    Vector2 v2;
    Color c0;
    Color c1;
    Color c2;

    Triangle2D();
    Triangle2D(Vector2 v0, Vector2 v1, Vector2 v2,
    		Color c0, Color c1, Color c2);
    Triangle2D(Triangle3D T);
    bool inside(Vector2 point);
    void CalculateBarycentricCoordinates(Vector2 point,
    			float& lambda1, float& lambda2, float& lambda3);
};

//////

#endif
