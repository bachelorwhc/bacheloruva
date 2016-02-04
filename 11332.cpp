#include <iostream>
#include <string>
#include <sstream>

std::string sum_number_string(const std::string& nstr) {
	unsigned long sum{ 0 };
	for(char c : nstr) {
		sum += c - '0';
	}
	std::string ret;
	std::stringstream sstream; 
	sstream << sum;
	sstream >> ret;
	return ret;
}

int main() {
	std::string nstr;
	while (std::cin >> nstr && nstr != "0") {
		std::string s(sum_number_string(nstr));
		while(s.size() > 1) {
			s = (sum_number_string(s));
		}
		std::cout << s << std::endl;
	}
	return 0;
}