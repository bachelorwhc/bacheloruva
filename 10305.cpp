#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using link = std::list<int>;
int main() {
	int n_tasks;
	int n_relas;
	while (std::cin >> n_tasks >> n_relas) {
		if (n_tasks == 0 && n_relas == 0)
			return 0;
		std::vector<link> tasks(n_tasks);
		for (int i = 0; i < n_relas; ++i) {
			int s, l;
			std::cin >> s >> l;
			tasks[l - 1].push_back(s - 1);
		}
		std::unordered_set<int> executed(n_tasks);
		int count = 0;
		for (int i = 0; i < n_tasks; ++i) {
			if (tasks[i].size() == 0) {
				std::cout << i + 1 << ' ';
				executed.insert(i);
				++count;
			}
		}
		while (count != n_tasks) {
			for (int i = 0; i < n_tasks; ++i) {
				if (executed.count(i) > 0)
					continue;
				else {
					for (auto it = tasks[i].begin(); it != tasks[i].end();) {
						if (executed.count(*it) > 0) {
							if (it == tasks[i].begin()) {
								tasks[i].erase(it);
								it = tasks[i].begin();
							}
							else {
								auto temp = it;
								--temp;
								tasks[i].erase(it);
								it = temp;
							}
						}
						else {
							++it;
						}
					}
				}
				if (tasks[i].size() == 0) {
					std::cout << i + 1 << ' ';
					executed.insert(i);
					++count;
				}
			}
		}
		std::cout << '\n';
	}
	return 0;
}