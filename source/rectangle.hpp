#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <math.h>
#include "color.hpp"
#include "vec2.hpp"

class Rectangle
{
	public:
	Rectangle(); //default
	Rectangle(float height, float width, Color clr); //custom
	
	//Variablen
	float height;
	float width;
	Color clr;
	Vec2 ed;

	//Getter and setter
	float get_height()const;			
	float get_width() const;
	float get_area() const;
	float get_circumference() const;
	float set_height(float nheight);	
	float set_width(float nwidth);
	bool is_inside(Vec2 const& ed);
	Vec2 get_ed() const;
};
#endif
