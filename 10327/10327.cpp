#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	unsigned short l;
	while (std::cin >> l)
	{
		std::vector<int> t(l);
		for(int j = 0; j < l; ++j)
		{
			std::cin >> t[j];
		}
		std::cout << "Minimum exchange operations : " << ' ' << std::endl;
	}
	return 0;
}