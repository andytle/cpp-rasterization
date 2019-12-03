#ifndef Triangle_H
#define Triangle_H

#include "Vector.h"
#include "Color.h"
#include "Matrix.h"

struct Triangle3D;

struct Triangle2D{

	Vector3 v0;
	Vector3 v1;
	Vector3 v2;

	Color c0;
	Color c1;
	Color c2;

	Triangle2D();
	Triangle2D(Triangle3D other);
	Triangle2D(Vector3 pV0, Vector3 pV1, Vector3 pV2, Color pC0, Color pC1, Color pC2);
	void CalculateBarycentricCoordinates(Vector2 P, float& lambda1, float& lambda2, float& lambda3);
};

struct Triangle3D{

	Vector4 v0;
	Vector4 v1;
	Vector4 v2;

	Color c0;
	Color c1;
	Color c2;

	bool shouldDraw;

	Triangle3D();
	Triangle3D(Vector4 pV0, Vector4 pV1, Vector4 pV2, Color pC0, Color pC1, Color pC2, bool draw);

	void Transform(Matrix4 m);
	void Homogenize();

};

#endif
