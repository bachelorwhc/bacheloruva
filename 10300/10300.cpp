#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	for(int i = 0; i < n; ++i)
	{
		unsigned short p;
		long long award = 0;
		std::cin >> p;
		for(int j = 0; j < p; ++j)
		{
			unsigned int place, animals, rlevel;
			std::cin >> place >> animals >> rlevel;
			award += place * rlevel;
		}
		std::cout << award << std::endl;
	}
	return 0;
}