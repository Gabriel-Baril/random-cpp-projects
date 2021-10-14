#include "stdafx.h"
#include "Constant.h"
#include "Palet.h"

Palet::Palet(sf::Vector2f p,int w,int h)
{
	setPosition(p);
	setSize(sf::Vector2f(w,h));
	setVel(0, 0);
}

void Palet::setVel(double x,double y) {
	this->vel.x = x;
	this->vel.y = y;
}

sf::Vector2f Palet::getVel() const 
{
	return this->vel;
}

void Palet::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		setVel(0, -speed);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		setVel(0, speed);
	else
		setVel(0, 0);
}

void Palet::collide_wall() 
{
	if (getPosition().y < 0)
		setPosition(getPosition().x,1);
		setVel(0, 0);
	if (getPosition().y + getSize().y > HEIGHT)
		setPosition(getPosition().x, HEIGHT - getSize().y - 1);
		setVel(0, 0);
}

void Palet::collide_ball(Ball& ball)
{
	if (getPosition().x < ball.getPosition().x + ball.getRadius()*2 &&
		getPosition().x + getSize().x > ball.getPosition().x &&
		getPosition().y < ball.getPosition().y + ball.getRadius()*2 &&
		getPosition().y + getSize().y > ball.getPosition().y) {
		ball.setVel(-ball.getVel().x,ball.getVel().y);
	}
}

void Palet::automatic(Ball const& ball)
{
	if (ball.getPosition().x > WIDTH/2) {
		setPosition(getPosition().x, ball.getPosition().y - getSize().y / 2);
	}
}

void Palet::update() {
	collide_wall();
	move();
	setPosition(getPosition().x + getVel().x, getPosition().y + getVel().y);
}


Palet::~Palet()
{
}