#include<iostream>
#include<vector>

struct Axis3D
{
	Vec<3, float> p0;
	Vec<3, float> dir;
	
	Vec<3, float> operator()(double t)
	{
		return {p0 + t * dir.x, p0 + t * dir.y, p0 + t * dir.z};
	}
}


template<unsigned short N>
class Solid
{
	std::vector<Vec<N, float>>& m_points;
public:
	Solid(const std::vector<Vec<N, float>>& points);
	double get_moment_of_inertia(const Axis3D&);
	
};