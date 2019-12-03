#include "Vector.h"
#include <math.h>

Vector2::Vector2(){
	x = 0.0;
	y = 0.0;
}

Vector2::Vector2(float pX, float pY){
	x = pX;
	y = pY;
}

Vector2::Vector2(Vector3 other){
	x = other.x;
	y = other.y;
}

Vector2 Vector2::operator*(float scalar){
	return Vector2(x*scalar, y*scalar);
}

Vector2 Vector2::operator+(Vector2 other){
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(Vector2 other){
	return Vector2(x - other.x, y - other.y);
}

float Vector2::Magnitude(){
	return sqrt((x*x) + (y*y));
}

float Vector2::Dot(Vector2 other){
	return (x*other.x) + (y*other.y);
}

Vector2 Vector2::Normalize(){
	Vector2 retVector(x, y);
	float mag = Magnitude();
	return retVector*(1 / mag);
}

Vector2 Vector2::Perpendicular(){
	return Vector2(-y, x);
}

float Determinant(Vector2 a, Vector2 b){
	return (b.x * a.y) - (a.x * b.y);
}

// ==========================================================================

Vector3::Vector3(){
	x = 0.0;
	y = 0.0;
	w = 0.0;
}

Vector3::Vector3(float pX, float pY, float pW){
	x = pX;
	y = pY;
	w = pW;
}

Vector3 Vector3::operator*(float scalar){
	return Vector3(x * scalar, y * scalar, w * scalar);
}

Vector3 Vector3::operator+(Vector3 other){
	return Vector3(x + other.x, y + other.y, w + other.w);
}

Vector3 Vector3::operator-(Vector3 other){
	return Vector3(x - other.x, y - other.y, w - other.w);
}

float Vector3::Magnitude(){
	return sqrt((x*x) + (y*y) + (w * w));
}

float Vector3::Dot(Vector3 other){
	return (x*other.x) + (y*other.y) + (w*other.w);
}

Vector3 Vector3::Normalize(){
	float mag = Magnitude();
	return Vector3(x / mag, y / mag, w / mag);
}

// ===============================================================

Vector4::Vector4(){
	x = 0.0;
	y = 0.0;
	z = 0.0;
	w = 0.0;
}

Vector4::Vector4(float pX, float pY, float pZ, float pW){
	x = pX;
	y = pY;
	z = pZ;
	w = pW;
}

Vector4 Vector4::operator*(float scalar){
	return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}

Vector4 Vector4::operator+(Vector4 other){
	return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
}

Vector4 Vector4::operator-(Vector4 other){
	return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
}

float Vector4::Magnitude(){
	return sqrt((x*x) + (y*y) + (z * z) + (w * w));
}

float Vector4::Dot(Vector4 other){
	return (x*other.x) + (y*other.y) + (z*other.z) + (w*other.w);
}

Vector4 Vector4::Normalize(){
	float mag = Magnitude();
	return Vector4(x / mag, y / mag, z / mag, w / mag);
}

Vector4 Vector4::Cross(Vector4 other){
	return Vector4(y*other.z - z*other.y,
				   z*other.x - x*other.z,
				   x*other.y - y*other.x,
					0);
}
