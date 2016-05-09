#include "mat2.hpp"
#include "vec2.hpp"
#include <math.h>
#include <iostream>
//default
Mat2::Mat2():
	w{1},
	x{0},
	y{0},
	z{1}
	{}

//custom
Mat2::Mat2(float a, float b, float c, float d):
	w{a},
	x{b},
	y{c},
	z{d}{}

//Matrix-Multiplikation
Mat2& Mat2::operator *= (Mat2 const& ma)
{
	Mat2 matrix{w*ma.w + x*ma.y, w*ma.x + x*ma.z, y*ma.w + z*ma.y, y*ma.x + z*ma.z};
	w = matrix.w;
	x = matrix.x;
	y = matrix.y;
	z = matrix.z;
	return *this;
}

//Matrix-Multiplikation, keine Memberfunktion
Mat2 operator * (Mat2 const& ma1, Mat2 const& ma2)
{
	Mat2 matrix{ma1.w*ma2.w + ma1.x*ma2.y, ma1.w*ma2.x + ma1.x*ma2.z, ma1.y*ma2.w + ma1.z*ma2.y, ma1.y*ma2.x + ma1.z*ma2.z};
	return matrix;
}

//Matrix-Vektor-Multiplikation
Vec2 operator*(Mat2 const& ma, Vec2 const& v)
{
	Vec2 vektor{ma.w*v.x + ma.x*v.y, ma.y*v.x + ma.z*v.y};
	return vektor;
}

//Vektor-Matrix-Multiplikation
Vec2 operator*(Vec2 const& v, Mat2 const& ma)
{
	Vec2 vektor{ma.w*v.x + ma.x*v.y, ma.y*v.x + ma.z*v.y}; //In diesem Beispiel ist dies möglich
	return vektor;
}

//Determinantenberechnung
float Mat2::det() const
{
	return (w*z - x*y);
}

//Inverse Matrix
Mat2 inverse(Mat2 const& ma)
{
	Mat2 invma{ma.z*(1/ma.det()), ma.x*(-1/ma.det()), ma.y*(-1/ma.det()), ma.w*(1/ma.det())};
	return invma;
}

//Transponierte Matrix
Mat2 transpose(Mat2 const& ma)
{
	Mat2 tranma{ma.w, ma.y, ma.x, ma.z};
	return tranma;
}

//Berechnung einer Rotationsmatrix auf Basis des Winkels 'phi'
Mat2 make_rotation_mat2(float phi)
{
	Mat2 rotma(cos(phi), (-1)*sin(phi), sin(phi), cos(phi));
	return rotma;
}
