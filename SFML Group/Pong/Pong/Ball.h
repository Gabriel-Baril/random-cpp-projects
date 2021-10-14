#pragma once
#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape
{
public:
	Ball(sf::Vector2f pos, int radius);
	~Ball();

	void setVel(double x, double y);
	sf::Vector2f getVel() const;

	void update();
	void collide_wall();


private:
	sf::Vector2f vel;
};

