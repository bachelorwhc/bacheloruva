#include <iostream>
#include <vector>
#include <string>

int main() {
	std::vector<std::string> all_string;
	std::string s;
	int maxlen = 0;
	while (std::getline(std::cin, s)) {
		all_string.push_back(s);
		maxlen = s.size() > maxlen ? s.size() : maxlen;
	}
	unsigned int line = all_string.size();
	char* c = new char[line * maxlen];
	for (int i = 0; i < maxlen * line; ++i)
		c[i] = ' ';
	for (int i = 0; i < line; ++i) {
		std::string currentline{ all_string[i] };
		for (int ci = 0; ci < currentline.size(); ++ci) {
			int index = ci * line + line - i - 1;
			c[index] = currentline[ci];
		}
	}
	for (int i = 0; i < maxlen; ++i) {
		for (int ci = 0; ci < line; ++ci)
			std::cout << c[i * line + ci];
		std::cout << std::endl;
	}
	delete[] c;
	return 0;
}