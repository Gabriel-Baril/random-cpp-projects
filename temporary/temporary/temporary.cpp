// temporary.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <iterator>
#include <map>
#include <functional>

int SOMME(int a, int b) {
	return a + b;
}

int main()
{
	std::map<std::string, int> names;
	std::map<std::string, int>::iterator iterator_names;
	names["Tawin"] = 5;
	names["Ninja"] = 12;

	//std::cout << names.cbegin()->first << std::endl;

	for (iterator_names = names.begin(); iterator_names != names.end();iterator_names++) {
		//std::cout << iterator_names->first << std::endl;
	}


	std::cin.get();

    return 0;
}

