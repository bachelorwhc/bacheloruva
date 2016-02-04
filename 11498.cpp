#include <iostream>
#include <vector>

int main() {
	int n_of_input;
	while (std::cin >> n_of_input && n_of_input != 0) {
		int cx, cy;
		std::cin >> cx >> cy;
		for (int i = 0; i < n_of_input; ++i) {
			int tx, ty;
			std::cin >> tx >> ty;
			if (tx == cx || ty == cy) {
				std::cout << "divisa" << std::endl;
				continue;
			}
			std::cout << (ty > cy ? 'N' : 'S') << (tx > cx ? 'E' : 'O') << std::endl;
		}
	}
	return 0;
}