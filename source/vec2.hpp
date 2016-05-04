#ifndef VEC2_HPP
#define VEC2_HPP
#include <vector>

//Vec2 class definition
class Vec2
{
	public:
	Vec2();
	Vec2(float x, float y);
	float x;
	float y;

	Vec2& operator+=(Vec2 const& v);
	Vec2& operator-=(Vec2 const& v);
	Vec2& operator*=(float v);
	Vec2& operator/(float v);
};

#endif //VEC2_HPP
/*
Ein Destructor ist eine Memberfunktion einer Klasse die ausgefuehrt wird,
wenn ein Objekt der Klasse zerstoert wird.
Wenn ein Objekt aus dem Scope geht oder mit "delete" geloescht wird, kommt
der Destructor und raeumt auf.
Bei Klassen die nur den Wert von Variablen definieren wird der Destructor nicht benoetigt,
da C++ automatisch die Arbeit des Konstruktors uebernimmt.
*/
