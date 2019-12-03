#ifndef Color_H
#define Color_H

struct Color{

	// Fields / Attributes
	float red;
	float green;
	float blue;
	float alpha;

	// Constructors
	Color();
	Color(float pRed, float pGreen, float pBlue, float pAlpha);

	// Methods
	void GetIntegerChannels(int* pRed, int* pGreen, int* pBlue, int* pAlpha);
	void Clamp();

	// Operators
	Color operator*(float scalar);
	Color operator/(float scalar);
	Color operator+(Color c);
	Color operator-(Color c);
	Color operator*(Color c);

};

// Default colors
#define Red Color(1.0, 0.0, 0.0, 1.0)
#define Green Color(0.0, 1.0, 0.0, 1.0)
#define Blue Color(0.0,0.0,1.0,1.0)
#define Black Color(0.0,0.0,0.0,1.0)
#define White Color(1.0,1.0,1.0,1.0)
#define Transparent Color(0.0,0.0,0.0,0.0)


#endif
