#include <iostream>
#include <vector>
#include <algorithm>
#ifdef _DEBUG
#include <fstream>
#endif

int main() {
	std::vector<int> a_way;
	std::vector<int> station;
	std::vector<int> b_way;
	std::vector<int> target;
	a_way.reserve(1000);
	station.reserve(1000);
	b_way.reserve(1000);
	target.reserve(1000);
	
	auto vector_equal = [=](const std::vector<int>& lhs, const std::vector<int>& rhs) {
		auto size = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
		for (int i = 0; i < size; ++i) {
			if (lhs[i] != rhs[i]) {
				return false;
			}
		}
		return true;
	};

	auto move_top = [=](std::vector<int>& lhs, std::vector<int>& rhs) {
		lhs.push_back(rhs.back());
		rhs.pop_back();
	};
	
	int num;
	while (std::cin >> num)
	{
		if (num == 0)
			return 0;

		int input;

		while (std::cin >> input)
		{
			if (input == 0) {
				std::cout << std::endl;
				break;
			}

			do {
				target.push_back(input);
			} while (target.size() < num && std::cin >> input);

			for (int i = num; i > 0; --i)
				a_way.push_back(i);

			bool ok = true;

			while (!a_way.empty()) 
			{
				for (int i = a_way.size() - 1; i >= 0; --i) {
					auto it = target.begin() + b_way.size();
					if (a_way[i] == *it) {
						for (int j = a_way.size(); j > i; --j) {
							move_top(station, a_way);
						}
						break;
					}
				}

				for (int i = station.size() - 1; i >= 0; --i) {
					auto it = target.begin() + b_way.size();
					if (station[i] == *it) {
						move_top(b_way, station);
					}
				}

				if (!vector_equal(b_way, target)) {
					ok = false;
					break;
				}
			}
			
			if (ok)
				std::cout << "Yes" << std::endl;
			else
				std::cout << "No" << std::endl;

			a_way.clear();
			station.clear();
			b_way.clear();
			target.clear();
		}
	}
	return 0;
}

