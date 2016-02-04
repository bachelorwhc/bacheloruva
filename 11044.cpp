#include <iostream>

int main() {
	int n_of_i;
	std::cin >> n_of_i;
	for (int i = 0; i < n_of_i; ++i) {
		int x, y;
		std::cin >> x >> y;
		std::cout << (x / 3) * (y / 3) << std::endl;
	}
	return 0;
}