#include <iostream>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cfloat>

struct Vector;
struct Vector {
	double x;
	double y;

	Vector operator/(const double rhs) {
		Vector ret;
		ret.x = x / rhs;
		ret.y = y / rhs;
		return ret;
	}

	double getDistance(const Vector& rhs);
};

Vector operator/(const double lhs, const Vector& rhs) {
	Vector ret;
	ret.x = lhs / rhs.x;
	ret.y = lhs / rhs.y;
	return ret;
}

Vector operator+(const Vector& lhs, const Vector& rhs) {
	Vector ret;
	ret.x = lhs.x + rhs.x;
	ret.y = lhs.y + rhs.y;
	return ret;
}

Vector operator-(const Vector& lhs, const Vector& rhs) {
	Vector ret;
	ret.x = lhs.x - rhs.x;
	ret.y = lhs.y - rhs.y;
	return ret;
}

using oVector = std::pair<Vector, Vector>;
oVector getBisection(const Vector& v1, const Vector& v2) {
	oVector ret;
	ret.first = (v1 + v2) / 2.0;
	ret.second = (v1 - v2);
	std::swap(ret.second.x, ret.second.y);
	ret.second.x = -ret.second.x;
	return ret;
}

Vector getIntersection(const oVector& v1, const oVector& v2) {
	Vector ret;
	double a1 = v1.second.y / v1.second.x; double b1 = v1.first.y - a1 * v1.first.x;
	double a2 = v2.second.y / v2.second.x; double b2 = v2.first.y - a2 * v2.first.x;
	ret.x = -(b1 - b2) / (a1 - a2);
	ret.y = ret.x * a1 + b1;
	return ret;
}

double Vector::getDistance(const Vector& rhs) {
	auto&& r = rhs - *this;
	return sqrt(r.x * r.x + r.y * r.y);
}

const double PI = acos(-1);

int main() {
	Vector p[3];
	int n, id = 1;
	while (std::cin >> n) {
		if (n == 0)
			return 0;
		std::cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y;
		auto&& b1 = getBisection(p[0], p[1]);
		auto&& b2 = getBisection(p[1], p[2]);
		auto&& c = getIntersection(b1, b2);
		auto&& v = p[0] - c;
		double angle = 360.0 / n;
		Vector min, max;
		min.x = FLT_MAX; min.y = FLT_MAX;
		max.x = FLT_MIN; max.y = FLT_MIN;
		for (int i = 0; i < n; ++i) {
			double x = v.x * cos(angle * i * PI / 180.0) + v.y * sin(angle * i * PI / 180.0);
			double y = v.x * -sin(angle * i * PI / 180.0) + v.y * cos(angle * i * PI / 180.0);
			if (x < min.x) min.x = x;
			if (y < min.y) min.y = y;
			if (x > max.x) max.x = x;
			if (y > max.y) max.y = y;
		}
		auto&& d = max - min;
		double area = d.x * d.y;
		printf("Polygon %d: %.3f\n", id++, area);
	}
	return 0;
}
