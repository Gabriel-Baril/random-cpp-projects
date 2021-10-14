#include "stdafx.h"
#include "Line.h"

Line::Line(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
	this->line[0] = sf::Vertex(v1);
	this->line[1] = sf::Vertex(v2);
}


Line::~Line()
{
}

void Line::update()
{
}
