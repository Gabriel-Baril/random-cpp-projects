#include "Player.h"

Player::Player(const sf::Vector2f& pos, const Sprite& sprite) : m_pos(pos), m_sprite(sprite)
{
	m_sprite.get_sprite().setPosition(pos);
}

Player::Player(const float& x, const float& y, const Sprite& sprite) : m_pos{x,y}, m_sprite(sprite)
{
	m_sprite.get_sprite().setPosition(x,y);
}

inline const sf::Vector2f& Player::get_pos() const noexcept
{
	return m_pos;
}

inline void Player::set_pos(const sf::Vector2f& pos)
{
	m_pos = pos;
}

inline const Sprite& Player::get_sprite() const
{
	return m_sprite;
}

inline void Player::set_sprite(const Sprite& sprite)
{
	m_sprite = sprite;
}

inline void Player::move(float dx, float dy)
{
	m_pos.x += dx;
	m_pos.y += dy;
	m_sprite.get_sprite().setPosition(m_pos);
}

inline void Player::render(sf::Window* window)
{
	((sf::RenderWindow*)window)->draw(m_sprite.get_sprite());
}
