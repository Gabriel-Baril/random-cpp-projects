#include <iostream>
#include <chrono>
#include <vector>
#include <thread>
#include <tuple>
#include "Polygon.hpp"
#include "TimerBenchmarking.hpp"
#include "Vec.hpp"

/*
template<typename T, typename... Ts>
T getVVec<0, T, Ts...>(const VVec<T, Ts...>& vvec)
{
	return vvec.value;
}
*/

/*
template<unsigned short N, typename T, typename... Ts>
auto getVVec(const VVec<T, Ts...>& vvec)
{
}
*/

struct Base
{
	float data;
};

struct Derivee : Base
{
	int data;
};

int main()
{
	Derivee d = {34, 67};

	std::cout << ((Derivee)d).data << std::endl;


	std::tuple<int, float, double> t = std::tuple<int, float, double>(34, 67, 1);
	

	std::vector<tw::math::Vec2f> vertices = std::vector<Vec2f>();
	vertices.push_back({ 0, 0 });
	vertices.push_back({ 0, 2 });
	vertices.push_back({ 2, 2 });
	vertices.push_back({ 2, 0 });

	Polygon poly = Polygon(vertices);

	//VVec<float, int, double, float> vvec = {3.45f, 5, 76.98, 92.6675f};
	VVec<int, float, double> vvec = {3, 4.35f, 67.6745};
	

	Vec<5, float> v1 = { 23, 56, 86, 12, 90 };
	Vec<4, int> v2 = { 57, 90, 102, 122 };
	Vec<4, double> v3 = { 57.4456, 90.67, 102.9, 10 };

	//std::cout << v3 << "\n";
	//std::cout << v2 << "\n";

	//std::cout << v3 + v2 << "\n";


	/*
	for (unsigned i = 0; i < 100; i++)
	{
		TimerBenchmarking t = TimerBenchmarking();
		poly.extract_points(1, 1);
	}
	*/
	


	return 0;
}