#include <iostream>
#include <algorithm>
#include <vector>

bool IsOrder(std::vector<int>& ns)
{
	unsigned int len(ns.size());
	for(unsigned int i = 0; i + 1< len; ++i)
	{
		if(ns[i] > ns[i + 1])
			return false;
	}
	return true;
}

int main()
{
	unsigned short l;
	while (std::cin >> l)
	{
		std::vector<int> ns(l);
		for(int j = 0; j < l; ++j)
			std::cin >> ns[j];
		unsigned int count(0);
		while (!IsOrder(ns))
		{
			for(unsigned int i = 0; i + 1 < l; ++i)
			{
				if(ns[i] > ns[i + 1])
				{
					std::swap(ns[i], ns[i + 1]);
					++count;
				}
			}
		}
		std::cout << "Minimum exchange operations : " << count << std::endl;
	}
	return 0;
}