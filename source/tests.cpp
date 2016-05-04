#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include "vec2.hpp"

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
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
