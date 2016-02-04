#include <iostream>
#include <vector>

bool corrupt(int* m, int size) {
	for (int y = 0; y < size; ++y) {
		int sum_r = 0;
		for (int x = 0; x < size; ++x) {
			sum_r += m[x*size + y];
		}
		if (sum_r % 2 == 1)
			return true;
	}
	return false;
}

std::vector<int> oddpoint(int* m, int size) {
	std::vector<int> points;
	for (int y = 0; y < size; ++y) {
		int sum_r = 0;
		for (int x = 0; x < size; ++x) {
			sum_r += m[x*size + y];
		}
		if (sum_r % 2 == 1)
			points.push_back(y);
	}
	return points;
}

int main() {
	int size;
	while (std::cin >> size && size != 0) {
		int* m_r_read = new int[size*size];
		int* m_c_read = new int[size*size];
		for (int y = 0; y < size; ++y) {
			for (int x = 0; x < size; ++x) {
				std::cin >> m_r_read[y*size + x];
				m_c_read[x*size + y] = m_r_read[y*size + x];
			}
		}
		std::vector<int>&& r(oddpoint(m_c_read, size));
		std::vector<int>&& c(oddpoint(m_r_read, size));
		if (r.size() == 0 && c.size() == 0)
			std::cout << "OK";
		else if (r.size() == 1 && c.size() == 1)
			std::cout << "Change bit (" << r[0] + 1 << "," << c[0] + 1 << ")";
		else
			std::cout << "Corrupt";
		std::cout << std::endl;
		delete[] m_r_read;
		delete[] m_c_read;
	}
	return 0;
}