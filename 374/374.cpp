#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int main()
{
	unsigned long long b, p, m;
	while(std::cin >> b >> p >> m)
	{
		unsigned int same(b);
		unsigned int count(1);
		unsigned int r(b % m);
		for(;; same *= same)
			if((same % m) == r)
			{
				++count;
				break;
			}
		std::cout << (unsigned long long)pow(b, p % count) % m << std::endl;
	}
	return 0;
}