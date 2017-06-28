#include <iostream>
#include <cmath>

int main() {
	float a, b;
	while (std::cin >> a >> b) {
		if (a == 0 && b == 0)
			return 0;
		int ia = ceilf(sqrtf(a));
		int ib = sqrtf(b);
		int ans = ib - ia;
		std::cout << (ans >= 0 ? (ans + 1) : 0) << '\n';
	}
	return 0;
}