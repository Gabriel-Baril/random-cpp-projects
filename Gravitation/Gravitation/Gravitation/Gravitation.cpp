// Gravitation.cpp : définit le point d'entrée pour l'application console.
//
#include "stdafx.h"
#include "Vec2.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>


#define WIDTH 1200
#define HEIGHT 1200

sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Vec2_TEST");
int arr[2];


int main()
{

	Vec2<float> anchor_(WIDTH/2,HEIGHT/2 - 40);
	Vec2<float> anchor(200, 200);
	Vec2<float> eLine(200,100);
	Vec2<float> eLine2(300, 100);
	sf::Vertex line[2];
	sf::Vertex line2[2];
	sf::Vertex line3[2];
	sf::Vector2<double> v = Vec2<double>::toSfVec2(Vec2<double>(10,20));

	window.setFramerateLimit(60);

	int x = 0;

	while (window.isOpen()) {
		sf::Event ev;
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed)
				window.close();
		}

		//eLine.revert();
		eLine.rotate(2);
		eLine2.rotate(-1);
		
		anchor.rotate(1.5);

		//window.clear();

		line[0] = sf::Vertex(sf::Vector2<float>(Vec2<float>::toSfVec2(anchor_ + anchor)),sf::Color::White);
		line[1] = sf::Vertex(sf::Vector2<float>(Vec2<float>::toSfVec2(anchor_ + anchor + eLine)), sf::Color::White);

		line2[0] = sf::Vertex(sf::Vector2<float>(Vec2<float>::toSfVec2(anchor_ + anchor)), sf::Color::White);
		line2[1] = sf::Vertex(sf::Vector2<float>(Vec2<float>::toSfVec2(anchor_ + anchor + eLine2)), sf::Color::White);

		line3[0] = sf::Vertex(sf::Vector2<float>(Vec2<float>::toSfVec2(anchor_)), sf::Color::White);
		line3[1] = sf::Vertex(sf::Vector2<float>(Vec2<float>::toSfVec2(anchor_ + anchor)), sf::Color::White);

		window.draw(line,2,sf::Lines);
		window.draw(line2, 2, sf::Lines);
		window.draw(line3, 2, sf::Lines);
		
		window.display();
	}

    return 0;
}

