#include <iostream>
#include <list>
#include <cmath>
#define POS(x, y) (w*y+x)
bool ADJ(int x1, int y1, int x2, int y2) {
	return (abs(x1-x2) < 2) && abs(y1 - y2)< 2;
}

struct Coordinate {
	int x;
	int y;
	Coordinate(int ix, int iy) : x(ix), y(iy) {}
};

struct Node {
	std::list<Coordinate*> nodes;
	int x;
	int y;
	bool m;
	Node(int ix, int iy) :nodes(), x(ix), y(iy), m(false) { Coordinate* pn = new Coordinate(ix, iy); nodes.push_back(pn); }

	bool insert(unsigned int ix, unsigned int iy) {
		for (Coordinate* n : nodes) {
			if (ADJ(n->x, n->y, ix, iy)) {
				Coordinate* pn = new Coordinate(ix, iy);
				nodes.push_back(pn);
				return true;
			}
		}
		return false;
	}

	void mergeall(Node* root) {
		for (Coordinate* n : root->nodes)
			nodes.push_back(n);
	}

	bool merge(Node* root) {
		for (Coordinate* n1 : root->nodes) {
			for (Coordinate* n2 : nodes)
				if (ADJ(n1->x, n1->y, n2->x, n2->y)) {
					mergeall(root);
					return true;
				}
		}
		return false;
	}
};

int count(const int* map, unsigned int size) {
	unsigned int sum = 0;
	for (int i = 0; i < size; ++i)
		sum += map[i] == 1 ? 1 : 0;
	return sum;
}

int main() {
	unsigned int w, h;
	while (std::cin >> h >> w && w > 0 && h > 0) {
		int* map = new int[w*h];
		char input;
		int n_of_o{ 0 };
		std::list<Node*> roots;
		for (int _y = 0; _y < h; ++_y) {
			for (int _x = 0; _x < w; ++_x) {
				std::cin >> input;
				bool inserted = false;
				if (input == '@') {
					for (auto root : roots) {
						if (root->insert(_x, _y)) {
							inserted = true;
							break;
						}
					}
					if (!inserted) {
						Node* n = new Node(_x, _y);
						roots.push_back(n);
					}
				}
			}
		}
		std::list<Node*> roots_clone(roots);
		for (auto root1 : roots_clone) {
			for (auto root2 : roots) {
				if (root1 == root2 || root2->m || root1->m)
					continue;
				else {
					if (root1->merge(root2))
						root2->m = true;
				}
			}
		}
		int sum = 0;
		for (auto root : roots)
			if (!root->m)
				++sum;
		std::cout << sum << std::endl;
		delete[] map;
	}
	return 0;
}