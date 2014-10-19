#include <iostream>

int main()
{
	long long n;
	while (std::cin >> n, n >= 0)
	{
		unsigned long long a, b;
		if(n%2 == 1)
		{
			a = (n + 1)/2;
			b = n;
		}
		else
		{
			a = n / 2;
			b = n + 1;
		}
		std::cout << a * b + 1 << std::endl;
	}
	return 0;
}