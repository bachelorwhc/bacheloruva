#include <iostream>
#include <vector>
#include <climits>
#define INDEX_2D_SQUARE(x, y, len) ((y) * (len) + (x))
const int MAX = INT_MAX / 2;

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
	int wood_length;
	while (std::cin >> wood_length && wood_length != 0) {
		int num_of_marks;
		cin >> num_of_marks;
		std::vector<int> marks;
		marks.push_back(0);
		int mark;
		for (int i = 0; i < num_of_marks; ++i) {
			cin >> mark;
			marks.push_back(mark);
		}
		marks.push_back(wood_length);
		num_of_marks = marks.size();
		int* score = new int[num_of_marks * num_of_marks];
		for (int i = 0; i < num_of_marks * num_of_marks; ++i)
			score[i] = 0;

		for (int start = 2; start < num_of_marks; ++start) {
			for (int x = start; x < num_of_marks; ++x) {
				score[INDEX_2D_SQUARE(x - start, x, num_of_marks)] = MAX;
				int diff = marks[x] - marks[x - start];
				int prev = MAX;
				for (int i = 1; i < start; ++i) {
					int sum = score[INDEX_2D_SQUARE(x - start, x - start + i, num_of_marks)] + score[INDEX_2D_SQUARE(x - start + i, x, num_of_marks)];
					prev = sum > prev ? prev : sum;
				}
				int lhs = prev + diff;
				int rhs = score[INDEX_2D_SQUARE(x - start, x, num_of_marks)];
				int s = lhs > rhs ? rhs : lhs;
				score[INDEX_2D_SQUARE(x - start, x, num_of_marks)] = s;
			}
		}
		cout << "The minimum cutting is " << score[INDEX_2D_SQUARE(0, num_of_marks - 1, num_of_marks)] << "." << endl;
		delete[] score;
	}
	return 0;
}