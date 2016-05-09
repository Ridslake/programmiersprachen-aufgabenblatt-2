#ifndef COLOR_HPP
#define COLOR_HPP
//2.7
struct Color
{
	Color() : r(0),g(0),b(0){}
	
	Color(float r): r{r}, g{r}, b{r}{}

	Color(float r, float g, float b):
	r{r},
	g{g},
	b{b}{}

	float r;
	float g;
	float b;
};

#endif

/*struct:
have default public members and bases

class:
default private members and bases
*/
