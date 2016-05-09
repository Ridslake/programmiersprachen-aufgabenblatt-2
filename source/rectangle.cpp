#include "rectangle.hpp"
#include <iostream>
#include <math.h>

//default
Rectangle::Rectangle():
	height{1},
	width{1}{}
//custom
Rectangle::Rectangle(float h, float w):
	height{h},
	width{w}{}

float Rectangle::get_height()
{
	return height;
}
float Rectangle::get_width()
{
	return width;
}
