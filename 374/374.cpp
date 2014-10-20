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
		
		unsigned long long r(b % m);
		unsigned long long sr(b % m);
		unsigned long long count(m - 1);
		
		unsigned pr = sr;
		for(unsigned long long i = 1; i <= count; ++i)
		{
			unsigned long long d(pow(sr, i));
			unsigned long long r(d % m);
			if(std::find(history.begin(), history.end(), r) == history.end())
				history.push_back(r);
			else
				break;
		}
		
		unsigned int index(p % history.size());
		if(index == 0)
			std::cout << history[history.size() - 1] << std::endl;
		else
			std::cout << history[p % history.size() - 1] << std::endl;
		history.clear();
	}
	return 0;
}