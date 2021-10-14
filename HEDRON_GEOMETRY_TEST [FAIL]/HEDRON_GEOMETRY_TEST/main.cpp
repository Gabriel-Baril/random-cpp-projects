#include <iostream>
#include <vector>
#include "PolygonData.h"
#include "CircleData.h"
#include "CapsuleData.h"

#define PI 3.1415

template<typename T> 
class Collider2D;

template<>
class Collider2D<PolygonData>
{
protected:
	bool collide(const PolygonData& poly_data)
	{
		for (unsigned i = 0;i < poly_data.m_vertices.size();i++)
		{
			std::cout << poly_data.m_vertices[i] << "\n";
		}
		return true;
	}
};

template<>
class Collider2D<CircleData>
{
protected:
	bool collide(const CircleData& circ_data)
	{
		std::cout << "RADIUS : " << circ_data.m_radius << "\n";
		std::cout << "CENTER : " << circ_data.m_center << "\n";
		return true;
	}
};

template<>
class Collider2D<CapsuleData>
{
protected:
	bool collide(const CapsuleData& cap_data)
	{
		std::cout << "LENGTH : " << cap_data.m_length << "\n";
		std::cout << "THICKNESS : " << cap_data.m_thickness << "\n";
		std::cout << "ANGLE : " << cap_data.m_theta << "\n";
		return false;
	}

};

template<typename CT>
class CompositeShape2D : private Collider2D<CT>
{
	CT m_data_collider;
public:
	CompositeShape2D(const CT& data_collider) : m_data_collider(data_collider) {}
	using Collider2D<CT>::collide;

	void collide()
	{
		collide(m_data_collider);
	}
};


int main()
{
	PolygonData pld = { { 
						{2, 3},
						{4, 90},
						{23, 67},
						{45, 78},
						{10, 0},
						{0,0}
					  } }; // PolygonData({ {2, 3}, {4, 90}, {23, 67}, {45, 78} });


	CircleData cd =     { { 2.3f, 4.89f }, 18.7 };                   // CircleData({ 2.3f, 4.89f }, 18.7);
	CapsuleData cap_d = { 15, 8, PI / 4 };                           //CapsuleData(15, 8, PI/4);

	CompositeShape2D<PolygonData> c_shape_1 = CompositeShape2D<PolygonData>(pld);
	CompositeShape2D<CircleData> c_shape_2 = CompositeShape2D<CircleData>(cd);
	CompositeShape2D<CapsuleData> c_shape_3 = CompositeShape2D<CapsuleData>(cap_d);
	c_shape_1.collide();
	std::cout << "\n";
	c_shape_2.collide();
	std::cout << "\n";
	c_shape_3.collide();
	std::cout << "\n";

	return 0;
}