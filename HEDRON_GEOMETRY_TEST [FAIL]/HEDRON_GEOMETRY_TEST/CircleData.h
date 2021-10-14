#pragma once
//#include "IShapeDataIllustrator.h"
#include "Vec2.h"


class CircleData
{
public:
	Vec2<float> m_center;
	float m_radius;

	CircleData(Vec2<float> center, float radius) : m_center(center), m_radius(radius) {}
};