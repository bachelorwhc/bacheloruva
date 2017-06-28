#include <iostream>

int main() {
	int temp;
	std::cin >> temp;
	int n_shops;
	while (std::cin >> n_shops) {
		int min = 100;
		int max = -1;
		for (int i = 0; i < n_shops; ++i) {
			int x;
			std::cin >> x;
			if (x < min)
				min = x;
			if (x > max)
				max = x;
		}
		std::cout << (max - min) * 2 << std::endl;
	}
	return 0;
}