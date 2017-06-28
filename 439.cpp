#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

struct Pos {
	Pos() {};
	Pos(int ix, int iy) : x(ix), y(iy) {};
	Pos(std::string p) {
		x = p[0] - 'a';
		y = p[1] - '1';
	}
	int x;
	int y;
};

namespace std {
	template <>
	struct hash<Pos> {
		size_t operator()(const Pos& p) const noexcept {
			return p.x * 10 + p.y;
		}
	};
}

bool operator==(const Pos& lhs, const Pos& rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

struct Table {
	Table() {
		for(int x = 0; x < 8; ++x) {
			for (int y = 0; y < 8; ++y) {
				Pos p(x, y);
				never_moved.insert(p);
			}
		}
	}
	std::unordered_set<Pos> moved;
	std::unordered_set<Pos> never_moved;
	std::vector<Pos> nextAvailableKnightMoves(const Pos& start);
};

std::vector<Pos> Table::nextAvailableKnightMoves(const Pos& start) {
	if(never_moved.count(start) > 0 && moved.count(start) == 0) {
		moved.insert(start);
		never_moved.erase(start);
	}
	std::vector<Pos> unchecked(8);
	unchecked[0] = Pos(start.x + 2, start.y + 1);
	unchecked[1] = Pos(start.x + 2, start.y - 1);
	unchecked[2] = Pos(start.x - 2, start.y + 1);
	unchecked[3] = Pos(start.x - 2, start.y - 1);
	unchecked[4] = Pos(start.x + 1, start.y + 2);
	unchecked[5] = Pos(start.x + 1, start.y - 2);
	unchecked[6] = Pos(start.x - 1, start.y + 2);
	unchecked[7] = Pos(start.x - 1, start.y - 2);
	std::vector<Pos> ret;
	for (auto& p : unchecked) {
		if (never_moved.count(p) > 0 && moved.count(p) == 0) {
			ret.push_back(p);
			moved.insert(p);
			never_moved.erase(p);
		}
	}
	return ret;
}


int main() {
	std::string s, t;
	while (std::cin >> s >> t) {
		Table table;
		Pos src(s);
		Pos tar(t);
		std::vector<Pos> next = { s };
		int count = 0;
		while(true) {
			std::vector<Pos> next_temp;
			for (auto& m : next) {
				if (m == tar) {
					goto result;
				}
				
				auto&& possible_move = table.nextAvailableKnightMoves(m);
				for (auto& pm : possible_move) {
					next_temp.push_back(pm);
				}
			}
			next = next_temp;
			++count;
		}
		result:
		std::cout << "To get from " << s << " to " << t << " takes " << count << " knight moves." << std::endl;
	}
	return 0;
}

