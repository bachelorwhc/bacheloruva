#include <iostream>

int main() {
	int n_of_i = 0;
	std::cin >> n_of_i;
	for (int i = 0; i < n_of_i; ++i) {
		int n_of_p;
		std::cin >> n_of_p;
		int prev;
		int current;
		int low = 0, high = 0;
		std::cin >> prev;
		for (int p = 1; p < n_of_p; ++p) {
			std::cin >> current;
			if (current > prev)
				++high;
			else if (prev > current)
				++low;
			prev = current;
		}
		std::cout << "Case " << i + 1 << ": " << high << " " << low << std::endl;
	}
	return 0;
}