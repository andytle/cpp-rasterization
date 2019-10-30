#ifndef __RASTER_H
#define __RASTER_H

#include "Color.h"
#include "Triangle2D.h"
#include "Model.h"
#include <iostream>

using namespace std;
class Raster {
    public:
        Raster();
        Raster(int pWidth, int pHeight, Color pFillColor);
        ~Raster();
        //checkpoint 1
        int GetWidth();
        int GetHeight();
        Color GetColorPixel(int x, int y);
        void SetColorPixel(int x, int y, Color pFillColor);
        void clear(Color pFillColor);
        void WriteToPPM();
        void DrawLine_DDA(float x1, float y1, float x2, float y2, Color fillColor);
        void swap(float &x1, float &y1, float &x2, float &y2);
        //checkpoint 2
        void DrawLine_DDA_Interpolated(float x1, float y1,
        								float x2, float y2,
										Color color1, Color color2);
        void swapVector2(Vector2 &v0, Vector2 &v1, Vector2 &v2);
        void DrawTriangle2D_DotProduct(Triangle2D triangle);
        void DrawTriangle3D_Barycentric(Triangle3D Tri3D);
        //checkpoint3
        void DrawModel(Model m);
    private:
        int width;
        int height;
        Color* pixels;

};

#endif
