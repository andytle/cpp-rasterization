#include "Color.h"
#include <iostream>
#include <string>
using namespace std;

Color::Color()
  : red(1.0), green(1.0), blue(1.0), alpha(1.0){
}

Color::Color(float pRed, float pGreen, float pBlue, float pAlpha)
  : red(pRed), green(pGreen), blue(pBlue), alpha(pAlpha){
    // red = pRed;
    // green = pGreen;
    // blue = pBlue;
    // alpha = pAlpha;
    Clamp();
}

void Color::Clamp(){
    if (red > 1.0) {
        red = 1.0;
    } else if (red < 0.0){
        red = 0.0;
    }

    if (green > 1.0) {
        green = 1.0;
    } else if (green < 0.0){
        green = 0.0;
    }

    if (blue > 1.0) {
        blue = 1.0;
    } else if (blue < 0.0){
        blue = 0.0;
    }

    if (alpha > 1.0) {
        alpha = 1.0;
    } else if (alpha < 0.0){
        alpha = 0.0;
    }

}

Color Color::operator+(const Color & other){
    Color new_color;
    new_color.red = this->red + other.red;
    new_color.green = this->green + other.green;
    new_color.blue = this->blue + other.blue;
    new_color.alpha = this->alpha + other.alpha;

    new_color.Clamp();
    return new_color;
}

Color Color::operator-(const Color & other){
    Color new_color;
    new_color.red = this->red - other.red;
    new_color.green = this->green - other.blue;
    new_color.blue = this->blue - other.blue;
    new_color.alpha = this->alpha - other.alpha;

    new_color.Clamp();
    return new_color;
}

Color Color::operator*(float p){
    Color new_color;
    new_color.red = p * this->red ;
    new_color.green = p * this->green;
    new_color.blue = p * this->blue;
    new_color.alpha = p * this->alpha;

    new_color.Clamp();
    return new_color;
}
