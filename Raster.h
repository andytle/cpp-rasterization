#ifndef Raster_H
#define Raster_H

#include "Color.h"
#include "Triangle.h"
#include "Model.h"

class Raster{

	private:
		int width;
		int height;
		Color* colorPixels;
		float* depthPixels;

	public:
		Raster();
		Raster(int pWidth, int pHeight, Color pFillColor);
		~Raster();

		int GetWidth();
		int GetHeight();

		Color GetColorPixel(int x, int y);
		void SetColorPixel(int x, int y, Color pFillColor);
		void Clear(Color pFillColor);

		float GetDepthPixel(int x, int y);
		void SetDepthPixel(int x, int y, float depth);
		void Clear(float depth);

		void DrawModel(Model m);
		void DrawTriangle3D_Barycentric(Triangle3D t);

		void WriteToPPM();

};

#endif
