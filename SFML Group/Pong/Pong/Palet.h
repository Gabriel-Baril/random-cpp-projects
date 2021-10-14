#pragma once
#include "Ball.h"
#include <SFML/Graphics.hpp>

class Palet : public sf::RectangleShape
{
public:
	Palet(sf::Vector2f pos,int width,int height);

	~Palet();

	sf::Vector2f getVel() const;
	void setVel(double ,double);

	void move();
	void update();
	void collide_wall();

	void collide_ball(Ball&);
	void automatic(Ball const&);

private:
	sf::Vector2f vel;
	const double speed = 2;
};

