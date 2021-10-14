#include <vector>
#include <functional>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.h"
#include "Sprite.h"

#define WINDOW_WIDTH 780
#define WINDOW_HEIGHT 420
#define ROOM_SIZE_X 15
#define ROOM_SIZE_Y 9
#define TILE_SIZE_X WINDOW_WIDTH / ROOM_SIZE_X
#define TILE_SIZE_Y WINDOW_HEIGHT / ROOM_SIZE_Y

sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Binding of Isaac");
Player player(sf::Vector2f(340,210), Sprite("F:/_PROGRAMMING/Game_Ressource/graphics/binding_of_isaac/heart_life/hearts.png"));


enum class TileID
{
	VOID = 0,
	ROCK = 1,
	WALL = 2,
	DOOR = 3
};

class Room
{
public:
	Room(char data[ROOM_SIZE_X][ROOM_SIZE_Y])
	{
		for (int i = 0;i < ROOM_SIZE_X;i++)
		{
			for (int j = 0;j < ROOM_SIZE_Y;j++) 
			{
				this->data[i][j] = data[i][j];
			}
		}
	}

	void render(sf::RectangleShape& temp)
	{
		for (int i = 0; i < ROOM_SIZE_X; i++)
		{
			for (int j = 0; j < ROOM_SIZE_Y; j++)
			{
				switch ((int)data[i][j])
				{
				case 0:
					temp.setFillColor(sf::Color(0,128,0));
					break;
				case 1:
					temp.setFillColor(sf::Color(128,128, 128));
					break;
				case 2:
					temp.setFillColor(sf::Color(0, 0, 0));
					break;
				case 3:
					temp.setFillColor(sf::Color(128, 0, 128));
					break;
				default:
					temp.setFillColor(sf::Color::Magenta);
					break;
				}
				temp.setPosition(sf::Vector2f(i * TILE_SIZE_X, j * TILE_SIZE_Y));
				window.draw(temp);
			}
		}
	}

	char data[ROOM_SIZE_X][ROOM_SIZE_Y];
private:
};

struct Tree
{
	Tree* nord = nullptr;
	Tree* south = nullptr;
	Tree* east = nullptr;
	Tree* west = nullptr;
	
	unsigned short getNumberLinks()
	{
		short count = 0;
		if (nord) count++;
		if (south) count++;
		if (east) count++;
		if (west) count++;
		return count;
	}
};

void handleInput(const sf::Event& event)
{
	if (event.type == sf::Event::Closed)
		window.close();
}

int main(void)
{

	sf::RectangleShape shape = sf::RectangleShape();
	shape.setSize(sf::Vector2f(TILE_SIZE_X,TILE_SIZE_Y));

	char d[ROOM_SIZE_X][ROOM_SIZE_Y] = { { 2,2,2,2,3,2,2,2,2 },
										 { 2,1,1,1,1,1,1,1,2 },
										 { 2,1,1,1,1,1,1,1,2 },
										 { 2,1,0,1,1,1,1,1,2 }, 
										 { 2,1,1,1,1,1,1,1,2 }, 
										 { 2,1,0,1,1,1,1,1,2 }, 
										 { 2,1,1,1,1,1,1,1,2 }, 
										 { 3,1,1,1,0,1,1,1,3 }, 
										 { 2,1,1,1,1,1,1,1,2 }, 
										 { 2,1,0,1,1,1,1,1,2 }, 
										 { 2,1,1,1,0,1,1,1,2 }, 
										 { 2,1,1,1,1,1,1,1,2 }, 
										 { 2,1,0,1,1,1,1,1,2 },
										 { 2,1,0,1,1,1,1,1,2 },
										 { 2,2,2,2,3,2,2,2,2 } };
	Room room(d);
	std::cout << (int)room.data[1][0];

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			handleInput(event);
		}

		window.clear();
		
		room.render(shape);
		window.draw(sprite.get_sprite());

		window.display();
	}

	return 0;
}