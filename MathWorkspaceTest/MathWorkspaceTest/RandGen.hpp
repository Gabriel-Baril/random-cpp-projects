#pragma once
#include <random>
#include <type_traits>


template<typename T>
class RandGen
{
	std::random_device dev;
	std::mt19937 rng;
	std::uniform_int_distribution<> dist;
public:
	T min;
	T max;
	RandGen(T min, T max) : min{ min }, max{ max }, rng{ dev() }, dist(min, max) {}

	T gen()
	{
		return dist(rng);
	}
};

template<typename T> requires std::is_floating_point_v<T>
class RandGen<T>
{
	std::random_device dev;
	std::mt19937 rng;
	std::uniform_real_distribution<> dist;
public:
	T min;
	T max;
	RandGen(T min, T max) : min{ min }, max{ max }, rng{ dev() }, dist(min, max) {}

	T gen()
	{
		return dist(rng);
	}
};