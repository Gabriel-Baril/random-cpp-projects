// Test_Template.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Liste.h"
#include <iostream>



int main()
{
	Liste<float> li(75);

	std::cout << li.get() << std::endl;

	std::cin.get();
    return 0;
}

