#include "stdafx.h"
#include "Ball.h"
#include "Constant.h" 


Ball::Ball(sf::Vector2f pos, int radius)
{
	setPosition(pos);
	setRadius(radius);
	setVel(3, 3);
}


Ball::~Ball()
{
}

sf::Vector2f Ball::getVel() const
{
	return this->vel;
}

void Ball::collide_wall()
{
	if (getPosition().y < 0 || getPosition().y + getRadius() * 2 > HEIGHT)
		setVel(getVel().x, -getVel().y);
	if (getPosition().x < 0 || getPosition().x + getRadius() * 2 > WIDTH)
		setVel(-getVel().x, getVel().y);
}

void Ball::update()
{
	setPosition(getPosition().x + getVel().x, getPosition().y + getVel().y);
	collide_wall();
}

void Ball::setVel(double x, double y)
{
	this->vel.x = x;
	this->vel.y = y;
}

