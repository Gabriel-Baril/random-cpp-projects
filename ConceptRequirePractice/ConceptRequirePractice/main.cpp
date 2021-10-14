#include <iostream>
#include "logic_gate.hpp"


namespace hedron
{
	template<unsigned N, typename T, typename... Args>
	struct types_arr
	{
		static constexpr unsigned size = sizeof...(Args) - N;
		using type = typename types_arr<N - 1, Args...>::type;
	};

	template<typename T, typename... Args>
	struct types_arr<0, T, Args...>
	{
		static constexpr unsigned size = sizeof...(Args);
		using type = T;
	};

	template<typename T, typename U, typename... Args>
	struct is_same
	{
		template<unsigned N> using type_at = typename types_arr<N, T, U, Args...>::type;
		static constexpr bool value = logic_and_v< is_same_v<T, U>, is_same_v<T, Args...> >;
	};

	template<typename T, typename U> 
	struct is_same<T, U> 
	{
		template<unsigned N> using type_at = typename types_arr<N, T, U>::type;
		static constexpr bool value = false;
	};

	template<typename T> 
	struct is_same<T, T>
	{
		template<unsigned N> using type_at = typename types_arr<N, T>::type;
		static constexpr bool value = true;
	};

	template<typename T, typename U, typename... Args> constexpr bool is_same_v = is_same<T, U, Args...>::value;

	template<typename T, typename U, typename... Args>
	struct is_any_of
	{
		static constexpr bool value = logic_or_v< is_same_v<T, U>, is_any_of_v<T, Args...> >;
	};

	template<typename T, typename U>
	struct is_any_of<T, U>
	{
		static constexpr bool value = is_same<T, U>::value;
	};

	template<typename T, typename U, typename... Args>
	constexpr bool is_any_of_v = is_any_of<T, U, Args...>::value;


	template<template<typename...> typename U, typename... Args>
	struct construct
	{
		using type = U<Args...>;
	};

	template<bool B, typename T = void>
	struct enable_if {};

	template<typename T>
	struct enable_if<true, T> 
	{
		using type = T;
	};

	template<typename T, typename U>
	struct is_base_of
	{
		T value = static_cast<T>(U());
	};

	template<bool... Bs>
	struct zip
	{
		template<typename... Ts>
		struct to
		{
			static_assert(sizeof...(Bs) == sizeof...(Ts), "The packs must have the same size");
		};
	};
}

struct Foo {};
struct Bar : Foo {};

template<typename T>
struct remove_pointer
{
	using type = T;
};


template<typename T>
struct remove_pointer<T*>
{
	using type = T;
};

template<typename T, typename... Ts>
struct star_counter
{
	static constexpr unsigned value = star_counter<T>::value + star_counter<Ts...>::value;
};

template<typename T>
struct star_counter<T>
{
	static constexpr unsigned value = 0;
};

template<typename T>
struct star_counter<T*>
{
	static constexpr unsigned value = star_counter<T>::value + 1;
};


template<int I, int... Is>
struct sum
{
	static constexpr int value = I + sum<Is...>;
};

template<int I>
struct sum<I>
{
	static constexpr int value = I;
};


template<unsigned N, int I, int... Is>
struct element_at
{
	static constexpr int value = element_at<N - 1, Is...>::value;
};

template<int I, int... Is>
struct element_at<0, I, Is...>
{
	static constexpr int value = I;
};

template<int I, int... Is>
struct m_list
{
	static constexpr unsigned size = sizeof...(Is) + 1;
	template<unsigned N> using at = element_at<N, I, Is...>;
	static constexpr int element = I;
};


template<int I1, int I2, int... Is>
struct max
{
	static constexpr int value = max<max<I1, I2>::value, Is...>::value;
};

template<int I1, int I2>
struct max<I1, I2>
{
	static constexpr int value = (I1 > I2) ? I1 : I2;
};

struct Null {};

template<int I,int... Is>
struct List
{
	static constexpr int node = I;
	using next = List<max<I,Is...>::value, Is...>;
};

template<int I>
struct List<I>
{
	static constexpr int node = I;
	using next = Null;
};


struct TrainingData
{
	float x;
	float y;
	char r;
	char g;
	char b;
	double loss;
};

template<typename T>
concept Printable = requires(T t) {
	std::cout << t;
};

template<typename T> 
void print_if(T t)
{
	std::cout << t << '\n';
}

template<typename T, typename... Ts> requires(Printable<T>)
void print_if(T t, Ts... rest)
{
	print_conditional(t);
	print_conditional(rest...);
}

int main()
{
	print_if(1, 2, 3, 'y', "Bonjour");
	//std::cout << typeid(List<3,8,80,0,9,6>::next).name() << '\n';
}