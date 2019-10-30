#include "Matrix.h"
#include "Vector2.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

Matrix4::Matrix4()
: m11(0.0), m21(0.0), m31(0.0), m41(0.0),
  m12(0.0), m22(0.0), m32(0.0), m42(0.0),
  m13(0.0), m23(0.0), m33(0.0), m43(0.0),
  m14(0.0), m24(0.0), m34(0.0), m44(0.0){}

Matrix4::Matrix4(float p11, float p21, float p31, float p41,
		float p12, float p22, float p32, float p42,
		float p13, float p23, float p33, float p43,
		float p14, float p24, float p34, float p44){
	m11 = p11; m21 = p21; m31 = p31; m41 = p41;
	m12 = p12; m22 = p22; m32 = p32; m42 = p42;
	m13 = p13; m23 = p23; m33 = p33; m43 = p43;
	m14 = p14; m24 = p24; m34 = p34; m44 = p44;
}

Vector4 Matrix4::operator*(const Vector4 & other){
	Vector4 new_vector;
	new_vector.x = m11 * other.x + m21 * other.y + m31 * other.z
			+ m41 * other.w;
	new_vector.y = m12 * other.x + m22 * other.y + m32 * other.z
			+ m42 * other.w;
	new_vector.z = m13 * other.x + m23 * other.y + m33 * other.z
			+ m43 * other.w;
	new_vector.w = m14 * other.x + m24 * other.y + m34 * other.z
			+ m44 * other.w;

	return new_vector;
}

Matrix4 Matrix4::operator*(const Matrix4 & other){
	Matrix4 new_matrix;
	new_matrix.m11 = m11*other.m11 + m21*other.m12 + m31*other.m13 + m41*other.m14;
	new_matrix.m21 = m11*other.m21 + m21*other.m22 + m31*other.m23 + m41*other.m24;
	new_matrix.m31 = m11*other.m31 + m21*other.m32 + m31*other.m33 + m41*other.m34;
	new_matrix.m41 = m11*other.m41 + m21*other.m42 + m31*other.m43 + m41*other.m44;

	new_matrix.m12 = m12*other.m11 + m22*other.m12 + m32*other.m13 + m42*other.m14;
	new_matrix.m22 = m12*other.m21 + m22*other.m22 + m32*other.m23 + m42*other.m24;
	new_matrix.m32 = m12*other.m31 + m22*other.m32 + m32*other.m33 + m42*other.m34;
	new_matrix.m42 = m12*other.m41 + m22*other.m42 + m32*other.m43 + m42*other.m44;

	new_matrix.m13 = m13*other.m11 + m23*other.m12 + m33*other.m13 + m43*other.m14;
	new_matrix.m23 = m13*other.m21 + m23*other.m22 + m33*other.m23 + m43*other.m24;
	new_matrix.m33 = m13*other.m31 + m23*other.m32 + m33*other.m33 + m43*other.m34;
	new_matrix.m43 = m13*other.m41 + m23*other.m42 + m33*other.m43 + m43*other.m44;

	new_matrix.m14 = m14*other.m11 + m24*other.m12 + m34*other.m13 + m44*other.m14;
	new_matrix.m24 = m14*other.m21 + m24*other.m22 + m34*other.m23 + m44*other.m24;
	new_matrix.m34 = m14*other.m31 + m24*other.m32 + m34*other.m33 + m44*other.m34;
	new_matrix.m44 = m14*other.m41 + m24*other.m42 + m34*other.m43 + m44*other.m44;

	return new_matrix;
}

Matrix4 Translate3D(float tX, float tY, float tZ){
	Matrix4 translate_matrix(1,0,0,tX,
							 0,1,0,tY,
							 0,0,1,tZ,
							 0,0,0,1);
	return translate_matrix;
}
Matrix4 Scale3D(float sX, float sY, float sZ){
	Matrix4 scale_matrix(sX,0,0,0,
						 0,sY,0,0,
						 0,0,sZ,0,
						 0,0,0,1);

	return scale_matrix;
}
Matrix4 RotateX3D(float degrees){
	float rad = degrees * M_PI / 180.0;
	Matrix4 rotateX_matrix(1,0,0,0,
						   0,cos(rad),sin(rad),0,
						   0,-sin(rad),cos(rad),0,
						   0,0,0,1);
	return rotateX_matrix;
}
Matrix4 RotateY3D(float degrees){
	float rad = degrees * M_PI / 180.0;
	Matrix4 rotateY_matrix(cos(rad),0,-sin(rad),0,
						   0,1,0,0,
						   sin(rad),0,cos(rad),0,
						   0,0,0,1);
	return rotateY_matrix;
}
Matrix4 RotateZ3D(float degrees){
	float rad = degrees * M_PI / 180.0;
	Matrix4 rotateZ_matrix(cos(rad),sin(rad),0,0,
						   -sin(rad),cos(rad),0,0,
						   0,0,1,0,
						   0,0,0,1);
	return rotateZ_matrix;
}
Matrix4 Rotate3D(float degreesX, float degreesY, float degreesZ){
	return RotateX3D(degreesX) * RotateY3D(degreesY) * RotateZ3D(degreesZ);
}
Matrix4 Rotate3D(float degrees, Vector4 vec){
	float rad = degrees * M_PI / 180.0;
	float alpha = atan(vec.x/vec.z);
	float beta = acos(vec.y/vec.Magnitude());
	return RotateY3D(alpha)*RotateX3D(-beta)*RotateY3D(rad)*RotateX3D(beta)*RotateY3D(alpha);
}


