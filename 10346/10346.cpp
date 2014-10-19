#include <iostream>

int main()
{
	unsigned long long n, k;
	while (std::cin >> n >> k)
	{
		unsigned long long count(0);
		unsigned long long d(n);
		unsigned long long r;
		do
		{
			r = d % k;
			d /= k;
			count += d;
			d += r;
		}
		while (d >= k);
		std::cout << count + n << std::endl;
	}
	return 0;
}