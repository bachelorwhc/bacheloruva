#include <iostream>
#include <fstream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <cfloat>
#include <cmath>
#include <climits>

struct Vec {
	Vec() : x(0), y(0) {

	}

	Vec(int ix, int iy) : x(ix), y(iy) {
	
	}

	union {
		struct {
			int x;
			int y;
		};
		unsigned long long data;
	};
};

bool operator==(const Vec& lhs, const Vec& rhs) {
	return lhs.data == rhs.data;
}

int sameline(const Vec& v1, const Vec& v2, const Vec& v3) {
	return (v3.x - v1.x)*(v2.y - v1.y) - (v2.x - v1.x)*(v3.y - v1.y);
}

namespace std {
	template <>
	struct hash<Vec> {
		size_t operator()(const Vec& v) const noexcept {
			return v.data;
		}
	};
}

int main() {
	int n, cases, set = 1;
	std::cin >> cases;
	while (std::cin >> n) {
		std::unordered_map<Vec, unsigned int> map;
		std::vector<Vec> gnus;
		for (int i = 0; i < n; ++i) {
			double x, y;
			std::cin >> x >> y;
			Vec v(x * 100, y * 100);
			if(map.count(v) == 0) {
				gnus.push_back(v);
				map[v] = gnus.size() - 1;
			}
		}
		std::cout << "Data set #"<< set <<" contains ";
		if (map.size() == 1) {
			std::cout << "a single gnu.\n";
		}
		else {
			size_t num_of_gnus = map.size();
			int max = 0;
			for (int i = 0; i < num_of_gnus; ++i) {
				for (int j = i + 1; j < num_of_gnus; ++j) {
					unsigned int count = 2;
					for (int k = j + 1; k < num_of_gnus; ++k) {
						if (sameline(gnus[i], gnus[j], gnus[k]) == 0)
							++count;
					}
					if (count > max)
						max = count;
				}
			}
			std::cout << num_of_gnus << " gnus, out of which a maximum of " << max << " are aligned.\n";
		}
		if (set == cases)
			break;
		++set;
	}
	return 0;
}