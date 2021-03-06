// Tempoary_0001.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class A {
public:
	A() {}
	virtual void hello() const { cout << "A" << endl; }
};

class B : public A
{
public:
	B() {}
	void hello() const {cout << "B" << endl; }
};

class C : virtual A
{
public:
	C() {}
	void hello() const { cout << "C" << endl; }
};

int main()
{
	const int& a = 12;
	int b = const_cast<int&>(a);
	b = 1;
	cout << a << endl;
	
	std::cin.get();
    return 0;
}

