#include "vec2.hpp"
#include <iostream>
//Task 2.3
Vec2::Vec2(): //default constructor
	x{0},
	y{0}{}

Vec2::Vec2(float c, float d):	//custom constructor
	x{c},
	y{d}{}

Vec2& Vec2::operator += (Vec2 const& v) //for memberfunctions
{
	x += v.x;
	y += v.y;
	
	return *this;	//return modified original
}

Vec2& Vec2::operator -= (Vec2 const& v)
{
	x -= v.x;
	y -= v.y;
	
	return *this;
}

Vec2& Vec2::operator *= (float v)
{
	x *= v;
	y *= v;
	return *this;
}

Vec2& Vec2::operator / (float v)
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
/*
Vec2 operator + (Vec2 const& u, Vec2 const& v) //for non-memberfunctions
{
	Vec2 w;
	a.x = u.x + v.x; //a.x = x von a
	a.y = u.y + v.y;
	return w;
}
Vec2 operator - (Vec2 const& u, Vec2 const& v);
{
	Vec2 w;
	a.x = u.x - v.x; //a.x = x von a
	a.y = u.y - v.y;
	return w;
}
*/

