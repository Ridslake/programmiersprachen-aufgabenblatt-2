#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <math.h>
#include "color.hpp"
#include "vec2.hpp"


class Circle
{
	public:
	Circle();	//default
	Circle(float radius, Color crl); //custom

	//Variablen
	float radius;
	Color clr;
	Vec2 ed;
	
	//Getter
	float get_durchmesser() const;
	float get_flaeche()const;					
	float get_circumference() const;		//Umfang
	float get_radius() const;
	float set_radius(float nradius);
};
#endif
