#include <iostream>
#include <stdlib.h>
#include <thread>

using namespace std::chrono_literals;

const char FILLED = '#';
const char EMPTY = '-';

void print_char_buffer(char* buffer, int buffer_size)
{
	for (int i = 0; i < buffer_size; i++)
	{
		std::cout << buffer[i];
	}
}

void fill_char_buffer(char* buffer, int buffer_size, int completeness, char fill_char, char empty_char)
{
	for (int i = 0; i < completeness; i++)
		buffer[i] = fill_char;

	for (int i = completeness; i < buffer_size; i++)
		buffer[i] = empty_char;
}

void progress_bar_animation(int width, int height)
{
	char* buffer = new char[width];
	for (int i = 0;i < width;i++)
	{
		fill_char_buffer(buffer, width, i, FILLED, EMPTY);
		for (int j = 0;j < height;j++)
		{
			print_char_buffer(buffer, width);
			printf("\n");
		}
		std::this_thread::sleep_for(100ms);
		system("cls");
	}
	delete[] buffer;
}

int main()
{
	progress_bar_animation(50, 2);
}