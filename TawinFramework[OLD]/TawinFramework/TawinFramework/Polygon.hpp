#pragma once
#include <initializer_list>
#include <array>
#include <vector>
#include "Vec.hpp"

using namespace tw::math;

struct Rectangle
{
	float min_x;
	float min_y;
	float max_x;
	float max_y;
};

class Polygon
{
	std::vector<Vec2f> m_vertices;
	//Vec2f m_velocity;
	//Vec2f m_acceleration;
	//float m_angular_speed;
	//float m_angular_acceleration;
public:
	Polygon(const std::vector<Vec2f>& arr_vertices);
	Polygon(const Polygon&);
	Polygon(Polygon&&);

	void update();
	void render();

	float get_area() const;
	float get_perimeter() const;
	Vec2f get_barycenter() const;

	float get_min_x() const;
	float get_min_y() const;
	float get_max_x() const;
	float get_max_y() const;
	
	std::vector<Polygon> triangulate() const;
	void move(float x, float y);
	void move(Vec2f v);
	void rotate(const Vec2f& anchor,float theta_rad);

	const std::vector<Vec2f>& extract_points(float,float) const;
	double get_moment_of_inertia() const; // moment of inertia from the barycenter
	double get_moment_of_inertia(const Vec2f& axis) const;

	Vec2f& operator[](unsigned short i);
	const Vec2f& operator[](unsigned short i) const;
};
