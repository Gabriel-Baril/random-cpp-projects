#include "stdafx.h"
#include <vector>
#include <functional>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

int randInt(int min,int max) {	
	return rand()%(max-min + 1) + min;
}

class Box : public sf::RectangleShape{
public:
	Box(sf::Vector2f* pos, int width, int height) {
		setPosition(*pos);
		setSize(sf::Vector2f(width,height));
		//setOrigin(getPosition().x + getSize().x/2,getPosition().y + getSize().y/2);
		setVel(sf::Vector2f(0,0));
		setAcc(sf::Vector2f(0,0));
	}

	Box(sf::Vector2f* pos, sf::Vector2f vel, int width, int height) {
		Box(pos,width,height);
		this->vel = vel;
	}

	Box(sf::Vector2f* pos, sf::Vector2f vel, sf::Vector2f acc, int width, int height) {
		Box(pos,vel,width,height);
		this->acc = acc;
	}

	sf::Vector2f getVel() { return this->vel; }
	void setVel(sf::Vector2f v) {
		this->vel = v;
	}

	void setVel(double x,double y) { 
		this->vel.x = x;
		this->vel.y = y;
	}
	sf::Vector2f getAcc() { return this->acc; }
	void setAcc(sf::Vector2f acc) { this->acc = acc; }

	void update() {
		collide_wall_test();
		setPosition(getPosition().x + getVel().x, getPosition().y + getVel().y);
		setVel(getVel().x + getAcc().x,getVel().y + getAcc().y);
		setRotation(getRotation() + getVel().x);
	}
private:
	void collide_wall_test() {
		if (getPosition().x <= 0 || getPosition().x + getSize().x >= SCREEN_WIDTH) {
			setVel(getVel().x*-1, getVel().y);
		}
		if (getPosition().y <= 0 || getPosition().y + getSize().y >= SCREEN_HEIGHT) {
			setVel(getVel().x, getVel().y*-1);
		}
	}

	sf::Vector2f vel;
	sf::Vector2f acc;
};

int main() 
{
	std::cout << randInt(0,10) << std::endl;

	std::function<void()> lambda;
	std::cout << sizeof(lambda) << std::endl;

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "MY_WINDOW");
	std::vector<Box*>* boxes = new std::vector<Box*>;
	const int DELAY = 10;
	for (unsigned int i = 0; i < 100;i++) {
		Box* box = new Box(new sf::Vector2f(randInt(0, SCREEN_WIDTH - 30), randInt(0, SCREEN_HEIGHT - 30)), randInt(10, 30), randInt(10, 30));
		boxes->push_back(box);
	}
	sf::Clock clock;
	
	while (window.isOpen()) 
	{
		sf::sleep(sf::milliseconds(DELAY));

		// handle event
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		for (int i = 0; i < boxes->size();i++) {
			boxes->at(i)->update();
			boxes->at(i)->setVel(randInt(1, 4), randInt(1, 4));
			window.draw(*(boxes->at(i)));
		}

		window.display();

		sf::Time frameTime = clock.restart();
		float framerate = 1 / (frameTime.asMilliseconds() * 0.001);
		//std::cout << framerate << std::endl;

	}

	return EXIT_SUCCESS;
}
