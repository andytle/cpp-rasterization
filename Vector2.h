#ifndef __VECTOR2_H
#define __VECTOR2_H
#include <iostream>
#include <string>
struct Vector2 {

    float x;
    float y;

    Vector2();
    Vector2(float x, float y);

    float Magnitude();
    float Dot(Vector2 other);
    Vector2 Perpendicular();
    Vector2 operator*(float p);
    Vector2 operator+(const Vector2 & other);
    Vector2 operator-(const Vector2 & other);

};
struct Vector4 {

    float x;
    float y;
    float z;
    float w;

    Vector4();
    Vector4(float x, float y, float z, float w);

    float Magnitude();
    Vector4 Normalize();
    float Dot(Vector4 other);
    Vector4 operator*(float p);
    //Vector4 operator*(Matrix4 & m);
    Vector4 operator+(const Vector4 & other);
    Vector4 operator-(const Vector4 & other);
    void print();
};

float Determinant(Vector2 a, Vector2 b);

#endif
