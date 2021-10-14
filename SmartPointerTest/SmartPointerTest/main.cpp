#include <iostream>
#include <sstream>
#include <vector>
#include <array>

/*
template<typename T>
std::string to_string(const T& current)
{
	std::stringstream ss;
	ss << current;
	return ss.str();
}

template<typename T, typename... Args>
std::string to_string(const T& current, Args&&... args)
{
	std::stringstream ss;
	ss << to_string(current) << to_string(std::forward<Args>(args)...);
	return ss.str();
}
*/

template<typename T>
std::string to_string_impl(const T& current)
{
	std::stringstream ss;
	ss << current;
	return ss.str();
}

template<typename... Args>
std::vector<std::string> to_string(const Args&... args)
{
	return { to_string_impl(args)... };
}

int main()
{
	const auto arr = to_string(1, "hello", 5.3f);
	for (const auto& current : arr)
	{
		std::cout << current << std::endl;
	}
	return 0;
}