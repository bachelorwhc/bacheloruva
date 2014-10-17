#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool IsJolly(std::vector<int>& numbers)
{
	int n(numbers.size());
	int* j = new int[n-1];
	for (int i = 1; i < n; ++i)
	{
		unsigned int d(abs(numbers[i] - numbers[i - 1]));
		if (!(d < n && d >= 1))
			return false;
		if (j[d-1] == 1)
			return false;
		j[d-1] = 1;
	}
	return true;
}

int main()
{
	int n;
	while (std::cin >> n)
	{
		std::vector<int> numbers(n);
		for (int i = 0; i < n; ++i)
		{
			std::cin >> numbers[i];
		}
		if (n == 1)
		{
			if (numbers[0] == 1)
				std::cout << "Jolly" << std::endl;
			else
				std::cout << "Not jolly" << std::endl;
			continue;
		}
		else if (n == 2)
		{
			if (abs(numbers[0] - numbers[1]) == 1)
				std::cout << "Jolly" << std::endl;
			else
				std::cout << "Not jolly" << std::endl;
			continue;
		}
		if (IsJolly(numbers))
			std::cout << "Jolly" << std::endl;
		else
			std::cout << "Not jolly" << std::endl;
	}
	return 0;
}