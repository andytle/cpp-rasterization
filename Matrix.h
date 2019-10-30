#ifndef __MATRIX_H
#define __MATRIX_H

#include <iostream>
#include "Vector2.h"

struct Matrix4 {

    float m11; float m21; float m31; float m41;
    float m12; float m22; float m32; float m42;
    float m13; float m23; float m33; float m43;
    float m14; float m24; float m34; float m44;

    Matrix4();
    Matrix4(float p11, float p21, float p31, float p41,
    		float p12, float p22, float p32, float p42,
			float p13, float p23, float p33, float p43,
			float p14, float p24, float p34, float p44);

    Vector4 operator*(const Vector4 & other);
    Matrix4 operator*(const Matrix4 & other);
};

Matrix4 Translate3D(float tX, float tY, float tZ);
Matrix4 Scale3D(float sX, float sY, float sZ);
Matrix4 RotateX3D(float degrees);
Matrix4 RotateY3D(float degrees);
Matrix4 RotateZ3D(float degrees);
Matrix4 Rotate3D(float degreesX, float degreesY, float degreesZ);
Matrix4 Rotate3D(float degrees, Vector4 vec);
#endif
