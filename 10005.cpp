#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>
#include <limits>

const double epsilon = std::numeric_limits<double>::epsilon();

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

	Vec operator-(const Vec& v) const {
		return Vec(x - v.x, y - v.y);
	}

	Vec operator/(const double s) const {
		return Vec(x/s, y/s);
	}

	double operator*(const Vec& v) const {
		return x * v.x + y * v.y;
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
		return abs(v.getDistance(center) - radii) <= epsilon;
	};

	Vec center;
	double radii = 0.0;
};

void setCircle(Circle& circle, const std::vector<unsigned int>& triangle, const std::vector<Vec>& points) {
	double t[3];
	for (int i = 0; i < 3; ++i) {
		t[i] = points[triangle[i]] * points[triangle[i]];
	}
	Vec tri[3];
	for (int i = 0; i < 3; ++i) {
		tri[i] = points[triangle[i]];
	}
	double p =
		tri[0].x * tri[1].y +
		tri[1].x * tri[2].y +
		tri[2].x * tri[0].y -
		tri[0].x * tri[2].y -
		tri[1].x * tri[0].y -
		tri[2].x * tri[1].y;
	Vec circum(
		(t[1] * tri[2].y + t[0] * tri[1].y + t[2] * tri[0].y - t[1] * tri[0].y - t[2] * tri[1].y - t[0] * tri[2].y) / p / 2.0,
		(t[2] * tri[1].x + t[1] * tri[0].x + t[0] * tri[2].x - t[0] * tri[1].x - t[1] * tri[2].x - t[2] * tri[0].x) / p / 2.0
	);

	Vec&& ad = circum - tri[0];
	Vec&& ab = tri[1] - tri[0];
	Vec&& ac = tri[2] - tri[0];

	Vec max, min;
	min.x = FLT_MAX; min.y = FLT_MAX;
	max.x = FLT_MIN; max.y = FLT_MIN;
	double max_distance = 0.0;
	for (int i = 0; i < 3; ++i) {
		auto d = tri[i].getDistance(tri[(i + 1) % 3]);
		if ((d - max_distance) > -epsilon) {
			max = tri[i];
			min = tri[(i + 1) % 3];
			max_distance = d;
		}
	}
	circle.center = (min + max) / 2;
	for (const auto& t : tri) {
		auto r = circle.center.getDistance(t);
		if(r > circle.radii) {
			circle.radii = r;
		}
	}
	auto cr = circum.getDistance(tri[0]);
	if (cr < circle.radii) {
		circle.center = circum;
		circle.radii = cr;
	}
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
				tri_init = true;
			}
			if (i > 2) {
				if (!circle.inCircle(v)) {
					Circle temp_circle;
					for (unsigned int ti = 0; ti < i; ++ti) {
						for (unsigned int tj = ti + 1; tj < i; ++tj) {
							setCircle(temp_circle, { ti, tj, i }, points);
							if ((temp_circle.radii - circle.radii) > 0.0) {
								circle = temp_circle;
								triangle[0] = ti;
								triangle[1] = tj;
								triangle[2] = i;
							}
						}
					}
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
			if ((radii * 2.0 - distance) <= epsilon) {
				ans = true;
			}
			else {
				ans = false;
			}
		}
		else {
			if ((circle.radii - radii) <= epsilon) {
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