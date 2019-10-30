#include "Vector2.h"

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

Vector2::Vector2()
  : x(0.0), y(0.0){}

Vector2::Vector2(float px, float py)
  : x(px), y(py){}

Vector2 Vector2::operator+(const Vector2 & other){
	Vector2 new_vector;
    new_vector.x = this->x + other.x;
    new_vector.y = this->y + other.y;
    return new_vector;
}

Vector2 Vector2::operator-(const Vector2 & other){
	Vector2 new_vector;
    new_vector.x = this->x - other.x;
    new_vector.y = this->y - other.y;
    return new_vector;
}

Vector2 Vector2::operator*(float p){
	Vector2 new_vector;
    new_vector.x = p * this->x;
    new_vector.y = p * this->y;
    return new_vector;
}

float Vector2::Magnitude(){
	return sqrt((x*x + y*y));
}

float Vector2::Dot(Vector2 other){
	return x * other.x + y * other.y;
}

Vector2 Vector2::Perpendicular(){
	Vector2 result;
	result.x = -y;
	result.y = x;
	return result;
}

float Determinant(Vector2 a, Vector2 b){
	return b.x * a.y - a.x * b.y;
}
//////////////////////////////////////////////////////

Vector4::Vector4()
  : x(0.0), y(0.0), z(0.0), w(0.0){}

Vector4::Vector4(float px, float py, float pz, float pw)
  : x(px), y(py), z(pz), w(pw){}

Vector4 Vector4::operator+(const Vector4 & other){
	Vector4 new_vector;
    new_vector.x = this->x + other.x;
    new_vector.y = this->y + other.y;
    new_vector.z = this->z + other.z;
    new_vector.w = this->w + other.w;
    return new_vector;
}

Vector4 Vector4::operator-(const Vector4 & other){
	Vector4 new_vector;
    new_vector.x = this->x - other.x;
    new_vector.y = this->y - other.y;
    new_vector.z = this->z - other.z;
    new_vector.w = this->w - other.w;
    return new_vector;
}

Vector4 Vector4::operator*(float p){
	Vector4 new_vector;
    new_vector.x = p * this->x;
    new_vector.y = p * this->y;
    new_vector.z = p * this->z;
    new_vector.w = p * this->w;
    return new_vector;
}
//Vector4 Vector4::operator*(Matrix4 m){
//	Vector4 new_vector;
//    new_vector.x = this->x * m.m11 + this->x * m.m12 + this->x * m.m13 + this->x * m.m14;
//    new_vector.y = this->y * m.m21 + this->y * m.m22 + this->y * m.m23 + this->y * m.m24;
//    new_vector.z = this->z * m.m31 + this->z * m.m32 + this->z * m.m33 + this->z * m.m34;
//    new_vector.w = this->w * m.m41 + this->w * m.m42 + this->w * m.m43 + this->w * m.m44;
//    return new_vector;
//}

float Vector4::Magnitude(){
	return sqrt((x*x + y*y + z*z + w*w));
}

Vector4 Vector4::Normalize(){
	Vector4 new_vector;
	float magnitude = sqrt((x*x + y*y + z*z + w*w));
	new_vector.x = (1/magnitude) * this->x;
	new_vector.y = (1/magnitude) * this->y;
	new_vector.z = (1/magnitude) * this->z;
	new_vector.w = (1/magnitude) * this->w;
	return new_vector;
}

float Vector4::Dot(Vector4 other){
	return x * other.x + y * other.y;
}
void Vector4::print(){
	cout << "x: " << x << " " <<
			"y: " << y << " " <<
			"z: " << z << " " <<
			"w: " << w << endl;
}
