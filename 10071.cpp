#include <iostream>

int main()
{
	int v;
	unsigned short t;
	while (std::cin >> v >> t) 
	{
		std::cout << v * 2 * t << std::endl;
	}
	return 0;
}