#include <iostream>
#include <type_traits>
#include <tuple>

namespace hedron
{
	template<typename T>
	class vector
	{
		T* data = nullptr;
		unsigned int max_capacity;
		unsigned int capacity;

		void resize(unsigned int size)
		{
			//std::cout << "test\n";
			if (capacity <= size && data != nullptr)
			{
				T* temp = new T[size];
				for (unsigned i = 0; i < capacity; i++)
				{
					if (temp != nullptr)
					{
						temp[i] = data[i];
					}
				}
				max_capacity = size;
				delete[] data;
				data = temp;
			}
		}
	public:
		vector(unsigned int size) : data{ new T[size] }, max_capacity{ size }, capacity{ 0 } {}

		void print_properties()
		{
			std::cout << "max_capacity: " << max_capacity << "\n";
			std::cout << "length: " << capacity << "\n";
		}
		
		template<typename T>
		void emplace_back(T el)
		{
			if (capacity >= max_capacity)
			{
				resize(max_capacity + 1);
			}
			data[capacity++] = el;
		}

		template<typename T, typename... Args>
		void emplace_back(T first,Args... args)
		{
			emplace_back(first);
			emplace_back(args...);
		}

		void print()
		{
			std::cout << "[";
			for (unsigned int i = 0;i < capacity;i++)
			{
				std::cout << data[i] << ((i == capacity - 1) ? "" : ",");
			}
			std::cout << "]\n";
		}

		unsigned int get_capacity()
		{
			return capacity;
		}

		unsigned int get_max_capacity()
		{
			return max_capacity;
		}

		virtual ~vector()
		{
			std::cout << "DESTRUCTED\n";
			if (data != nullptr)
			{
				delete[] data;
			}
		}
	};
}

class Sphere
{
public:
	float m_radius;
	Sphere() {}
	Sphere(float radius) : m_radius{ radius } {}
	friend std::ostream& operator<<(std::ostream& os, const Sphere& s)
	{
		os << "Radius: " << s.m_radius;
		return os;
	}


};


template<typename T,unsigned N, unsigned... Args>
struct object_property_filter
{
	using type = std::tuple<int, int, double>;
	T object;
};

namespace hedron
{
	template<typename T, typename... Args>
	struct tuple : public hedron::tuple<Args...>
	{
		T element;
	};

	template<typename T>
	struct tuple<T>
	{
		T element;
	};

	template<unsigned N, typename T, typename... Args>
	auto get(const hedron::tuple<T, Args...>& tup)
	{
		if constexpr (N == 0)
			return tup.element;
		else
			return get<N-1>( static_cast<hedron::tuple<Args...>>(tup) );
	}
}

template<typename... Args>
void test(Args... args)
{
	const int size = sizeof...(Args);
	int data[size] = {args...};
	for (unsigned i = 0;i < size;i++) 
	{
		std::cout << data[i] << std::endl;
	}
}

struct Polygon
{
};


int main()
{


	/*
	hedron::tuple<int, float, double> t = { 9.678, 3.34f, 12 };
	std::cout << hedron::get<2>(t) << std::endl;

	std::tuple<int, float, double> t2 = { 12, 3.34f, 9.678 };

	test(3,7,6,5);

	hedron::vector<Sphere> vec = hedron::vector<Sphere>(5);
	vec.emplace_back(5, Sphere(3), Sphere(8));
	vec.print();
	vec.emplace_back(Sphere(12), Sphere(67), Sphere(89), Sphere(10));
	vec.print();
	*/
}