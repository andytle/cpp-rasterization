#ifndef __MODEL_H
#define __MODEL_H

#include <iostream>
#include "Vector2.h"
#include "Triangle2D.h"
#include <vector>
using namespace std;
class Model {
    public:
        Model();
        int NumTriangles();
        Triangle3D operator[ ](int i);
        void Transform(Matrix4 transform);
        void ReadFromOBJFile(string path, Color c);

    private:
        vector<Triangle3D> triangles;

};
#endif
