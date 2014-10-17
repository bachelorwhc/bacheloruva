#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

int main()
{
	int it;
	std::cin >> it;
	char cs[100];
	for (int i = 0; i < it; ++i)
	{
		std::string rs;
		std::cin >> rs;
		std::string s(rs);
		std::reverse(rs.begin(), rs.end());
		unsigned long long o(strtoull(s.c_str(), 0, 10));
		unsigned long long r(strtoull(rs.c_str(), 0, 10));
		unsigned int times = 0;
		while (o != r)
		{
			o = o + r;
			sprintf(cs, "%llu", o);
			int end;
			for (int i = 0; cs[i] != '\0'; ++i)
				end = i;
			std::reverse(cs, cs + end + 1);
			r = strtoull(cs, 0, 10);
			++times;
		}
		std::cout << times << ' ' << o << std::endl;
	}
	return 0;
}