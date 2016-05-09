#include "circle.hpp"
#include <iostream>
#include <math.h>
#include "color.hpp"
#include "vec2.hpp"

Circle::Circle():		//default
	radius{1},
	clr{},
	ed{}
	{}

Circle::Circle(float radius, Color clr):
	radius{radius},
	clr{clr},
	ed{ed}
	{}
	
float Circle::get_flaeche()const
{
	return radius*radius*M_PI;
}
float Circle::get_durchmesser()const
{
	return radius*2;
}				
float Circle::get_circumference() const		//Umfang
{
	return 2 * M_PI * radius;
}	
float Circle::get_radius()const
{
	return radius;
} 
float Circle::set_radius(float nradius)
{
	radius = abs(nradius);
	return radius;
}
