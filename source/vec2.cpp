#include "vec2.hpp"
#include <iostream>
//Task 2.3
Vec2::Vec2(): //default constructor
	x{0},
	y{0}{}

Vec2::Vec2(float c, float d):	//custom constructor
	x{c},
	y{d}{}

Vec2& Vec2::operator += (Vec2 const& v) //addition :: for memberfunctions
{
	x += v.x;
	y += v.y;
	
	return *this;	//return modified original
}

Vec2& Vec2::operator -= (Vec2 const& v)//subtraction
{
	x -= v.x;
	y -= v.y;
	
	return *this;
}

Vec2& Vec2::operator *= (float v)//mulitplication with value
{
	x *= v;
	y *= v;
	return *this;
}

Vec2& Vec2::operator / (float v)//division with value, 0- 
{
	if (v == 0.0f)
	{
		x = v;
		y = v;
		return *this;
	}
	else
	{
		x = x/v;
		y = y/v;
	return *this;
	}
}
//2.4
Vec2 operator + (Vec2 const& u, Vec2 const& v) //addition :: saved in a new vector :: for non-memberfunctions
{
	Vec2 w;
	w.x = u.x + v.x; //w.x = x von w
	w.y = u.y + v.y;
	return w;
}
Vec2 operator - (Vec2 const& u, Vec2 const& v)//subtraction
{
	Vec2 w;
	w.x = u.x - v.x; //w.x = w von a
	w.y = u.y - v.y;
	return w;
}
Vec2 operator * (Vec2 const& v, float s)//multiplication
{
	Vec2 w;
	w.x = v.x*s;
	w.y = v.y*s;
	return w;
}
Vec2 operator / (Vec2 const& v, float s)//division
{
	Vec2 w;
	w.x = v.x/s;
	w.y = v.y/s;
	return w;
}
Vec2 operator * (float s, Vec2 const& v)//multiplication
{
	Vec2 w;
	w.x = v.x*s;
	w.y = v.y*s;
	return w;
}
