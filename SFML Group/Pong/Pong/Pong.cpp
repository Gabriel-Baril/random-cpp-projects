// Pong.cpp : définit le point d'entrée pour l'application console.
//
#include "stdafx.h"
#include "Constant.h"
#include "Palet.h"
#include "Ball.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>


int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "PONG");
	window.setFramerateLimit(60);

	sf::Vertex line[] = {sf::Vertex(sf::Vector2f(WIDTH/2,0)), sf::Vertex(sf::Vector2f(WIDTH / 2,HEIGHT))};

	sf::Clock clock;
	Palet playerPalet(sf::Vector2f(0,0),15,HEIGHT/6);
	Palet AIPalet(sf::Vector2f(WIDTH - 10,0),15,HEIGHT/6);
	Ball ball(sf::Vector2f(WIDTH/2, HEIGHT/2),10);

	while (window.isOpen()) 
	{
		
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();

		playerPalet.update();
		AIPalet.automatic(ball);
		ball.update();

		playerPalet.collide_ball(ball);
		AIPalet.collide_ball(ball);

		window.draw(AIPalet);
		window.draw(playerPalet);
		window.draw(ball);
		window.draw(line,2,sf::Lines);

		window.display();

		sf::Time frameTime = clock.restart();
		float framerate = 1 / (frameTime.asMilliseconds() * 0.001);
		std::cout << framerate << std::endl;
	}


    return 0;
}

