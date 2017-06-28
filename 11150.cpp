#include <iostream>

int main() {
	int n;
	while (std::cin >> n) {
		bool bonus(false);
		int count = n;
		for (; n >= 3;) {
			if (n % 3 == 2 && !bonus) {
				bonus = true;
				n += 1;
			}
			count += (n / 3);
			n = n / 3 + n % 3;
		}
		if (n == 2 && !bonus)
			++count;
		std::cout << count << '\n';
	}
	return 0;
}