#include "Triangle.h"
#include <math.h>

Triangle2D::Triangle2D(){
	v0 = Vector3(0.0, 0.0, 1.0);
	v1 = Vector3(0.0, 0.0, 1.0);
	v2 = Vector3(0.0, 0.0, 1.0);
	c0 = Transparent;
	c1 = Transparent;
	c2 = Transparent;
}

Triangle2D::Triangle2D(Triangle3D other){
	v0 = Vector3(other.v0.x, other.v0.y, 1);
	v1 = Vector3(other.v1.x, other.v1.y, 1);
	v2 = Vector3(other.v2.x, other.v2.y, 1);
	c0 = other.c0;
	c1 = other.c1;
	c2 = other.c2;
}

Triangle2D::Triangle2D(Vector3 pV0, Vector3 pV1, Vector3 pV2, Color pC0, Color pC1, Color pC2){
	v0 = pV0;
	v1 = pV1;
	v2 = pV2;
	c0 = pC0;
	c1 = pC1;
	c2 = pC2;
}

void Triangle2D::CalculateBarycentricCoordinates(Vector2 P, float& lambda1, float& lambda2, float& lambda3){

	lambda1 = Determinant(v1 - v2, P - v2) / Determinant(v1 - v2, v0 - v2);
	lambda2 = Determinant(P - v2, v0 - v2) / Determinant(v1 - v2, v0 - v2);
	lambda3 = 1.0 - lambda1 - lambda2;

}

Triangle3D::Triangle3D(){
	v0 = Vector4(0.0, 0.0, 0.0, 1.0);
	v1 = Vector4(0.0, 0.0, 0.0, 1.0);
	v2 = Vector4(0.0, 0.0, 0.0, 1.0);
	c0 = Transparent;
	c1 = Transparent;
	c2 = Transparent;
	shouldDraw = true;
}

Triangle3D::Triangle3D(Vector4 pV0, Vector4 pV1, Vector4 pV2, Color pC0, Color pC1, Color pC2, bool draw){
	v0 = pV0;
	v1 = pV1;
	v2 = pV2;
	c0 = pC0;
	c1 = pC1;
	c2 = pC2;
	shouldDraw = draw;
}

void Triangle3D::Transform(Matrix4 m){
	v0 = m * v0;
	v1 = m * v1;
	v2 = m * v2;
}
