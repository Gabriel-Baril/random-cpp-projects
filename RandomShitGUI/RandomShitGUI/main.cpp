#include <iostream>


struct EventHandler
{
	void(*on_mouse_over_callback)();

	virtual void on_mouse_over()
	{
		on_mouse_over_callback();
	}
};

struct Vec2
{
	float x;
	float y;
};

struct Collider
{
	virtual bool point_collider_collision(const Vec2& point) = 0;
};

struct RectCollider : Collider
{
	Vec2 pos;
	Vec2 dim;

	bool point_collider_collision(const Vec2& point)
	{
		return point.x >= pos.x && 
			   point.x <= pos.x + dim.x &&
			   point.y >= pos.y &&
			   point.y <= pos.y + dim.y;
	}
};

struct CircleCollider : Collider
{
	Vec2 pos;
	float radius;

	bool point_collider_collision(const Vec2& point)
	{
		return pos.x*pos.x+pos.y*pos.y < radius*radius;
	}
};

struct Button
{
	EventHandler eventHandler;
	Collider* collider;
};


void hello()
{
	std::cout << "HELLO" << std::endl;
}

int main()
{
	
	Button button;
	button.eventHandler.on_mouse_over_callback = hello;

	button.eventHandler.on_mouse_over();


}