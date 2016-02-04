#include <iostream>
#include <vector>

enum COLOR
{
	un, black, white
};

struct Node
{
	Node() : color(un), links() {};
	COLOR color;
	std::vector<unsigned int> links;
};

bool IsBiocolorable(std::vector<Node>& nodes, unsigned int start, COLOR color)
{
	if(nodes[start].color == un)
		nodes[start].color = color;
	else
	{
		if(color == nodes[start].color)
			return true;
		else
			return false;
	}
	bool is_biocolorable(true);
	for(unsigned int i = 0; i < nodes[start].links.size(); ++i)
	{
		if(nodes[start].links[i] == start)
			continue;
		COLOR next = (nodes[start].color == black ? white : black );
		is_biocolorable = is_biocolorable && IsBiocolorable(nodes, nodes[start].links[i], next);
	}
	return is_biocolorable;
}

int main()
{
	unsigned int num_of_node;
	while (std::cin >> num_of_node)
	{
		if(num_of_node == 0)
			return 0;
		std::vector<Node> nodes(num_of_node);
		unsigned int num_of_edge;
		std::cin >> num_of_edge;
		for(unsigned int e = 0; e < num_of_edge; ++e)
		{
			unsigned int ni, ln;
			std::cin >> ni >> ln;
			std::vector<Node*> v;
			nodes[ni].links.push_back(ln);
			nodes[ln].links.push_back(ni);
		}
		if(IsBiocolorable(nodes, 0, black))
			std::cout << "BICOLORABLE." << std::endl;
		else
			std::cout << "NOT BICOLORABLE." << std::endl;
	}
	return 0;
}