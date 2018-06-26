#include <iostream>
#include <vector>
#include <cstring>
const int max = 1001;
int table[max];

void build_table()
{
	int i = sizeof(table);
	for (int i = 0; i < max; ++i)
		table[i] = 1;
	for (int i = 2; i < max; ++i)
	{
		if (table[i] == 0)
			continue;
		for (int j = 2; i * j < max; ++j)
			table[i * j] = 0;
	}
}

int main() {
	build_table();
	std::vector<int> primes;
	for (int i = 1; i < max; ++i)
		if (table[i])
			primes.push_back(i);

	int m, n;
	while (std::cin >> m >> n)
	{
		std::vector<int> ps;
		for (auto p : primes)
			if (p > m)
				break;
			else
				ps.push_back(p);
		auto k = ps.size();
		std::vector<int> outs;
		if ((k % 2 == 0 && n * 2 > k) || (k % 2 == 1 && n * 2 - 1 > k)) {
			outs = ps;
		}
		else if (k % 2 == 0) {
			int s = ps.size() / 2 - n;
			for (int i = 0; i < n * 2 && i < k; ++i)
				outs.push_back(ps[s + i]);
		}
		else {
			int s = (ps.size() + 1) / 2 - n;
			for (int i = 0; i < n * 2 - 1 && i < k; ++i)
				outs.push_back(ps[s + i]);
		}
		std::cout << m << ' ' << n << ":";
		for (auto p : outs)
			std::cout << ' ' << p;
		std::cout << std::endl << std::endl;
	}
	return 0;
}