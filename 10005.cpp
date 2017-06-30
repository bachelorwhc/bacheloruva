#include <iostream>
#include <vector>
#include <cfloat>
#include <cmath>
#include <climits>
#include <algorithm>

struct Vec {
	Vec() : x(0), y(0) {

	}

	Vec(double ix, double iy) : x(ix), y(iy) {

	}

	double getDistance(const Vec& v) const {
		return sqrt((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y));
	}

	Vec operator+(const Vec& v) const {
		return Vec(x + v.x, y + v.y);
	}

	Vec operator/(const double s) const {
		return Vec(x/s, y/s);
	}

	double x;
	double y;
};

struct Circle {
	Circle() : center(), radii(0.0) {

	}
	Circle(double ix, double iy, double radius) : center(ix, iy), radii(radius) {

	}

	bool inCircle(const Vec& v) {
		return v.getDistance(center) <= (radii + FLT_EPSILON);
	};

	Vec center;
	double radii;
};

void setCircle(Circle& circle, const std::vector<unsigned int>& tri, const std::vector<Vec>& points) {
	circle.center = (points[tri[0]] + points[tri[1]] + points[tri[2]]) / 3.0f;
	circle.radii = circle.center.getDistance(points[tri[0]]);
}

int main() {
	unsigned int n;
	while (std::cin >> n) {
		if (n == 0)
			return 0;
		Circle circle;
		bool tri_init = false;
		std::vector<unsigned int> triangle(3);
		std::vector<Vec> points(n);
		for (unsigned int i = 0; i < n; ++i) {
			Vec v;
			std::cin >> v.x >> v.y;
			points[i] = v;
			if (!tri_init && i > 1) {
				triangle[0] = 0;
				triangle[1] = 1;
				triangle[2] = 2;
				setCircle(circle, triangle, points);
			}
			if (i > 2) {
				if (!circle.inCircle(v)) {
					Circle t_cs[3];
					setCircle(t_cs[0], { triangle[0], triangle[1], i }, points); // 2
					setCircle(t_cs[1], { triangle[1], triangle[2], i }, points); // 0
					setCircle(t_cs[2], { triangle[2], triangle[0], i }, points); // 1
					int max = 0;
					int change = 2;
					for (int ci = 1; ci < 3; ++ci) {
						if (t_cs[ci].radii > t_cs[max].radii) {
							max = ci;
							change = (ci + 2) % 3;
						}
					}
					circle = t_cs[max];
					triangle[change] = i;
				}
			}
		}
		double radii;
		std::cin >> radii;
		bool ans = false;
		if (n == 1) {
			ans = true;
		}
		else if (n == 2) {
			double distance = points[0].getDistance(points[1]);
			if ((radii * 2.0 + FLT_EPSILON) >= (distance)) {
				ans = true;
			}
			else {
				ans = false;
			}
		}
		else {
			if (circle.radii <= (radii + FLT_EPSILON)) {
				ans = true;
			}
			else {
				ans = false;
			}
		}
		if (ans)
			std::cout << "The polygon can be packed in the circle.\n";
		else
			std::cout << "There is no way of packing that polygon.\n";
	}
	return 0;
}