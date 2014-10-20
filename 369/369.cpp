#include <iostream>
#include <cmath>

int main()
{
	unsigned long long m, n;
	while (std::cin >> n >> m)
	{
		if(n == 0 && m == 0)
			break;
		if(n - m < m)
			m = n - m;
		unsigned long long a(n - m + 1), b(1);
		unsigned int doublecount(0);
		for(unsigned long long i = 2; (n - m) + i <= n; ++i)
		{
			if((n - m + i) % 2 == 0)
			{
				a *= ((n - m + i) / 2);
				++doublecount;
			}
			else
				a *= (n - m + i);
		}
		for(unsigned long long i = 2; i <= m; ++i)
		{
			if(i % 2 == 0 && doublecount >= 0)
			{
				b *= (i / 2);
				--doublecount;
			}
			else
				b *= i;
		}
		std::cout << n << " things taken " << m << " at a time is " << a / b << " exactly." << std::endl;
	}
	return 0;
}