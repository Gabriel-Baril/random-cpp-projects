#include <vector>
#include <ranges>
#include <iostream>

struct Color
{
	char r;
	char g;
	char b;
	char a;
};

struct Vec2
{
	float x;
	float y;
};

struct LinePrimitive
{
	struct Physic
	{
		Vec2 start;
		Vec2 end;
	};

	struct Style
	{
		float thickness;
		Color color;
		float strokeThickness;
		Color strokeColor;
		bool filled;
	};

	Physic physic;
	Style style;
};

struct CirclePrimitive
{
	struct Physic
	{
		Vec2 center;
		float radius;
	};

	struct Style {
		bool filled;
	};

	Physic physic;
	Style style;
};

struct RenderTarget
{
	virtual void draw(const LinePrimitive& line) = 0;
	virtual void draw(const CirclePrimitive& circle) = 0;
};

struct SFMLRenderTarget : RenderTarget
{
	void draw(const LinePrimitive& line) override
	{
		std::cout << "Drawing line at [\n" << line.physic.start.x << ", " << line.physic.start.y << "]\n";
	}
};


int main()
{
	RenderTarget* target = new SFMLRenderTarget;

}