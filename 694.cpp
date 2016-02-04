#include <iostream>
#include <cstdio>

int main()
{
	long long A, limit, count(1), item(0);
	while (std::cin >> A >> limit, limit >= 0 && A >= 0)
	{
		long long OA(A);
		while (A != 1)
		{
			if(A % 2 == 0)
			{
				A /= 2;
			}
			else
			{
				A = 3 * A + 1;
			}
			
			if(A >= limit)
			{
				break;
			}
			else
			{
				++count;
			}
		}
		std::cout << "Case " << ++item << ": A = " << OA << ", limit = " << limit << ", number of terms = " << count << std::endl;
		count = 1;
	}
	return 0;
}