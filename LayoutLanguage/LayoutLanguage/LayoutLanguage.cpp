#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::pair<std::vector<std::string>, std::vector<std::string>> readFileData(const char* file_path)
{
	auto output = std::pair<std::vector<std::string>, std::vector<std::string>>();
	std::ifstream file;

	file.open(file_path);
	if (!file)
	{
		std::cout << "Unable to open file\n";
		exit(1);
	}

	std::string line;
	char current;
	while (file >> current)
	{
		std::cout << current << '\n';
	}
	
	
	return output;
}

int main()
{
	readFileData("C:/Users/Gabriel/Desktop/element.layout");
}