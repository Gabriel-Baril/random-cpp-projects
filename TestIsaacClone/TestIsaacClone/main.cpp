#include<iostream>

#define ROOM_SIZE_X 3
#define ROOM_SIZE_Y 3

enum class TileID
{
	ROCK = 0,
	TINTED_ROCK = 1,
	SUPER_TINTED_ROCK = 2,
	SKULL = 3
};


void render(TileID tiles[ROOM_SIZE_X][ROOM_SIZE_Y])
{
	for (unsigned int i = 0;i < ROOM_SIZE_X;i++) 
	{
		for (unsigned int j = 0; j < ROOM_SIZE_Y; j++)
		{	
			switch (tiles[i][j])
			{
			case TileID::ROCK:
				std::cout << "#";
				break;
			case TileID::TINTED_ROCK:
				std::cout << "*";
				break;
			case TileID::SUPER_TINTED_ROCK:
				std::cout << "+";
				break;
			case TileID::SKULL:
				std::cout << "-";
				break;
			default:
				std::cout << "?";
				break;
			}
		}
		std::cout << std::endl;
	}
}

int main(void)
{
	TileID tiles[ROOM_SIZE_X][ROOM_SIZE_Y] = { { TileID::ROCK, TileID::ROCK,       TileID::ROCK }, 
											   { TileID::ROCK, TileID::TINTED_ROCK,TileID::ROCK },
											   { TileID::ROCK, TileID::ROCK,       TileID::ROCK } };
	render(tiles);


	system("PAUSE");
}