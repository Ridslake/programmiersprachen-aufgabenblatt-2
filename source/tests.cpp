#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include <math.h>
#include "mat2.hpp"
#include "color.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "color.hpp"
#include <iostream>
//Test cases for memberfunctions
TEST_CASE("describe_default_const_Vec2", "[Vec2]")//default constructor
{
	Vec2 v;
	REQUIRE(Approx(0.0f) == v.x);
	REQUIRE(Approx(0.0f) == v.y);
}
TEST_CASE("describe_custom_const_Vec2", "[Vec2]")//custom constructor
{
	Vec2 v{4.5f,1.5f};

	REQUIRE(Approx(4.5f) == v.x);
	REQUIRE(Approx(1.5f) == v.y);
}
TEST_CASE("describe_custom_add_Vec2", "[Vec2]")//addition
{
	Vec2 v{2.5f,3.5f};
	Vec2 w{4.5f,1.5f};
	
	v += w;

	REQUIRE(Approx(7.0f) == v.x);
	REQUIRE(Approx(5.0f) == v.y);
}
TEST_CASE("describe_custom_sub_Vec2", "[Vec2]")//subtraction
{
	Vec2 v{2.5f,3.5f};
	Vec2 w{4.5f,1.5f};
	
	v -= w;

	REQUIRE(Approx(-2.0f) == v.x);
	REQUIRE(Approx(2.0f) == v.y);
}
TEST_CASE("describe_custom_mul_Vec2", "[Vec2]")//multiplication
{
	Vec2 v{2.5f,3.5f};
	float w = 2.0f;
	
	v *= w;

	REQUIRE(Approx(5.0f) == v.x);
	REQUIRE(Approx(7.0f) == v.y);
}
TEST_CASE("describe_custom_div_Vec2", "[Vec2]")//division
{
	Vec2 v{2.5f,3.5f};
	float w = 2.0f;
	
	v = v / w;

	REQUIRE(Approx(1.25f) == v.x);
	REQUIRE(Approx(1.75f) == v.y);
}

//Test cases for non-memberfunctions
TEST_CASE("describe_add_", "[Vec2]")//addition
{
	Vec2 v{2.5f,3.5f};
	Vec2 w{4.5f,1.5f};
	Vec2 h;
	
	h = v+w;

	REQUIRE(Approx(7.0f) == h.x);
	REQUIRE(Approx(5.0f) == h.y);
}
TEST_CASE("describe_sub_Vec2", "[Vec2]")//subtraction
{
	Vec2 v{2.5f,3.5f};
	Vec2 w{4.5f,1.5f};
	Vec2 h;
	
	h = v-w;

	REQUIRE(Approx(-2.0f) == h.x);
	REQUIRE(Approx(2.0f) == h.y);
}
TEST_CASE("describe_mul_Vec2", "[Vec2]")//multiplication
{
	Vec2 v{2.5f,3.5f};
	float w = 2.0f;
	Vec2 h;
	
	h = v*w;

	REQUIRE(Approx(5.0f) == h.x);
	REQUIRE(Approx(7.0f) == h.y);
}
TEST_CASE("describe_div_Vec2", "[Vec2]")//division
{
	Vec2 v{2.5f,3.5f};
	float w = 2.0f;
	Vec2 h;
	
	h = v / w;

	REQUIRE(Approx(1.25f) == h.x);
	REQUIRE(Approx(1.75f) == h.y);
}
TEST_CASE("describe_mulow_Vec2", "[Vec2]")//multiplication, other way around
{
	float w = 2.0f;
	Vec2 v{2.5f,3.5f};
	Vec2 h;
	
	h = w*v;

	REQUIRE(Approx(5.0f) == h.x);
	REQUIRE(Approx(7.0f) == h.y);
}

TEST_CASE("default_custom ","[Matrix2]")
{
	Mat2 m{};		//Default constructor
	REQUIRE(m.w == 1);
	REQUIRE(m.x == 0);
	REQUIRE(m.y == 0);
	REQUIRE(m.z == 1);

	Mat2 ma2(4.0,5.0,6.0,7.0);	//Custom
	REQUIRE(ma2.w == 4.0);
	REQUIRE(ma2.x == 5.0);
	REQUIRE(ma2.y == 6.0);
	REQUIRE(ma2.z == 7.0);

}

TEST_CASE("MatrixMulitplikation", "MatrixMultiplikation")
{
	Mat2 matrix1(2.0,1.0,2.0,2.0);
	Mat2 matrix2(2.0,3.0,4.0,5.0);
	matrix1 *= matrix2;
	REQUIRE(matrix1.w == Approx(8.0));
	REQUIRE(matrix1.x == Approx(11.0));
	REQUIRE(matrix1.y == Approx(12.0));
	REQUIRE(matrix1.z == Approx(16.0));
}
TEST_CASE("Matrix_MatrixMulitplikation_const", "MatrixMultiplikation")
{
	Mat2 matrix1(2.0,1.0,2.0,2.0);
	Mat2 matrix2(2.0,3.0,4.0,5.0);
	Mat2 matrix3{};
	matrix3 = matrix1 * matrix2;
	REQUIRE(matrix3.w == Approx(8.0));
	REQUIRE(matrix3.x == Approx(11.0));
	REQUIRE(matrix3.y == Approx(12.0));
	REQUIRE(matrix3.z == Approx(16.0));
}
TEST_CASE("Vektor_Matrix_Mulitplikation", "MV")
{
	Mat2 ma(5.0,6.0,7.0,8.0);
	Vec2 v1(2.0,3.0);
	Vec2 v2 {};
	v2 = ma * v1;
	REQUIRE(v2.x == Approx(28.0));
	REQUIRE(v2.y == Approx(38.0));
}
TEST_CASE("Determinante", "det")
{
	Mat2 ma(6.0,6.0,5.0,6.0);
	float t = ma.det();
	REQUIRE(t == Approx(6.0));
}
TEST_CASE("inverse_Matrix", "invma")
{
	Mat2 ma(2.0,2.0,3.0,4.0);
	float t = ma.det();
	REQUIRE(t == Approx(2.0));
	Mat2 mai = inverse(ma);
	REQUIRE(mai.w == Approx(2.0));
	REQUIRE(mai.x == Approx(-1.0));
	REQUIRE(mai.y == Approx(-1.5));
	REQUIRE(mai.z == Approx(1.0));
}
TEST_CASE("transponiert_Matrix", "tram")
{
	Mat2 ma(3.0,2.0,1.0,6.0);
	Mat2 tram = transpose(ma);
	REQUIRE(tram.w == Approx(3.0));
	REQUIRE(tram.x == Approx(1.0));
	REQUIRE(tram.y == Approx(2.0));
	REQUIRE(tram.z == Approx(6.0));
}
TEST_CASE("color", "color")
{
	Color black{0.0};
	REQUIRE(black.r == Approx(0.0));
	REQUIRE(black.g == Approx(0.0));
	REQUIRE(black.b == Approx(0.0));
}
TEST_CASE("colorre", "colorre")
{
	Color red{1.0,0.0,0.0};
	REQUIRE(red.r == Approx(1.0));
	REQUIRE(red.g == Approx(0.0));
	REQUIRE(red.b == Approx(0.0));
}
TEST_CASE("rectangle", "rectangle")
{
	Rectangle def{};
	REQUIRE(def.height == Approx(1));
	REQUIRE(def.width == Approx(1));
	Rectangle betta{3.5,40,{0.6,0.5,0.5}};
	REQUIRE(betta.height == Approx(3.5));
	REQUIRE(betta.width == Approx(40));
	REQUIRE(betta.clr.r == Approx(0.6));
	REQUIRE(betta.clr.g == Approx(0.5));
	REQUIRE(betta.clr.b == Approx(0.5));
}

TEST_CASE("rectangleGetter", "Rgetter")
{
	Rectangle cust{3,40,{0.6,0.4,0.3}};
	REQUIRE(cust.get_height() == Approx(3));
	REQUIRE(cust.get_width() == Approx(40));
	REQUIRE(cust.get_area() == Approx(120));
	REQUIRE(cust.get_circumference() == Approx(3*2+40*2));
	cust.set_height(5);
	cust.set_width(-3);
	REQUIRE(cust.get_height() == Approx(5));
	REQUIRE(cust.get_width() == Approx(3));
	REQUIRE(cust.clr.r == Approx(0.6));
	REQUIRE(cust.clr.g == Approx(0.4));
	REQUIRE(cust.clr.b == Approx(0.3));
}
TEST_CASE("circle", "circle")
{
	Circle def{};
	Circle vier{4.0,{0.6,0.4,0.3}};
	std::cout << vier.clr.r << "rot" << std::endl;
	REQUIRE(def.radius == Approx(1));
	REQUIRE(vier.radius == (4.0));
	REQUIRE(vier.clr.r == Approx(0.6));
	REQUIRE(vier.clr.g == Approx(0.4));
	REQUIRE(vier.clr.b == Approx(0.3));
}
TEST_CASE("circleGetter", "Cgetter")
{
	Circle sieben{7.0, {0.3, 0.4, 0}};
	REQUIRE(sieben.get_durchmesser() == Approx(14.0));
	REQUIRE(sieben.get_flaeche() == Approx(7 * 7 * M_PI));
	REQUIRE(sieben.get_circumference() == Approx(2 * M_PI * 7));
	REQUIRE(sieben.get_radius() == Approx(7.0));
	sieben.set_radius(3.0);
	REQUIRE(sieben.get_radius() == Approx(3.0));
	REQUIRE(sieben.clr.r == Approx(0.3));
	REQUIRE(sieben.clr.g == Approx(0.4));
	REQUIRE(sieben.clr.b == Approx(0));
}
TEST_CASE("Pointinsde", "Pintin")
{

}
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
