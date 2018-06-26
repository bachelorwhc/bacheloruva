#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>
#define VALUE_AT(table, i, j, pitch) (table[pitch * i + j])

using ItemInfo = std::pair<int, int>;

int main() {
	int sets;
	std::cin >> sets;
	for (int _s = 0; _s < sets; ++_s) {
		std::vector<ItemInfo> items;
		std::vector<int> persons;

		int item_count;
		std::cin >> item_count;
		for (int _i = 0; _i < item_count; ++_i) {
			int price, weight;
			std::cin >> price >> weight;
			items.push_back({ price, weight });
		}
		int person_count;
		std::cin >> person_count;
		for (int _p = 0; _p < person_count; ++_p) {
			int weight;
			std::cin >> weight;
			persons.push_back(weight);
		}
		std::sort(persons.begin(), persons.end());
		std::sort(items.begin(), items.end(), [](ItemInfo& lhs, ItemInfo& rhs) {
			return lhs.second < rhs.second;
		});


		std::vector<std::vector<int>> price_table;
		std::vector<std::vector<int>> weight_table;
		for (int i = 0; i < item_count + 1; ++i) {
			price_table.push_back(std::vector<int>(item_count + 1));
			weight_table.push_back(std::vector<int>(item_count + 1));
		}
		for (int i = 0; i < item_count; ++i) {
			price_table[0][i + 1] = items[i].first;
			weight_table[0][i + 1] = items[i].second;
		}
		for (int i = 0; i < item_count; ++i) {
			price_table[i + 1][0] = items[i].first;
			weight_table[i + 1][0] = items[i].second;
		}

		int max = 0;

		for (int i = 1; i <= item_count; ++i) {
			for (int j = 1; j <= item_count; ++j) {
				if(weight_table[])
			}
		}
	}
	return 0;
}