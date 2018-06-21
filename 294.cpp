#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#ifdef _DEBUG
#include<fstream>
#endif

const int MAX = 100000;
int raw_table[MAX + 1];
std::vector<int> table;

void build_table()
{
	int i = sizeof(raw_table);
	for (int i = 0; i <= MAX; ++i)
		raw_table[i] = 1;
	for (int i = 2; i <= MAX; ++i)
	{
		if (raw_table[i] == 0)
			continue;
		for (int j = 2; i * j < MAX; ++j)
			raw_table[i * j] = 0;
	}
	for (int i = 2; i <= MAX; ++i)
	{
		if (raw_table[i] == 0)
			continue;
		table.push_back(i);
	}
}

void find_maximum_divisors(int min, int max, int& ans, int& divisor_count)
{
	divisor_count = 0;
	ans = 0;
	for (int number = min; number <= max; ++number)
	{
		if (number == 1)
		{
			divisor_count = 1;
			ans = 1;
			continue;
		}
		else if (number <= MAX && raw_table[number] > 0)
		{
			if (divisor_count < 2)
			{
				ans = number;
				divisor_count = 2;
			}
			continue;
		}

		int c_divisor_count{ 1 };

		std::vector<std::pair<int, int>> divisors;
		for (auto p : table)
		{
			if (p > number)
				break;
			std::pair<int, int> divisor{p, 0};
			auto n = number;
			while (n % p == 0)
			{
				n /= p;
				++divisor.second;
			}
			if(divisor.second > 0)
				divisors.push_back(divisor);
		}
		for (auto& d : divisors) 
		{
			c_divisor_count *= (d.second + 1);
		}

		if (c_divisor_count > divisor_count)
		{
			divisor_count = c_divisor_count;
			ans = number;
		}
	}
}

int main()
{
	build_table();
	int n;
	std::cin >> n;
#ifdef _DEBUG
	std::ofstream file("ans.txt");
#endif
	for (int i = 0; i < n; ++i)
	{
		int min, max;
		std::cin >> min >> max;
		int ans, divisor_count;
		find_maximum_divisors(min, max, ans, divisor_count);
#ifdef _DEBUG
		file
#else
		std::cout 
#endif
			<< "Between " << min << " and " << max << ", " 
			<< ans << " has a maximum of " << divisor_count << " divisors." << std::endl;
	}
	return 0;
}