#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Sprite.h"


class Player
{
public:
	Player(const sf::Vector2f& pos, const Sprite& sprite);
	Player(const float& x,const float& y, const Sprite& sprite);
	Player(const Player&) = delete;
	Player(const Player&&) = delete;

	inline const sf::Vector2f& get_pos() const noexcept;
	inline void set_pos(const sf::Vector2f& pos);
	inline const Sprite& get_sprite() const;
	inline void set_sprite(const Sprite& sprite);
	inline void move(float dx, float dy);
	inline void render(sf::Window* window);

	Player& operator=(const Player&) = delete;
	Player& operator=(const Player&&) = delete;

private:
	sf::Vector2f m_pos;
	Sprite m_sprite;
};