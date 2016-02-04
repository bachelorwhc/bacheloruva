#include <iostream>

int main()
{
	unsigned short it;
	std::cin >> it;
	for (unsigned int i = 0; i < it; ++i)
	{
		unsigned short a, b, sum = 0;
		std::cin >> a >> b;
		for (unsigned short j = a; j <= b; ++j)
		{
			if (j % 2)
				sum += j;
		}
		std::cout << "Case " << i + 1 << ": " << sum << std::endl;
	}
	return 0;
}