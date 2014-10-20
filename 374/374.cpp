#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int main()
{
	unsigned long long b, p, m;
	std::vector<unsigned long long> history;
	while (std::cin >> b >> p >> m)
	{
		unsigned long long tb(1);
		unsigned long long r;
		b %= m;
		if(p == 0)
		{
			std::cout << 1 << std::endl;
			continue;
		}

		if(b == 0)
		{
			std::cout << 0 << std::endl;
			continue;
		}
		for(unsigned long long i = 0; i < p; ++i)
		{
			tb = b * tb % m;
			if(std::find(history.begin(), history.end(), tb) == history.end())
				history.push_back(tb);
			else
				break;
		}

		unsigned long long len(history.size());

		tb = 1;
		if(len == 0)
			tb = 1;
		else
			if(p % len != 0)
				for(unsigned long long i = 0; i < p % len; ++i)
					tb = b * tb % m;
			else
				tb = history[len - 1];


		std::cout << tb << std::endl;
		history.clear();
	}
	return 0;
}