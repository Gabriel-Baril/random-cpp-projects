#pragma once
#include "Polygon.hpp"

Polygon::Polygon(const std::vector<Vec2f>& arr_vertices) : m_vertices(arr_vertices) {}

float Polygon::get_area() const
{
	float area = 0;
	for (auto [i, next] = std::tuple<unsigned short, unsigned short>{ 0, 0 }; i < m_vertices.size(); i++)
	{
		next = (i == m_vertices.size() - 1) ? 0 : i + 1;
		area += m_vertices[i].x * m_vertices[next].y - m_vertices[i].y * m_vertices[next].x;
	}
	return fabsf(area) / 2;
}

float Polygon::get_perimeter() const
{
	float perimeter = 0;
	for (auto [i, next, temp_diff_x, temp_diff_y] = std::tuple<unsigned short, unsigned short, float, float>{ 0,0,0,0 }; i < m_vertices.size(); i++)
	{
		next = (i == m_vertices.size() - 1) ? 0 : i + 1;
		temp_diff_x = m_vertices[next].x - m_vertices[i].x;
		temp_diff_y = m_vertices[next].y - m_vertices[i].y;
		perimeter += sqrtf(temp_diff_x * temp_diff_x + temp_diff_y * temp_diff_y);
	}
	return perimeter;
}

Vec2f Polygon::get_barycenter() const
{
	float b_x = 0;
	float b_y = 0;
	for (unsigned short i = 0; i < m_vertices.size(); i++)
	{
		b_x += m_vertices[i].x;
		b_y += m_vertices[i].y;
	}
	return { b_x / m_vertices.size(), b_y / m_vertices.size() };
}

float Polygon::get_min_x() const
{
	float min_x = m_vertices[0].x;
	for (unsigned i = 1; i < m_vertices.size(); i++)
		if (m_vertices[i].x < min_x)
			min_x = m_vertices[i].x;
	return min_x;
}

float Polygon::get_min_y() const
{
	float min_y = m_vertices[0].y;
	for (unsigned i = 1; i < m_vertices.size(); i++)
		if (m_vertices[i].y < min_y)
			min_y = m_vertices[i].y;
	return min_y;
}

float Polygon::get_max_x() const
{
	float max_x = m_vertices[0].x;
	for (unsigned i = 1; i < m_vertices.size(); i++)
		if (m_vertices[i].x > max_x)
			max_x = m_vertices[i].x;
	return max_x;
}

float Polygon::get_max_y() const
{
	float max_y = m_vertices[0].y;
	for (unsigned i = 1; i < m_vertices.size(); i++)
		if (m_vertices[i].y > max_y)
			max_y = m_vertices[i].y;
	return max_y;
}

const std::vector<Vec2f>& Polygon::extract_points(float dx, float dy) const
{
	std::vector<Vec2f> inner_points = std::vector<Vec2f>();

	for (float x_ = get_min_x(); x_ <= get_max_x(); x_ += dx)
		for (float y_ = get_min_y(); y_ <= get_max_y(); y_ += dy)
			if (true) // if [x_, y_] inside polygon
				inner_points.push_back( { x_, y_ } );
	return inner_points;
}
