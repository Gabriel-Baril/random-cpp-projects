// Test_cpp.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "MyHeader.h"
#include <iostream>
#include <string>
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::function;

template<typename T>
class Point 
{
public:
	Point() {}
	Point(const T& x,const T& y) 
	{
		this->x = x;
		this->y = y;
	}
	T getX() const { return this->x; }
	T getY() const { return this->y; }
	T setX(T x) { this->x = x; }
	T setY(T y) { this->y = y; }

	bool operator>(const Point & p1) const { return ((this->x + this->y) > (p1.x + p1.y)); }
	bool operator<(const Point & p1) const { return ((this->x + this->y) < (p1.x + p1.y)); }
	bool operator>=(const Point & p1) const { return ((this->x + this->y) >= (p1.x + p1.y)); }
	bool operator<=(const Point & p1) const { return ((this->x + this->y) <= (p1.x + p1.y)); }

private:
	T x;
	T y;
};


template<typename T>
class Box{
private:
	Point<T> pos;
public:
	Box(const Box<T>& box) { 
		this->pos = box.getPos();
	}

	Box(T x,T y) {
		this->pos = Point<T>(x,y);
	}

	Point<T> getPos() const { return this->pos; }

	template<typename T> friend Box<T>& operator+(const Box<T>&, const Box<T>&);
	template<typename T> friend std::ostream& operator<<(std::ostream&, const Box<T>&);
};

template<typename T>
Box<T>& operator+(const Box<T>& b1, const Box<T>& b2) {
	return *(new Box<T>(b1.getPos().getX() + b2.getPos().getX(), b1.getPos().getY() + b2.getPos().getY()));
}

template<typename T>
std::ostream& operator<<(std::ostream & os, const Box<T>& box)
{
	os << "(" << box.getPos().getX() << "," << box.getPos().getY() << ")" << endl;
	return os;
}

class Base {
public:
	Base() {}
	void MyBase() {};
};

int main(){
	int a = 196;

	Box<float> b1(10,30);
	Box<float> b2(50,90);

	Box<float> b3 = b1 + b2;
	 
	void* p = &b3;
	cout << (Box<float>)*p << endl;

	cout << b3 << endl;


	std::cin.get();
    return 0;
}
