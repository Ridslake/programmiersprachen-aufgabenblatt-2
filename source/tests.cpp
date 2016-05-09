#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include <math.h>
#include "mat2.hpp"
#include "color.hpp"
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
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
