#include "Student.hpp"

Student::Student(unsigned int age, const std::string& name)
{
	this->age = age;
	this->name = name;
}

Student Student::operator+(const Student& student)
{
	return Student(this->age + student.age, this->name + student.name);
}


