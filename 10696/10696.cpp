#include <iostream>

unsigned long long f91(unsigned long long n)
{
	if(n <= 100)
	{
		return f91(f91(n + 11));
	}
	else
	{
		return n - 10;
	}
}

int main()
{
	unsigned long long n;
	while (std::cin >> n, n != 0)
	{
		std::cout << "f91(" << n << ") = " << f91(n) << std::endl;
	}
	return 0;
}