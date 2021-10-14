#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include <type_traits>
#include "Command.h"
#include "Logger.h"

void fun(const char* t_name)
{
	for (unsigned i = 0;i < 1000;i++)
	{
		if (i % 3) Logger::get_instance().error(t_name, "ON LINE -> " + std::to_string(i) );
		else if (i % 4) Logger::get_instance().warning(t_name, "ON LINE -> " + std::to_string(i) );
		else if (i % 2) Logger::get_instance().log(t_name, "ON LINE -> " + std::to_string(i), 15, false);
	}
}

struct Vec3
{
	float x, y, z;
};


template<typename T>
struct Type
{
	static void print()
	{
		std::cout << "DEFAULT" << std::endl;
	}
};


template<typename T>
struct Type<T*>
{
	static void print()
	{
		std::cout << "POINTER TYPE" << std::endl;
	}
};

template<typename T>
struct Type<T**>
{
	static void print()
	{
		std::cout << "DOUBLE POINTER TYPE" << std::endl;
	}
};

template<typename T>
struct Type<T***>
{
	static void print()
	{
		std::cout << "TRIPLE POINTER TYPE" << std::endl;
	}
};

template<typename T>
struct Type<T&>
{
	static void print()
	{
		std::cout << "L-REFERENCE TYPE" << std::endl;
	}
};

unsigned maximal_square(std::string arr[], unsigned size)
{


	return size;
}

template<int N>
void call_if_ood(char t[N%2])
{
	
}


int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	Vec3 v = {7,42,80};
	const auto& [x, y, z] = v;

	//std::thread t1(fun,"THREAD 1");
	//std::thread t2(fun, "THREAD 2");

	//Type<int***>::print();

	std::string data[] = { "0111", "1111", "1111", "1111" };

	std::cout << maximal_square(data, sizeof(data) / sizeof(data[0])) << std::endl;


	//t1.join();
	//t2.join();

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;

	std::cout << diff.count() << std::endl;


	//std::ostringstream os_string();
	//os_string << "test";

	//Logger::get_instance().error("Console", "TEST_PRINTING");
}