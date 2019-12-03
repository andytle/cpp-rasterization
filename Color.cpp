#include "Color.h"
#include <math.h>

Color::Color(){
	red = 0.0;
	green = 0.0;
	blue = 0.0;
	alpha = 0.0;
}

Color::Color(float pRed, float pGreen, float pBlue, float pAlpha){
	red = pRed;
	green = pGreen;
	blue = pBlue;
	alpha = pAlpha;
	Clamp(); // Ensure channel intensities are valid
}

void Color::GetIntegerChannels(int* pRed, int* pGreen, int* pBlue, int* pAlpha){
	*pRed = red * 255;
	*pGreen = green * 255;
	*pBlue = blue * 255;
	*pAlpha = alpha * 255;
}

void Color::Clamp(){
	red = fmax(float(0.0), fmin(red, float(1.0)));
	green = fmax(float(0.0), fmin(green, float(1.0)));
	blue = fmax(float(0.0), fmin(blue, float(1.0)));
	alpha = fmax(float(0.0), fmin(alpha, float(1.0)));
}

Color Color::operator*(float scalar){
	Color newColor(red, green, blue, alpha);
	newColor.red *= scalar;
	newColor.green *= scalar;
	newColor.blue *= scalar;
	newColor.alpha *= scalar;
	newColor.Clamp(); // Ensure channel intensities are valid
	return newColor;
}

Color Color::operator/(float scalar){
	Color newColor(red, green, blue, alpha);
	newColor.red /= scalar;
	newColor.green /= scalar;
	newColor.blue /= scalar;
	newColor.alpha /= scalar;
	newColor.Clamp(); // Ensure channel intensities are valid
	return newColor;
}

Color Color::operator+(Color c){
	Color newColor(red, green, blue, alpha);
	newColor.red += c.red;
	newColor.green += c.green;
	newColor.blue += c.blue;
	newColor.alpha += c.alpha;
	newColor.Clamp(); // Ensure channel intensities are valid
	return newColor;
}

Color Color::operator-(Color c){
	Color newColor(red, green, blue, alpha);
	newColor.red -= c.red;
	newColor.green -= c.green;
	newColor.blue -= c.blue;
	newColor.alpha -= c.alpha;
	newColor.Clamp(); // Ensure channel intensities are valid
	return newColor;
}

Color Color::operator*(Color c){
	Color newColor(red, green, blue, alpha);
	newColor.red *= c.red;
	newColor.green *= c.green;
	newColor.blue *= c.blue;
	newColor.alpha *= c.alpha;
	newColor.Clamp(); // Ensure channel intensities are valid
	return newColor;
}


