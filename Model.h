#ifndef Model_H
#define Model_H

#include "Triangle.h"
#include "Matrix.h"
#include "Color.h"

#include <vector>
#include <string>
using namespace std;

class Model{

	private:
		vector<Triangle3D> triangles;
	
	public:
		Model();
		int NumTriangles();
		Triangle3D operator[](int i);
		void Transform(Matrix4 m);
		void ReadFromOBJFile(string filepath, Color pFillColor);
		void Homogenize();
		void PerformBackfaceCulling(Vector4 eye, Vector4 spot);

};

#endif
