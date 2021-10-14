#include <iostream>
#include <vector>
#include <string>


double add(double a, double b)
{
	return a + b;
}

double mul(double a, double b)
{
	return a*b;
}

/*
std::vector<std::vector<std::string>> traverse(Tree* start, Tree* end)
{
	std::vector<std::vector<std::string>> paths;
	std::vector<Tree*> visited_node;
	Tree* current_node;
	for (unsigned i = 0;i < start->nodes.size();i++)
	{
		paths.push_back({});
		paths.back().push_back(start->info);
		visited_node.push_back(start);
		current_node = start->nodes[i];
		while (current_node != end)
		{
			bool valid_node = true;
			for (unsigned j = 0; j < current_node->nodes.size(); j++)
			{
				valid_node = true;
				for (unsigned k = 0; k < visited_node.size(); k++)
				{
					if (current_node->nodes[j] == visited_node[k] || current_node->nodes[j]->nodes.size() == 0)
					{
						valid_node = false;
						break;
					}
				}
				if (valid_node)
				{
					current_node = current_node->nodes[j];
					visited_node.push_back(current_node);
					break;
				}
			}
			if (!valid_node)
			{
				paths.pop_back();
				break;
			}
			paths.back().push_back(current_node->info);
		}
		visited_node.clear();
	}
	return paths;
}
*/


struct Tree
{
	std::vector<Tree*> nodes;
	std::string info;
	//double (*f)(double, double);
};


void traverse(Tree* start, Tree* end, std::vector<std::vector<Tree*>>& paths)
{
	if (start != end)
	{
		for (unsigned i = 0; i < start->nodes.size(); i++)
		{
			bool is_node_valid = true;
			for (unsigned j = 0;j < paths.back().size();j++)
			{
				if (start->nodes[i] == paths.back()[j])
				{
					is_node_valid = false;
					break;
				}
			}
			if (is_node_valid && start->nodes[i]->nodes.size() != 1)
			{
				paths.back().push_back(start);
				traverse(start->nodes[i], end, paths);
			}
		}
	}
	else
	{
		paths.back().push_back(end);
		paths.push_back({});
	}
}


int main()
{
	Tree n0;
	Tree n1;
	Tree n2;
	Tree n3;
	Tree n4;
	Tree n5;
	Tree n6;
	Tree n7;
	Tree n8;
	Tree n9;
	Tree n10;
	Tree n11;
	Tree n12;

	n0 = { {&n1 ,&n2, &n5}, "n0" };
	n1 = { {&n0, &n2}, "n1" };
	n2 = { {&n0, &n3}, "n2" };
	n3 = { {&n2, &n11}, "n3" };
	n4 = { {&n5}, "n4" };
	n5 = { {&n0, &n4, &n6, &n7, &n8}, "n5" };
	n6 = { {&n5}, "n6" };
	n7 = { {&n5, &n9}, "n7" };
	n8 = { {&n5, &n9}, "n8" };
	n9 = { {&n7, &n8, &n10, &n11, &n12}, "n9" };
	n10 = { {&n9}, "n10" };
	n11 = { {&n3, &n9}, "n11" };
	n12 = { {&n9}, "n12" };
	
	std::vector<std::vector<Tree*>> paths = { {} }; 
	traverse(&n0, &n11, paths);

	for (unsigned i = 0;i < paths.size();i++)
	{
		for (unsigned j = 0;j < paths[i].size();j++)
		{
			std::cout << paths[i][j]->info << ((j != paths[i].size() - 1) ? "->" : "");
		}
		std::cout << '\n';
	}

	/*
	std::vector<Tree*> path_1;
	traverse(&n0, &n11, path_1);
	for (unsigned i = 0;i < path_1.size();i++)
	{
		std::cout << path_1[i]->info << ((i != path_1.size() - 1) ? "->" : "");
	}
	*/
}