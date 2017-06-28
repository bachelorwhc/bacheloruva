#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main() {
	int n_b, n_q;
	int count = 1;
	while (std::cin >> n_b >> n_q) {
		if (n_b == 0 && n_q == 0)
			return 0;
		std::vector<int> bs(n_b);
		std::unordered_set<int> bc;
		for(int i = 0; i < n_b; ++i) {
			std::cin >> bs[i];
			bc.insert(bs[i]);
		}
		std::sort(bs.begin(), bs.end());
		std::cout << "CASE# " << count << ":\n";
		for (int i = 0; i < n_q; ++i) {
			int w = 0;
			std::cin >> w;
			if (bc.count(w) > 0) {
				for (int iv = 0; iv < bs.size(); ++iv) {
					if (bs[iv] == w) {
						std::cout << w << " found at " << iv + 1 << '\n';
						break;
					}
				}
			}
			else {
				std::cout << w << " not found\n";
			}
		}
		++count;
	}
	return 0;
}