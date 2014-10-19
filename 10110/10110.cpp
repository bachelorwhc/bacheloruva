#include <iostream>
#include <cmath>

int main()
{
	unsigned int lights;
	while (std::cin >> lights, lights)
	{
		int t(sqrt(lights));
		std::cout << ((t * t == lights) ? "yes" : "no") << std::endl;
	}
	return 0;
}