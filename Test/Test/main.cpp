#include <iostream>

struct Date
{
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 23;
};



int main()
{
	std::cout << sizeof(char)*8 << " bits\n";
	std::cout << sizeof(Date)*8 << " bits\n";

}