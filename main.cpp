#include "Color.h"
#include "Model.h"
#include "Raster.h"
#include "Triangle.h"
#include "Vector.h"

#include <iostream>
using namespace std;

int main()
{
    Raster myRaster(100, 100, White);
    Model teapot;
    Model bunny = Model();
    teapot.ReadFromOBJFile("teapot.obj", Red);
    bunny.ReadFromOBJFile("bunny.obj", Blue);

    Matrix4 modelMatrixTeapot = Translate3D(50,50,-30)
    							*RotateZ3D(45.0)
								*Scale3D(0.5,0.5,0.5);
    Matrix4 modelMatrixBunny = Translate3D(70,30,-60)
    							*RotateZ3D(-20.0)
								*Scale3D(500,500,500);
    Vector4 eye(50,50,30,1);
    Vector4 spot(50,50,-30,1);
    teapot.PerformBackfaceCulling(eye,spot);
    Matrix4 viewMatrix = LookAt(eye, spot,
								Vector4(0,1,0,0));
    Matrix4 perspectiveMatrix = Perspective(70.0,
    							myRaster.GetWidth()/myRaster.GetHeight(),
								0.01, 88.5);
    Matrix4 viewportMatrix = Viewport(0,0, myRaster.GetWidth(),
    									myRaster.GetHeight());
    teapot.Transform(perspectiveMatrix
    				*viewMatrix
					*modelMatrixTeapot);
    bunny.Transform(perspectiveMatrix
    				*viewMatrix
					*modelMatrixBunny);
    teapot.Homogenize();
    bunny.Homogenize();

    teapot.Transform(viewportMatrix);
    bunny.Transform(viewportMatrix);

    myRaster.DrawModel(teapot);
//    myRaster.DrawModel(bunny);
    myRaster.WriteToPPM();
    cin.get();
    return 0;
}

