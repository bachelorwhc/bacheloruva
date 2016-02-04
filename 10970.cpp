#include <iostream>

int main()
{
	unsigned int m, n;
	while (std::cin >> m >> n)
	{
		std::cout << (m - 1) + m * (n - 1) << std::endl;
	}
	return 0;
}