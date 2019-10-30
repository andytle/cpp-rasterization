#include "Triangle2D.h"
#include "Vector2.h"

#include <iostream>
#include <string>

using namespace std;

Triangle2D::Triangle2D()
  : v0(0.0,0.0), v1(0.0,0.0), v2(0.0,0.0),
	c0(1.0, 1.0, 1.0, 0.0), c1(1.0, 1.0, 1.0, 0.0), c2(1.0, 1.0, 1.0, 0.0){}

Triangle2D::Triangle2D(Vector2 pv0, Vector2 pv1, Vector2 pv2,
    		Color pc0, Color pc1, Color pc2){
	v0 = pv0;
	v1 = pv1;
	v2 = pv2;
	c0 = pc0;
	c1 = pc1;
	c2 = pc2;
}

Triangle2D::Triangle2D(Triangle3D T){
	Vector2 pv0(T.v0.x, T.v0.y);
	Vector2 pv1(T.v1.x, T.v1.y);
	Vector2 pv2(T.v2.x, T.v2.y);
	v0 = pv0;
	v1 = pv1;
	v2 = pv2;
	c0 = T.c0;
	c1 = T.c1;
	c2 = T.c2;
}

bool Triangle2D::inside(Vector2 point){

	Vector2 edge0 = v1 - v0;
	Vector2 edgep0 = edge0.Perpendicular();
	Vector2 g0 = point - v0;
	float result0 = edgep0.Dot(g0);

	Vector2 edge1 = v2 - v1;
	Vector2 edgep1 = edge1.Perpendicular();
	Vector2 g1 = point - v1;
	float result1 = edgep1.Dot(g1);

	Vector2 edge2 = v0 - v2;
	Vector2 edgep2 = edge2.Perpendicular();
	Vector2 g2 = point - v2;
	float result2 = edgep2.Dot(g2);

	return (result0>=0 && result1>=0 && result2>=0);
}
void Triangle2D::CalculateBarycentricCoordinates(Vector2 point,
    			float& lambda1, float& lambda2, float& lambda3){
	Vector2 p;
	Vector2 a;
	float area = Determinant((this->v1-this->v2), (this->v0-this->v1))/2;
	a = v1 - v2;
	p = point - v2;
	lambda1 = (Determinant(a, p)/2)/area;
	a = v0 - v2;
	p = point - v2;
	lambda2 = (Determinant(p, a)/2)/area;
	lambda3 = 1-lambda1-lambda2;
}
//////////////////////////////////////////
Triangle3D::Triangle3D()
  : v0(0.0,0.0,0.0,1.0), v1(0.0,0.0,0.0,1.0), v2(0.0,0.0,0.0,1.0),
	c0(1.0, 1.0, 1.0, 0.0), c1(1.0, 1.0, 1.0, 0.0), c2(1.0, 1.0, 1.0, 0.0){}

Triangle3D::Triangle3D(Vector4 pv0, Vector4 pv1, Vector4 pv2,
    		Color pc0, Color pc1, Color pc2){
	v0 = pv0;
	v1 = pv1;
	v2 = pv2;
	c0 = pc0;
	c1 = pc1;
	c2 = pc2;
}
void Triangle3D::Transform(Matrix4 m){
	v0 = m * v0;
	v1 = m * v1;
	v2 = m * v2;
//	v0.x = v0.x * m.m11 + v0.x * m.m12 + v0.x * m.m13 + v0.x * m.m14;
//	v0.y = v0.y * m.m21 + v0.y * m.m22 + v0.y * m.m23 + v0.y * m.m24;
//	v0.z = v0.z * m.m31 + v0.z * m.m32 + v0.z * m.m33 + v0.z * m.m34;
//	v0.w = v0.w * m.m41 + v0.w * m.m42 + v0.w * m.m43 + v0.w * m.m44;
//
//	v1.x = v1.x * m.m11 + v1.x * m.m12 + v1.x * m.m13 + v1.x * m.m14;
//	v1.y = v1.y * m.m21 + v1.y * m.m22 + v1.y * m.m23 + v1.y * m.m24;
//	v1.z = v1.z * m.m31 + v1.z * m.m32 + v1.z * m.m33 + v1.z * m.m34;
//	v1.w = v1.w * m.m41 + v1.w * m.m42 + v1.w * m.m43 + v1.w * m.m44;
//
//	v2.x = v2.x * m.m11 + v2.x * m.m12 + v2.x * m.m13 + v2.x * m.m14;
//	v2.y = v2.y * m.m21 + v2.y * m.m22 + v2.y * m.m23 + v2.y * m.m24;
//	v2.z = v2.z * m.m31 + v2.z * m.m32 + v2.z * m.m33 + v2.z * m.m34;
//	v2.w = v2.w * m.m41 + v2.w * m.m42 + v2.w * m.m43 + v2.w * m.m44;

}
