#include <iostream>
#include <vector>

const int MAX = 10000;
int highs[MAX];

int main() {
	int l, h, r;
	for (int i = 0; i < MAX; ++i)
		highs[i] = 0;

	while (std::cin >> l >> h >> r) {
		for (int i = l; i < r; ++i) {
			if (highs[i - 1] > 0)
				highs[i - 1] = highs[i - 1] < h ? h : highs[i - 1];
			else
				highs[i - 1] = h;
		}
	}

	int current = 0;
	bool first = true;
	for (int i = 0; i < MAX; ++i) {
		if (highs[i] != current) {
			current = highs[i];
			if(first) {
				std::cout << i + 1 << " " << current;
				first = false;
			}
			else
				std::cout << " " << i + 1 << " " << current;
		}	
	}
	std::cout << std::endl;
	return 0;
}