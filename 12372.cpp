#include <iostream>
#include <vector>

int main() {
	std::vector<int> box(3);
	std::cin >> box[0];
	int i = 1;
	while (std::cin >> box[0] >> box[1] >> box[2]) {
		std::cout << "Case " << i++ << ": ";
		if (box[0] > 20 || box[1] > 20 || box[2] > 20) {
			std::cout << "bad\n";
		}
		else {
			std::cout << "good\n";
		}
	}
	return 0;
}