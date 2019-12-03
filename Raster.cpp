#include "Raster.h"
#include <fstream>
#include <math.h>
#include <limits>
	using namespace std;

Raster::Raster(){
	height = 0;
	width = 0;
	colorPixels = nullptr;
	depthPixels = nullptr;
}

Raster::Raster(int pWidth, int pHeight, Color pFillColor){
	width = pWidth;
	height = pHeight;
	int totalPixels = width * height;
	colorPixels = new Color[totalPixels];
	depthPixels = new float[totalPixels];
	for (int i = 0; i < totalPixels; i++){
		colorPixels[i] = pFillColor;
	}
	for (int i = 0; i < totalPixels; i++){
		depthPixels[i] = numeric_limits<float>::max();
	}
}

void Model::Homogenize(){
	for (int i = 0; i < triangles.size(); i++){
		triangles[i].v0 = (triangles[i].v0)*(1/(triangles[i].v0.w));
		triangles[i].v1 = (triangles[i].v1)*(1/(triangles[i].v1.w));
		triangles[i].v2 = (triangles[i].v2)*(1/(triangles[i].v2.w));
		}
}

void Model::PerformBackfaceCulling(Vector4 eye, Vector4 spot){
	for (int i = 0; i < triangles.size(); i++){
		Vector4 a = triangles[i].v2 - triangles[i].v1;
		Vector4 b = triangles[i].v0 - triangles[i].v1;
		Vector4 normal = a.Cross(b).Normalize();
		if ((spot-eye).Dot(normal) < 0.0){
			triangles[i].shouldDraw = false;
			triangles[i].c0 = Blue;
			triangles[i].c1 = Blue;
			triangles[i].c2 = Blue;
		}
	}
}


Raster::~Raster(){
	delete[] colorPixels;
	delete[] depthPixels;
}

int Raster::GetWidth(){
	return width;
}

int Raster::GetHeight(){
	return height;
}

Color Raster::GetColorPixel(int x, int y){
	int totalPixels = width * height;
	int idx = ((height - y - 1) * width) + x;
	if (idx >= 0 && idx < totalPixels){
		return colorPixels[idx];
	}
	else
		return Transparent;
}

float Raster::GetDepthPixel(int x, int y){
	int totalPixels = width * height;
	int idx = ((height - y - 1) * width) + x;
	if (idx >= 0 && idx < totalPixels){
		return depthPixels[idx];
	}
	else
		return numeric_limits<float>::max();
}

void Raster::SetColorPixel(int x, int y, Color pFillColor){
	int totalPixels = width * height;
	int idx = ((height - y - 1) * width) + x;
	if (idx >= 0 && idx < totalPixels){
		colorPixels[idx] = pFillColor;
	}
}

void Raster::SetDepthPixel(int x, int y, float d){
	int totalPixels = width * height;
	int idx = ((height - y - 1) * width) + x;
	if (idx >= 0 && idx < totalPixels){
		depthPixels[idx] = d;
	}
}

void Raster::Clear(Color pFillColor){
	int totalPixels = width * height;
	for (int i = 0; i < totalPixels; i++){
		colorPixels[i] = pFillColor;
	}
}

void Raster::Clear(float d){
	int totalPixels = width * height;
	for (int i = 0; i < totalPixels; i++){
		depthPixels[i] = d;
	}
}

void Raster::WriteToPPM(){
	ofstream oFile;
	oFile.open("FRAME_BUFFER.ppm");
	oFile << "P3" << "\n";
	oFile << width << " " << height << "\n";
	oFile << "255" << "\n";
	for (int row = 0; row < height; row++){
		for (int col = 0; col < width; col++){
			int r, g, b, a;
			int idx = (row * width) + col;
			colorPixels[idx].GetIntegerChannels(&r, &g, &b, &a);
			oFile << int(r) << " " << int(g) << " " << int(b) << " ";
		}
		oFile << "\n";
	}
	oFile.close();
}

void Raster::DrawModel(Model m){
	for (int i = 0; i < m.NumTriangles(); i++){
		DrawTriangle3D_Barycentric(m[i]);
	}
}

void Raster::DrawTriangle3D_Barycentric(Triangle3D t){
	if (t.shouldDraw == false)
		return;

	int xMin = fmax(0, fmin(fmin(floor(t.v0.x), floor(t.v1.x)), floor(t.v2.x)));
	int xMax = fmin(GetWidth(), fmax(fmax(ceil(t.v0.x), ceil(t.v1.x)), ceil(t.v2.x)));
	int yMin = fmax(0, fmin(fmin(floor(t.v0.y), floor(t.v1.y)), floor(t.v2.y)));
	int yMax = fmin(GetHeight(), fmax(fmax(ceil(t.v0.y), ceil(t.v1.y)), ceil(t.v2.y)));

	Triangle2D myTri(t);

	for (int x = xMin; x < xMax; x++){
		for (int y = yMin; y < yMax; y++){
			
			float lambda1 = 0.0;
			float lambda2 = 0.0;
			float lambda3 = 0.0;

			myTri.CalculateBarycentricCoordinates(Vector2(float(x) + 0.5, float(y) + 0.5), lambda1, lambda2, lambda3);

			if (lambda1 >= 0.0 && lambda2 >= 0.0 && lambda3 >= 0.0){
				float setDepth = t.v0.z*lambda1
								+ t.v1.z*lambda2
								+ t.v2.z*lambda3;
				if (setDepth < GetDepthPixel(x,y)){
					SetDepthPixel(x, y, setDepth);
					SetColorPixel(x, y, t.c0*lambda1 + t.c1*lambda2 + t.c2*lambda3);
				}
			}
		}
	}
}

