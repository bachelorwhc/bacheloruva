#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	unsigned int it;
	std::cin >> it;
	std::vector<unsigned int> cost(3);
	for(unsigned int i = 0; i < it; ++i)
	{
		std::cin >> cost[0] >> cost[1] >> cost[2];
		std::sort(cost.begin(), cost.end());
		std::cout << "Case " << i + 1 << ": " << cost[1] << std::endl;
	}
	return 0;
}