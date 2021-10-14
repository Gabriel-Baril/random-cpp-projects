#pragma once

template<typename T>
struct Vec2
{
	T x;
	T y;

	friend std::ostream& operator<<(std::ostream& os, const Vec2<T>& v)
	{
		return os << "[" << v.x << "," << v.y << "]";
	}
};