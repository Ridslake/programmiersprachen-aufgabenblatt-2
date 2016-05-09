#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <math.h>

class Rectangle
{
	public:
	Rectangle(); //default
	Rectangle(float height, float width); //custom
	
	//Getter and setter
	float get_height() const;			
	float get_width() const;
	float set_height(float new_height);	
	float set_width(float new_width);
	
	//Variablen
	float height;
	float width;
};
#endif
