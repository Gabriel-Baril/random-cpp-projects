#pragma once
#include <SFML/Graphics.hpp>

class Line
{
private:
	sf::Vertex line[2];
public:
	Line(const sf::Vector2f&,const sf::Vector2f&);
	~Line();
	
	void update();
	void setBegin(const sf::Vector2f&);
	void setEnd(const sf::Vector2f&);
};

