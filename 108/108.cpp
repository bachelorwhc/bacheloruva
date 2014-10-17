#include <iostream>
#include <vector>
#include <algorithm>
#define MATRIXINFO matrix, size

struct Group
{
	Group(short sx, short ex, short sy, short ey) :
		x1(sx), x2(ex), y1(sy), y2(ey)
	{

	};
	short x1;
	short x2;
	short y1;
	short y2;
};

short GetElement(short int* matrix, unsigned short size, unsigned short x, unsigned short y)
{
	return matrix[x + y * size];
}

long long GroupCount(short int* matrix, short size, Group& g)
{
	if (g.x1 > g.x2 || g.y1 > g.y2 || g.x1 >= size || g.x1 >= size || g.y1 < 0 || g.y2 < 0 || g.x1 < 0 || g.y1 < 0 || g.x2 >= size || g.y2 >= size)
		return -127000000;
	long long sum(0);
	for (short x = g.x1; x <= g.x2; ++x)
		for (short y = g.y1; y <= g.y2; ++y)
			sum += GetElement(MATRIXINFO, x, y);
	return sum;
}

int main()
{
	unsigned short size;
	std::cin >> size;
	short int* matrix = new short int[size * size];
	for (unsigned short y = 0; y < size; ++y)
		for (unsigned short x = 0; x < size; ++x)
			std::cin >> matrix[x + y * size];
	long long max = 0;
	short sx = 0, sy = 0;
	short ex = size - 1, ey = size - 1;
	Group start_g(sx, ex, sy, ey);
	max = GroupCount(MATRIXINFO, start_g);
	short keep = 0;
	while (true)
	{
		Group g1(sx + 1 + keep, ex, sy, ey);
		Group g2(sx, ex - 1 - keep, sy, ey);
		Group g3(sx, ex, sy + 1 + keep, ey);
		Group g4(sx, ex, sy, ey - 1 - keep);
		Group g1r(0, sx + keep, sy, ey);
		Group g2r(ex - keep, size - 1, sy, ey);
		Group g3r(sx, ex, 0, sy + keep);
		Group g4r(sx, ex, ey - keep, size - 1);
		long long m1(GroupCount(MATRIXINFO, g1));
		long long m2(GroupCount(MATRIXINFO, g2));
		long long m3(GroupCount(MATRIXINFO, g3));
		long long m4(GroupCount(MATRIXINFO, g4));
		long long m1r(GroupCount(MATRIXINFO, g1r));
		long long m2r(GroupCount(MATRIXINFO, g2r));
		long long m3r(GroupCount(MATRIXINFO, g3r));
		long long m4r(GroupCount(MATRIXINFO, g4r));

		if (m1 == -127000000 && m2 == -127000000 && m3 == -127000000 && m4 == -127000000)
			break;
		if (m1 == -127000000)
			m1r = -127000000;
		if (m2 == -127000000)
			m2r = -127000000;
		if (m3 == -127000000)
			m3r = -127000000;
		if (m4 == -127000000)
			m4r = -127000000;
		max = m1 > max ? m1 : max;
		max = m2 > max ? m2 : max;
		max = m3 > max ? m3 : max;
		max = m4 > max ? m4 : max;
		max = m1r > max ? m1r : max;
		max = m2r > max ? m2r : max;
		max = m3r > max ? m3r : max;
		max = m4r > max ? m4r : max;
		if (m1 == max)
		{
			++sx;
			keep = 0;
		}
		else if (m2 == max)
		{
			--ex;
			keep = 0;
		}
		else if (m3 == max)
		{
			++sy;
			keep = 0;
		}
		else if (m4 == max)
		{
			--ey;
			keep = 0;
		}
		else if (m1r == max)
		{
			sx = g1r.x1;
			sy = g1r.y1;
			ex = g1r.x2;
			ey = g1r.y2;
			keep = 0;
		}
		else if (m2r == max)
		{
			
			sx = g2r.x1;
			sy = g2r.y1;
			ex = g2r.x2;
			ey = g2r.y2;
			keep = 0;
		}
		else if (m3r == max)
		{
			sx = g3r.x1;
			sy = g3r.y1;
			ex = g3r.x2;
			ey = g3r.y2;
			keep = 0;
		}
		else if (m4r == max)
		{
			sx = g4r.x1;
			sy = g4r.y1;
			ex = g4r.x2;
			ey = g4r.y2;
			keep = 0;
		}
		else
			++keep;
	}

	std::cout << max << std::endl;
	return 0;
}