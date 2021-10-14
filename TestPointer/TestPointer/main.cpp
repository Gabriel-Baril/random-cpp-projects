#include <iostream>

#pragma pack(0)

using std::cout;
using std::endl;

struct SEVEN_BITS
{
	char c : 7;
};

struct Test
{
	unsigned short a : 7, b : 9;
};


int main()
{
	Test t = {3,51};

	cout << *reinterpret_cast<short*>(&t) << endl;

	std::cin.get();
	return 0;
}