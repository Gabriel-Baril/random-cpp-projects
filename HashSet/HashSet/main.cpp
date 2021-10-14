#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

int main()
{
	long loop_limit = 1000000;

	std::unordered_set<std::string> s1;
	std::vector<std::string> s2 = std::vector<std::string>(loop_limit);


	for (volatile int i = 0;i < loop_limit;i++)
	{
		if (i % (loop_limit/100) == 0)
			std::cout << (i*100)/loop_limit << "%\n";
		
		s1.insert(std::to_string(i));
		s2.emplace_back(std::to_string(i));
	}
	std::cout << "Finished" << '\n';

	std::cout << s1.count("-1") << '\n';

	bool contain = false;
	for (volatile int i = 0; i < s2.size(); i++)
	{
		if (s2.at(i) == "-1")
		{
			contain = true;
		}
	}
	std::cout << contain << '\n';
}