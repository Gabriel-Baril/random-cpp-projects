#pragma once
#include <iostream>
#include <cmath>
#include <type_traits>

template<typename T> constexpr bool is_number_v = std::is_integral_v<T> || std::is_floating_point_v<T>;

template<typename T, typename U, typename = void> struct choose_biggest_number_type_hierarchie;

template<typename T, typename U> struct choose_biggest_number_type_hierarchie<T*, U> {};
template<typename T, typename U> struct choose_biggest_number_type_hierarchie<T, U*> {};
template<typename T, typename U> struct choose_biggest_number_type_hierarchie<T*, U*> {};

template<typename T, typename U> struct choose_biggest_number_type_hierarchie<T, U, std::enable_if_t< std::is_integral_v<T> 
																									  && std::is_integral_v<U> 
																								      && (sizeof(T) > sizeof(U)) 
																								      && std::is_unsigned_v<T> 
																									  && std::is_unsigned_v<U> >> { typename std::remove_cvref_t<T> type; };
																									  
template<typename T, typename U> struct choose_biggest_number_type_hierarchie<T, U, std::enable_if_t< std::is_integral_v<T> 
																									  && std::is_integral_v<U> 
																								      && (sizeof(T) <= sizeof(U)) 
																								      && std::is_unsigned_v<T> 
																									  && std::is_unsigned_v<U> >> { typename std::remove_cvref_t<U> type; };

template<typename T, typename U> struct choose_biggest_number_type_hierarchie<T, U, std::enable_if_t< std::is_integral_v<T> 
																									  && std::is_integral_v<U> 
																								      && (sizeof(T) > sizeof(U)) 
																								      && std::is_unsigned_v<T> 
																									  && std::is_signed_v<U> >> { typename std::make_signed_t<std::remove_cvref_t<T>> type; };
																									  
template<typename T, typename U> struct choose_biggest_number_type_hierarchie<T, U, std::enable_if_t< std::is_integral_v<T> 
																									  && std::is_integral_v<U> 
																								      && (sizeof(T) <= sizeof(U)) 
																								      && std::is_unsigned_v<T> 
																									  && std::is_signed_v<U> >> { typename std::remove_cvref_t<U> type; };
																									  
template<typename T, typename U> struct choose_biggest_number_type_hierarchie<T, U, std::enable_if_t< std::is_integral_v<T> 
																									  && std::is_integral_v<U> 
																								      && (sizeof(T) > sizeof(U)) 
																								      && std::is_signed_v<T> 
																									  && std::is_unsigned_v<U> >> { typename std::remove_cvref_t<T> type; };
																									  
template<typename T, typename U> struct choose_biggest_number_type_hierarchie<T, U, std::enable_if_t< std::is_integral_v<T> 
																									  && std::is_integral_v<U> 
																								      && (sizeof(T) <= sizeof(U)) 
																								      && std::is_signed_v<T> 
																									  && std::is_unsigned_v<U> >> { typename std::make_signed_t<std::remove_cvref_t<U>> type; };
																									  
template<typename T, typename U> struct choose_biggest_number_type_hierarchie<T, U, std::enable_if_t< std::is_integral_v<T> 
																									  && std::is_integral_v<U> 
																								      && (sizeof(T) > sizeof(U)) 
																								      && std::is_signed_v<T> 
																									  && std::is_signed_v<U> >> { typename std::remove_cvref_t<T> type; };
																									  
template<typename T, typename U> struct choose_biggest_number_type_hierarchie<T, U, std::enable_if_t< std::is_integral_v<T> 
																									  && std::is_integral_v<U> 
																								      && (sizeof(T) <= sizeof(U)) 
																								      && std::is_signed_v<T> 
																									  && std::is_signed_v<U> >> { typename std::remove_cvref_t<U> type; };

template<typename T, typename U> struct choose_biggest_number_type_hierarchie<T, U, std::enable_if_t< std::is_floating_point_v<T> && std::is_integral_v<U>								       >> { typename std::remove_cvref_t<T> type; };
template<typename T, typename U> struct choose_biggest_number_type_hierarchie<T, U, std::enable_if_t< std::is_integral_v<T>       && std::is_floating_point_v<U>							   >> { typename std::remove_cvref_t<U> type; };

template<typename T, typename U> struct choose_biggest_number_type_hierarchie<T, U, std::enable_if_t< std::is_floating_point_v<T> && std::is_floating_point_v<U> && (sizeof(T) > sizeof(U))    >> { typename std::remove_cvref_t<T> type; };
template<typename T, typename U> struct choose_biggest_number_type_hierarchie<T, U, std::enable_if_t< std::is_floating_point_v<T> && std::is_floating_point_v<U> && (sizeof(T) <= sizeof(U))   >> { typename std::remove_cvref_t<U> type; };

namespace tw::math
{
#pragma pack(push, 1)
	template<typename T, typename ...Ts> struct VVec { T value; VVec<Ts...> rest; }; // not sure
	template<typename T> struct VVec<T> { T value; };								 // not sure
#pragma pack(pop)

	template<unsigned short N, typename T, typename = void>
	struct Vec;

	template<unsigned short N, typename T>
	struct Vec<N, T, std::enable_if_t<is_number_v<T> && (N > 4)>>
	{
		T components[N];
		T& operator[](unsigned i) { return components[i]; }
		const T& operator[](unsigned i) const { return components[i]; }
	};

	template<typename T> struct Vec<2, T, std::enable_if_t<is_number_v<T>> > { T x; T y; };
	template<typename T> struct Vec<3, T, std::enable_if_t<is_number_v<T>> > { T x; T y; T z; };
	template<typename T> struct Vec<4, T, std::enable_if_t<is_number_v<T>> > { T x; T y; T z; T w; };

	template<signed N, signed M> constexpr signed max() { return (N >= M) ? N : M; }
	template<signed N, signed M> constexpr signed min() { return (N >= M) ? M : N; }

	template<unsigned short N, typename T>
    inline Vec<N, T> operator+(const Vec<N, T>& v1, const Vec<N, T>& v2);

	template<unsigned short N, unsigned short M, typename T> 
	inline Vec<max<N, M>(), T> operator+(const Vec<N, T>& v1, const Vec<M, T>& v2);

	template<unsigned short N, typename T, typename U>
	inline Vec<N, T> operator+(const Vec<N, T>& v1, const Vec<N, U>& v2); // cancer

	template<unsigned short N, typename T>
	inline Vec<N, T> operator-(const Vec<N, T>& v1, const Vec<N, T>& v2);

	template<unsigned short N, unsigned short M, typename T>
	inline Vec<max<N, M>(), T> operator-(const Vec<N, T>& v1, const Vec<M, T>& v2);

	template<unsigned short N, typename T>
	inline std::ostream& operator<<(std::ostream& os, const Vec<N, T>& vec);

	template<typename T> using Vec2     = Vec<2, T>;
	using					   Vec2i    = Vec<2, int>;
	using					   Vec2f    = Vec<2, float>;
	using					   Vec2d    = Vec<2, double>;

	template<typename T> using Point2   = Vec<2, T>;
	using					   Point2i  = Vec<2, int>;
	using					   Point2f  = Vec<2, float>;
	using					   Point2d  = Vec<2, double>;

	template<typename T> using Vert2    = Vec<2, T>;
	using					   Vert2i   = Vec<2, int>;
	using					   Vert2f   = Vec<2, float>;
	using					   Vert2d   = Vec<2, double>;

	template<typename T> using Complex  = Vec<2, T>;
	using					   Complexi = Vec<2, int>;
	using					   Complexf = Vec<2, float>;
	using					   Complexd = Vec<2, double>;


	template<typename T> using Vec3     = Vec<3, T>;
	using					   Vec3i    = Vec<3, int>;
	using					   Vec3f    = Vec<3, float>;
	using					   Vec3d    = Vec<3, double>;

	template<typename T> using Point3   = Vec<3, T>;
	using					   Point3i  = Vec<3, int>;
	using					   Point3f  = Vec<3, float>;
	using					   Point3d  = Vec<3, double>;

	template<typename T> using Vert3    = Vec<3, T>;
	using					   Vert3i   = Vec<3, int>;
	using					   Vert3f   = Vec<3, float>;
	using					   Vert3d   = Vec<3, double>;


	template<typename T> using Vec4     = Vec<4, T>;
	using					   Vec4i    = Vec<4, int>;
	using					   Vec4f    = Vec<4, float>;
	using					   Vec4d    = Vec<4, double>;

	template<typename T> using Point4   = Vec<4, T>;
	using					   Point4i  = Vec<4, int>;
	using					   Point4f  = Vec<4, float>;
	using					   Point4d  = Vec<4, double>;

	template<typename T> using Vert4    = Vec<4, T>;
	using					   Vert4i   = Vec<4, int>;
	using					   Vert4f   = Vec<4, float>;
	using					   Vert4d   = Vec<4, double>;

	template<typename T> using Quat     = Vec<4, T>;
	using					   Quati    = Vec<4, int>;
	using					   Quatf    = Vec<4, float>;
	using					   Quatd    = Vec<4, double>;

}

#include "vec.tpp"