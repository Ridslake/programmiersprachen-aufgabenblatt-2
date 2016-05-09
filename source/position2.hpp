#ifndef POSITION2_HPP
#define POSITION2_HPP
struct position
{
	float x,y;
	Position(); x(0), y(0){}
	Position(float x, float y): x{x}, y{y} {}
};
#endif
