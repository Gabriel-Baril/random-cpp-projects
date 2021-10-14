#include <iostream>
#include <string>

class Student
{
public:
	Student(unsigned int, const std::string&);
	Student operator+(const Student&);

	unsigned int age;
	std::string name;
};
