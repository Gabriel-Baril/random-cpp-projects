// Toolkit.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Vec2.h"

using std::cout;
using std::endl;

int main()
{
	Vec2<float> v2(13, 11);
	Vec2<float> v1(10, 20);
	Vec2<float> v3(100, 73);


	v1 + v2 + v3 << cout;

	std::cin.get();
    return 0;
}

