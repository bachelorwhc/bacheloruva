#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using std::vector;
using std::map;
using std::string;
using std::getline;
using std::cout;
using std::cin;

int main() {
	vector<string> n_list;
	map<string, int> count;
	string input;
	int n_of_i;
	cin >> n_of_i;
	cin.ignore();
	for (int i = 0; i < n_of_i; ++i) {
		getline(cin, input);
		string n;
		for (char c : input) {
			if (c == ' ')
				break;
			else
				n += c;
		}
		if (std::find(n_list.begin(), n_list.end(), n) == n_list.end()) {
			n_list.push_back(n);
		}
		if (count.count(n) > 0)
			++count[n];
		else
			count[n] = 1;
	}
	int size = n_list.size();
	std::sort(n_list.begin(), n_list.end());
	for (const string& n : n_list) {
		std::cout << n << " " << count[n] << std::endl;
	}
	return 0;
}
