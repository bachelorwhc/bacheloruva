#include <iostream>
#include <cmath>

int main()
{
	unsigned long long m, n;
	while (std::cin >> n >> m)
	{
		unsigned long long bm(m);
		if(n == 0 && m == 0)
			break;
		if(n == m)
		{
			std::cout << n << " things taken " << m << " at a time is " << 1 << " exactly." << std::endl;
			continue;
		}
		if(n - m < m)
			m = n - m;
		unsigned long long a(n - m + 1), b(1);
		for(unsigned long long i = 2; (n - m) + i <= n; ++i)
				a *= (n - m + i);
		for(unsigned long long i = 2; i <= m; ++i)
				b *= i;
		unsigned long long ans(a/b);
		std::cout << n << " things taken " << bm << " at a time is " << ans << " exactly." << std::endl;
	}
	return 0;
}