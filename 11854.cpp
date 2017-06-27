#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<unsigned long long> t(3);
	while (std::cin >> t[0] >> t[1] >> t[2]) {
		if (t[0] == 0 && t[1] == 0 && t[2] == 0) {
			return 0;
		}
		std::sort(t.begin(), t.end());
		if (t[0] + t[1] > t[2]) {
			if ((t[0] * t[0] + t[1] * t[1]) == t[2] * t[2])
				std::cout << "right\n";
			else
				std::cout << "wrong\n";
		}
		else {
			std::cout << "wrong\n";
		}
	}
	return 0;
}