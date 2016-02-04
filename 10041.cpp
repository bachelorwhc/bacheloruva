#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main()
{
	unsigned int it;
	std::cin >> it;
	for(unsigned int i = 0; i < it; ++i)
	{
		unsigned rn;
		std::cin >> rn;
		std::vector<long long> r(rn);
		unsigned sn;
		for(unsigned int j = 0; j < rn; ++j)
		{
			std::cin >> sn;
			r[j] = sn;
		}
		unsigned int bn = r.size();
		unsigned int distance = 0;
		if(bn == 1)
			distance = 0;
		else
		{
			unsigned int min = -1;
			for(unsigned int s = 0; s < bn; ++s)
			{
				unsigned int d(0);
				for(unsigned int v = 0; v < bn; ++v)	
				{
					if(v == s)
						continue;
					d += (std::abs(r[s] - r[v]));
				}
				if(d < min)
					min = d;
			}
			distance = min;
		}
		std::cout << distance << std::endl;
	}
	return 0;
}