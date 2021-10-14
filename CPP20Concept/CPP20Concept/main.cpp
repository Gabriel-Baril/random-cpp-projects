#include <iostream>
#include <concepts>

enum BOX_RENDER
{
	BORDER_TOP = 1,
	BORDER_RIGHT = 1 << 1,
	BORDER_BOTTOM = 1 << 2,
	BORDER_LEFT = 1 << 3,
	BORDER_ALL = BORDER_TOP | BORDER_RIGHT | BORDER_BOTTOM | BORDER_LEFT,
	BORDER_V = BORDER_RIGHT | BORDER_LEFT,
	BORDER_H = BORDER_TOP | BORDER_BOTTOM
};

void test()
{
	struct Logger
	{
		static void log()
		{
			std::cout << "test" << std::endl;
		}
	};
	Logger::log();
}



int main()
{
	test();
}