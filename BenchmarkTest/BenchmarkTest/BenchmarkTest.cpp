// BenchmarkTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct Vec3
{
	float x, y, z;
};


template<typename Derivee>
class Shape
{
	typename Derivee::draw_func_ret_val draw(const typename Derivee::draw_func_param& params)
	{

	}
};

class Polygon : public Shape<Polygon>
{
public:
	struct DrawOption
	{
		float borderThickness;
		Vec3 borderColor;
		Vec3 fillColor;
	};

	using draw_func_param = DrawOption;
	using draw_func_ret_val = void;
private:
};

int main()
{
	Polygon poly;
	poly.
}