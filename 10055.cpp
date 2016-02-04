#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
	long long h, e;
	while (std::cin >> h >> e) {
		std::cout << std::abs(h - e) << std::endl;
	}
	return 0;
}