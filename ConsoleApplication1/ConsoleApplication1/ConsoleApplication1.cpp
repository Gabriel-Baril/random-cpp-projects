// ConsoleApplication1.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::endl;

class Box {
public:
	Box(const int& x,const int& y,const int& width,const int& height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	void setX(int x) { this->x = x; }
	int getX() const { return this->x; }
	void setY(int y) { this->y = y; }
	int getY() const { return this->y; }
	void setWidth(int width) { this->width = width; }
	int getWidth() const { return this->width; }
	void setHeight(int height) { this->height = height; }
	int getHeight() const { return this->height; }

	friend std::ostream& operator<<(std::ostream&, const Box&);
	friend Box operator+(const Box&, const Box&);
	friend Box operator-(const Box&, const Box&);
	friend Box operator*(const Box&, const Box&);
	friend Box operator/(const Box&, const Box&);
	
private:
	int x;
	int y;
	int width;
	int height;
};

std::ostream & operator<<(std::ostream & os, const Box & box)
{
	os << "Pos : (" << box.getX() << "," << box.getY() << ")   Dim : (" << box.getWidth() << "," << box.getHeight() << ")" << endl;
	return os;
}

Box operator+(const Box & b1, const Box & b2)
{
	return Box(b1.getX() + b2.getX(), b1.getY() + b2.getY(), b1.getWidth() + b2.getWidth(), b1.getHeight() + b2.getHeight());
}

Box operator-(const Box & b1, const Box & b2)
{
	return Box(b1.getX() - b2.getX(), b1.getY() - b2.getY(), b1.getWidth() - b2.getWidth(), b1.getHeight() - b2.getHeight());
}

Box operator*(const Box & b1, const Box & b2)
{
	return Box(b1.getX() * b2.getX(), b1.getY() * b2.getY(), b1.getWidth() * b2.getWidth(), b1.getHeight() * b2.getHeight());
}

Box operator/(const Box & b1, const Box & b2)
{
	return Box(b1.getX() / b2.getX(), b1.getY() / b2.getY(), b1.getWidth() / b2.getWidth(), b1.getHeight() / b2.getHeight());
}

int func(int a,int b) {
	return a + b;
}

int main()
{
	Box b1(200,4,24,20);
	Box b2(100,100,30,30);
	Box b3 = b1 / b2;
	
	int(*add)(int, int) = [](int a, int b) { return a + b; };

	cout << add(20, 30) << endl;
	cout << b3 << endl;

	std::cin.get();
    return 0;
}
