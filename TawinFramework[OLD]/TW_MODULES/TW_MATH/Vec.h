#pragma once

#include <type_traits>
#include <iostream>

template<typename T> concept bool Number = std::is_integral_v<T> || std::is_floating_point_v<T>;

template<unsigned N, typename T = float> struct Vec;

template<typename T> using Vec2    = Vec<2, T>;
					 using Vec2d   = Vec<2, double>;
					 using Vec2f   = Vec<2, float>;
					 using Vec2i   = Vec<2, int>;

template<typename T> using Point2  = Vec<2, T>;
					 using Point2d = Vec<2, double>;
					 using Point2f = Vec<2, float>;
					 using Point2i = Vec<2, int>;

template<typename T> using Vert2   = Vec<2, T>;
					 using Vert2d  = Vec<2, double>;
					 using Vert2f  = Vec<2, float>;
					 using Vert2i  = Vec<2, int>;

template<typename T> using Vec3    = Vec<3, T>;
					 using Vec3d   = Vec<3, double>;
					 using Vec3f   = Vec<3, float>;
					 using Vec3i   = Vec<3, int>;
					 
template<typename T> using Point3  = Vec<3, T>;
					 using Point3d = Vec<3, double>;
					 using Point3f = Vec<3, float>;
					 using Point3i = Vec<3, int>;

template<typename T> using Vert3   = Vec<3, T>;
					 using Vert3d  = Vec<3, double>;
					 using Vert3f  = Vec<3, float>;
					 using Vert3i  = Vec<3, int>;

template<typename T> using Vec4    = Vec<4, T>;
					 using Vec4d   = Vec<4, double>;
					 using Vec4f   = Vec<4, float>;
					 using Vec4i   = Vec<4, int>;

template<typename T> using Point4  = Vec<4, T>;
					 using Point4d = Vec<4, double>;
					 using Pointf  = Vec<4, float>;
					 using Pointi  = Vec<4, int>;
					 
template<typename T> using Vert4   = Vec<4, T>;
					 using Vert4d  = Vec<4, double>;
					 using Vert4f  = Vec<4, float>;
					 using Vert4i  = Vec<4, int>;

template<unsigned N, typename T = float> requires Number<T> && N > 0
struct Vec
{
	T components[N] {};
	
	friend Vec<N,T> operator+(const Vec<N,T>& v1, const Vec<N,T>& v2);
	friend Vec<N,T> operator-(const Vec<N,T>& v1, const Vec<N,T>& v2);
	friend Vec<N,T> operator*(const Vec<N,T>& v1, const Vec<N,T>& v2);
	friend Vec<N,T> operator*(const Vec<N,T>& v1, const Vec<N,T>& v2);
	friend Vec<N,T> operator/(const Vec<N,T>& v1, const Vec<N,T>& v2);
	
	
	
	T& operator[](int index) { return this->components[index]; }
	const T& operator[](int index) const { return this->components[index]; }
	friend std::ostream& operator<<(std::ostream& os, const Vec<N,T> vec)
	{
		os << "[";
		for(unsigned i = 0;i < N;i++)
		{
			os << components[i] << ( (i == N - 1) ? "" : "," );
		}
		return os << "]";
	}
};