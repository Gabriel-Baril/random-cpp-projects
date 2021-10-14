#include <iostream>
#include <string>
#include <cmath>

unsigned int loadChunks(int n, int x, int y)
{
	unsigned int offSet = 1;
	int factor = 2;
	for (int i = -n; i < n + 1;i++)
	{
		for (int j = 0; j < offSet; j++)
		{
			std::cout << "(" << x - n + abs(i) + j << "," << y + i << ")" << std::endl;
		}
		if (offSet >= 2 * n + 1) factor = -2;
		offSet += factor;
	}
	return 2*n*(n + 1) + 1;
}

int main()
{
	std::cout << loadChunks(1, 0, 0) << std::endl;

	system("pause");
	return 1;
}
