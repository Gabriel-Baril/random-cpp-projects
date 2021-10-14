#include <iostream>
#include <vector>
#include <typeinfo>

class Box;
class Ball;

class Shape
{
public:
	Shape(const float& x, const float& y) : x(x), y(y)
	{
	}

	virtual bool collide(Shape* shape)
	{
		
		return false;
	}
	virtual bool collide(const Box&) = 0;
	virtual bool collide(const Ball&) = 0;

	float x;
	float y;
};

class Box : public Shape
{
public:
	Box(const float& x, const float& y, const float& w, const float& h) : Shape(x,y), w(w), h(h) 
	{
		
	};
	bool collide(const Box& box)
	{
		std::cout << "BOX-BOX" << std::endl;
		return false;
	}
	bool collide(const Ball& ball)
	{
		std::cout << "BOX-BALL" << std::endl;
		return false;
	}
	float w;
	float h;
};

class Ball : public Shape
{
public:
	Ball(const float& x, const float& y, const float& r) : Shape(x, y), r(r)
	{

	};
	bool collide(const Box& box)
	{
		std::cout << "BALL-BOX" << std::endl;
		return false;
	}
	bool collide(const Ball& ball)
	{
		std::cout << "BALL-BALL" << std::endl;
		return false;
	}
	float r;
};

int main(void)
{
	std::vector<Shape*> shapes;
	shapes.push_back(new Box(1,2,34,4));
	shapes.push_back(new Ball(10, 25, 15));
	int a = 32;
	std::unique_ptr<int> data(&a);
	std::cout << *data << std::endl;
	delete data.get();

	system("PAUSE");
	return 0;
}
