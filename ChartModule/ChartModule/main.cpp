#include <iostream>
#include <string>

struct ChartOption
{
	std::string title;
	uint32_t width;
	uint32_t height;

};

// Bar Chart

/* Org chart
	Column 0 - The node ID. It should be unique among all nodes, and can include any characters, including spaces. This is shown on the node. You can specify a formatted value to show on the chart instead, but the unformatted value is still used as the ID.
	Column 1 - [optional] The ID of the parent node. This should be the unformatted value from column 0 of another row. Leave unspecified for a root node.
	Column 2 - [optional] Tool-tip text to show, when a user hovers over this node.
*/


#include <string>
#include <vector>
#include <algorithm>

struct ListItem
{
    ListItem* parent;
    std::vector<ListItem*> nodes;
    std::string label;

    ListItem(ListItem* parent, const std::string& label) :
        parent{ parent }, label{ label }
    {
        if(parent)
            parent->pushNode(this);
    }

    void pushNode(ListItem* node)
    {
        if (std::find(nodes.begin(), nodes.end(), node) == nodes.end())
        {
            nodes.push_back(node);
        }
    }
};

void print_list_tree(ListItem* item, int spaceCount = 0)
{
    std::cout << std::string(spaceCount, ' ') << item->label << std::endl;
    for (ListItem* node : item->nodes)
    {
        print_list_tree(node, spaceCount + 1);
    }
}

int main()
{
    ListItem category1 = { nullptr, "Category 1" };
    ListItem category2 = { nullptr, "Category 2" };
    ListItem item1_2 = { &category2, "Item 1_2" };
    ListItem item2_2 = { &category2, "Item 2_2" };
    ListItem category2_1 = { &category2, "Category 2.1" };
    ListItem item3 = { &category2_1, "Item 3" };
    ListItem item4 = { &category2_1, "Item 4" };

    print_list_tree(&category2);
}