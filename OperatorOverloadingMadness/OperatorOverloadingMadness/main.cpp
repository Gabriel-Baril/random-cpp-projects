#include <iostream>
#include "Fraction.h"

int main()
{
	Fraction f1 = Fraction(3, 7);
	Fraction f2 = Fraction(2, 3);

	Fraction* f[4];
	for (int i = 0;i < 3;i++)
	{
		f[i] = new Fraction(i, i);
	}

	for (int i = 0; i < 3; i++)
	{
		delete f[i];
	}

	std::cout << (f1 + f2) << std::endl;
}