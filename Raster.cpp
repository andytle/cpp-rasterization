#include "Raster.h"
#include "Vector2.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

Raster::Raster()
  : width(0), height(0), pixels(NULL){  

}

Raster::Raster(int pWidth, int pHeight, Color pFillColor)
  : width(pWidth), height(pHeight){
  int size = width * height;
  pixels = new (nothrow) Color[size];
  if (pixels == nullptr){
      cout << "Error: the allocation of this block memory failed" << endl;
  }
  else {
    for (int i = 0; i < size; i++){
        pixels[i] = pFillColor;
    }
  }

}

Raster::~Raster(){
    delete [] pixels;
}

int Raster::GetWidth(){
    return width;
}

int Raster::GetHeight(){
    return height;
}

Color Raster::GetColorPixel(int x, int y){
    return pixels[width * (height-y-1) + x];
}

void Raster::SetColorPixel(int x, int y, Color pFillColor){
    pixels[width * (height-y-1) + x] = pFillColor;
}

void Raster::clear(Color pFillColor){
    for (int i = 0; i < width * height; i++){
        pixels[i] = pFillColor;
    }
}

void Raster::WriteToPPM(){
    ofstream img;
    img.open("andy1.ppm");
    img.clear();
    img << "P3" << endl;
    img << width << " " << height << endl;
    img << "255" << endl;
    for (int i = 0; i < width * height; i++){
        int r = pixels[i].red * 255;
        int g = pixels[i].green * 255;
        int b = pixels[i].blue * 255;
        img << r << " " << g << " " << b << endl;
    }
    img.close();
}

void Raster::DrawLine_DDA(float x1, float y1, float x2, float y2, Color fillColor){
    if (x1 == x2){ //vertical
        swap(x1, y1, x2, y2);
        x1 = round(x1);
        y1 = round(y1);
        for (int y = y1; y <= y2; y++){
            SetColorPixel(x1, round(y), fillColor);
        }
    }
    else{ //not vertical
        swap(x1, y1, x2, y2);
        float m = ((y2 - y1)/(x2 - x1)); //slope
        if (abs(m) <= 1){ //slope is less than 1
            x1 = round(x1);
            float y = round(y1);
            for (int x = x1; x <= x2; x++){
                SetColorPixel(x, round(y), fillColor);
                y += m;
            }
        }
        else {
            m = 1/m;
            y2 = round(y2);
            float x = round(x2);
            for (int y = y2; y >= y1; y--){
                SetColorPixel(round(x), y, fillColor);
                x -= m;
            }
        }
    }
}

void Raster::DrawLine_DDA_Interpolated(float x1, float y1, float x2, float y2, Color color1, Color color2){
    if (x1 == x2){ //vertical
        swap(x1, y1, x2, y2);
        Vector2 first(x2-x1,y2-y1);
        x1 = round(x1);
        y1 = round(y1);

        for (int y = y1; y <= y2; y++){
        	Vector2 point(x1,y);
        	float ratio = point.Magnitude()/first.Magnitude();
        	Color set = color2*ratio + color1*(1.0-ratio);
            SetColorPixel(x1, round(y), set);
        }
    }
    else{ //not vertical
        swap(x1, y1, x2, y2);
        Vector2 first(x2-x1,y2-y1);
        float m = ((y2 - y1)/(x2 - x1)); //slope

        if (abs(m) <= 1){ //slope is less than 1
            x1 = round(x1);
            float y = round(y1);
            for (int x = x1; x <= x2; x++){
            	Vector2 point(x,y1);
            	float ratio = point.Magnitude()/first.Magnitude();
            	Color set = color2*ratio + color1*(1.0-ratio);
                SetColorPixel(x, round(y), set);
                y += m;
            }
        }
        else {
            m = 1/m;
            y2 = round(y2);
            float x = round(x2);
            for (int y = y2; y >= y1; y--){
            	Vector2 point(x,y1);
            	float ratio = point.Magnitude()/first.Magnitude();
            	Color set = color2*ratio + color1*(1.0-ratio);
                SetColorPixel(x, round(y), set);
                x -= m;
            }
        }
    }
}

void Raster::swapVector2(Vector2 &v0, Vector2 &v1, Vector2 &v2){
    float centerX = (v0.x + v1.x + v2.x);
    float centerY = (v0.y + v1.y + v2.y);
    Vector2 center(centerX, centerY);
    float det = Determinant(v0 - center, v1 - center);
    if(det < 0){
        Vector2 temp = v1;
        v1 = v0;
        v0 = temp;
    }
}

void Raster::DrawTriangle2D_DotProduct(Triangle2D triangle){
	//swapVector2(triangle.v0, triangle.v1, triangle.v2);
	float minx = min(min(triangle.v0.x, triangle.v1.x), triangle.v2.x);
	float miny = min(min(triangle.v0.y, triangle.v1.y), triangle.v2.y);
	float maxx = max(max(triangle.v0.x, triangle.v1.x), triangle.v2.x);
	float maxy = max(max(triangle.v0.y, triangle.v1.y), triangle.v2.y);
	if (minx < 0) minx = 0;
	if (miny < 0) miny = 0;
	if (maxx > width) minx = width;
	if (maxy > height) minx = height;
	for(int x = minx; x <= maxx; x++){
		for(int y = miny; y <= maxy; y++){
			Vector2 p(x,y);
			SetColorPixel(x,y, Black);
			if (triangle.inside(p))
				SetColorPixel(x,y, Red);
		}
	}
}
void Raster::DrawTriangle3D_Barycentric(Triangle3D Tri3D){
	Triangle2D T(Tri3D);
	float minx = min(min(T.v0.x, T.v1.x), T.v2.x);
	float miny = min(min(T.v0.y, T.v1.y), T.v2.y);
	float maxx = max(max(T.v0.x, T.v1.x), T.v2.x);
	float maxy = max(max(T.v0.y, T.v1.y), T.v2.y);
	if (minx < 0) minx = 0;
	if (miny < 0) miny = 0;
	if (maxx > width) minx = width;
	if (maxy > height) minx = height;
	for(int x = minx; x <= maxx; x++){
		for(int y = miny; y <= maxy; y++){
			Vector2 p(x,y);
			float lambda0, lambda1, lambda2;
			T.CalculateBarycentricCoordinates(p, lambda0, lambda1, lambda2);
			if (lambda0 >= 0 && lambda1 >= 0 && lambda2 >= 0){
				Color setColor = T.c0*lambda0
								+ T.c1*lambda1
								+ T.c2*lambda2;
				SetColorPixel(x,y, setColor);
			}
		}
	}
}

void Raster::swap(float& x1, float& y1, float& x2, float& y2){
    if (x1 > x2){
        float temp_x, temp_y;
        temp_x = x1;
        x1 = x2;
        x2 = temp_x;
        temp_y = y1;
        y1 = y2;
        y2 = temp_y;
    }
    else if (x1 == x2) {
        if (y1 > y2){
        float temp_y;
        temp_y = y1;
        y1 = y2;
        y2 = temp_y;
        }
    }
}

void Raster::DrawModel(Model m){
	for (int i = 0; i < m.NumTriangles(); i++){
		DrawTriangle3D_Barycentric(m[i]);
	}
}
