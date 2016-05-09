#include "rectangle.hpp"
#include <iostream>
#include <math.h>
#include "color.hpp"
#include "vec2.hpp"

//default
Rectangle::Rectangle():
	height{1},
	width{1},
	clr{},
	ed{}{}
//custom
Rectangle::Rectangle(float h, float w, Color clr):
	height{h},
	width{w},
	clr{clr},
	ed{ed}{}

float Rectangle::get_height() const
{
	float betrag = abs(height);
	return betrag;
}
float Rectangle::get_width() const
{
	float betrag = abs(width);
	return betrag;
}
float Rectangle::get_area() const
{
	float bh = abs(height);
	float bw = abs(width);
	return bh*bw;
}
Vec2 Rectangle::get_ed() const 
{
	return ed;
} 
float Rectangle::set_height(float nheight)
{
	height = abs(nheight);
	return height;
}
float Rectangle::get_circumference()const
{
	return 2*height+2*width;
}
float Rectangle::set_width(float nwidth)
{
	width = abs(nwidth);
	return width;
}
/*
bool Rectangle::is_inside(Vec2 const& ed)
{
	if( get_height() > 0 && get_width() > 0)
	{
		if (point.x < get_ed().x || point.x > (get_ed().x + get_width()))
			return false;
		if (point.y < get_ed().y || point.y > (get_ed().y + get_height()))
			return false;
		else 
			return true;
	}
	if (get_height() > 0 && get_width() < 0)
	{
		if (point.x < (get_ed().x  + get_width()) || point.x > get_ed().x)
			return false;
		if (point.y < get_ed().y || point.y > (get_ed().y + get_height()))
			return false;
		else
			return true;
	}
	if (get_height() < 0 && get_width() > 0){
		if (point.x < get_ed().x || point.x > (get_ed().x + get_width()))
			return false;
		if (point.y < (get_vertex().y + get_height()) || point.y > get_ed().y)
			return false;
		else
			return true;
	}
	else
	{
		if (point.x < (get_ed().x + get_width()) || point.x > get_ed().x)
			return false;
		if (point.y < (get_ed().y + get_height()) || point.y > get_ed().y)
			return false;
		else
			return true;
	}
}
*/
