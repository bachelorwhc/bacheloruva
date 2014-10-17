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
	long long sum(0);
	for (short x = g.x1; x <= g.x2; ++x)
		for (short y = g.y1; y <= g.y2; ++y)
			sum += GetElement(MATRIXINFO, x, y);
	return sum;
}

long GetMax(short int* matrix, short size)
{
	long max(0);
	for (unsigned int maxleft = 0, maxright = 0, end = size - 1, now = 0;;)
	{
		max += matrix[now];
		if (max < 0)
		{
			maxleft = now;
			maxright = now + 1;
		}
		else if ()
		{

		}

	}
}

int main()
{
	unsigned short size;
	std::cin >> size;
	//short int* matrix = new short int[size * size];
	short int* matrix = new short int[size];
	//for (unsigned short y = 0; y < size; ++y)
	for (unsigned short x = 0; x < size; ++x)
		std::cin >> matrix[x];
			//std::cin >> matrix[x + y * size];


	for (unsigned short i = 0; i < size; ++i)
	{

	}
	return 0;
}