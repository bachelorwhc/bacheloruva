#include <iostream>
#include <vector>

int main() {
	int n_of_input;
	std::cin >> n_of_input;
	for (int i = 0; i < n_of_input; ++i) {
		int n_of_i;
		std::cin >> n_of_i;
		std::vector<int> a(n_of_i);
		int item;
		for (int it = 0; it < n_of_i; ++it) {
			std::cin >> item;
			a[it] = item;
		}
		int max = a[0];
		for (int n : a)
			max = n > max ? n : max;
		std::cout << "Case " << i+1 << ": " << max << std::endl;
	}
	return 0;
}