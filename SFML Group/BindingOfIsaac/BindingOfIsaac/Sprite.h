
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Sprite
{
public:
	Sprite(const char* texture_path)
	{
		if (!m_texture.loadFromFile(texture_path))
		{
			std::cout << "FAILED TO LOAD TEXTURE" << std::endl;
		}
		else
		{
			m_sprite.setTexture(m_texture);
			m_sprite.scale(4, 4);
		}
	}
	sf::Sprite& get_sprite() { return m_sprite; }
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};