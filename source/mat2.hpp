#ifndef MAT2_HPP
#define MAT2_HPP
#include "vec2.hpp"
#include <math.h>

//Aufgabe 2.5 und 2.6
class Mat2
{
	public:
	Mat2();						//Default	
	Mat2(float w, float x, float y, float z); 	//Custom

	float det() const;
	Mat2& operator *= (Mat2 const& m);
	
	float w;
	float x;
	float y;
	float z;

};

	Mat2 operator * (Mat2 const& ma1, Mat2 const& ma2);
	Vec2 operator * (Mat2 const& ma, Vec2 const& v);
	Vec2 operator * (Vec2 const& v, Mat2 const& ma);
	Mat2 inverse(Mat2 const& ma);					//Inverse
	Mat2 transpose(Mat2 const& ma);					//Transponierte
	Mat2 make_rotation_mat2(float phi);				//Rotationsmatrix

#endif // MAT2_HPP
