#pragma once
#include <vector>
//#include "IShapeDataIllustrator.h"
#include "Vec2.h"

class PolygonData
{
public:
	std::vector<Vec2<float>> m_vertices;
	PolygonData(const std::vector<Vec2<float>>& vector_init) : m_vertices(vector_init) {}
};