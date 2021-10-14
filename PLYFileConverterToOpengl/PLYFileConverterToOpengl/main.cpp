#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <algorithm>
#include <iterator>

struct FileData
{
	float* vertices;
	float* indices;
	FileData(size_t v_size, size_t i_size)
	{
		vertices = new float[v_size];
	}
};

void split(const std::string& str, std::vector<std::string>& cont, const std::string& delims = " ")
{
	std::size_t current, previous = 0;
	current = str.find_first_of(delims);
	while (current != std::string::npos) {
		cont.push_back(str.substr(previous, current - previous));
		previous = current + 1;
		current = str.find_first_of(delims, previous);
	}
	cont.push_back(str.substr(previous, current - previous));
}

void readVertexDataFromPLYFile(const std::string path) {
	std::ifstream file(path);
	std::vector<std::string> data;
	if (file.is_open()) {
		std::string line;
		while (std::getline(file,line)) {
			line = std::regex_replace(line, std::regex("3  "), "");
			split(line, data, " ");
			//std::cout << line << std::endl;
		}
	}
	bool passed = false;
	std::vector<float> vertices;
	std::vector<float> indices;
	for (unsigned int i = 0; i < data.size(); i++)
	{
		if (data.at(i)._Equal("INDICES")) {
			passed = true;
			continue;
		}
		if (!passed) vertices.push_back(std::stof(data.at(i)));
		if (passed) indices.push_back(std::stof(data.at(i)));
	}
	for (int i = 0; i < indices.size();i++) {
		if (i % 3 == 0) std::cout << std::endl;
		std::cout << indices.at(i) << " ";
	}
}

int main(int argc, char **argv) 
{
	if (argv[1] != nullptr) {
		std::cout << "The path of the file is : " << argv[1] << std::endl;

		readVertexDataFromPLYFile(argv[1]);
	}
	else
	{
		std::cout << "NO FILE DRAGGED" << std::endl;
	}

	system("PAUSE");
}