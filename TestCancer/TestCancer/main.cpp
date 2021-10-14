#include <iostream>
#include "Student.hpp"


int main()
{
	Student s1 = Student(13, "Jean");
	Student s2 = Student(18, "Jacob");

	Student s3 = s1.operator+(s2);

	std::cout << s3.name;
}