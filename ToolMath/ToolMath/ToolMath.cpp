// ToolMath.cpp : définit le point d'entrée pour l'application console.

#include "stdafx.h"
#include "Vec2.h"
#include "Segment.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main()
{
	Segment<float> seg(Vec2<float>(0,0),Vec2<float>(20,20));

	cout << seg.equation.equ << endl;


	std::cin.get();

	return 0;
}