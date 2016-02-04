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

long FindMaxSubarray(short int* matrix, unsigned short size, unsigned short& left_of_max, unsigned short& right_of_max)
{
	unsigned short left_of_cur = 0;
	unsigned short right_of_cur = 0;
	unsigned short point = 0;
	unsigned short end = size - 1;
	long max = -1270000;
	long count(0);
	bool first(false);
	for(;end < size && point <= end;++point)
	{
		right_of_cur = point;
		count += matrix[point];
		if(count > max)
		{
			right_of_max = right_of_cur;
			left_of_max = left_of_cur;
			max = count;
		}
		if(count < 0)
		{
			count = 0;		
			left_of_cur = point + 1;
		}
	}
	return max;
}

int main()
{
	unsigned short size;
	std::cin >> size;
	short int* matrix = new short int[size];
	//for (unsigned short y = 0; y < size; ++y)
	for (unsigned short x = 0; x < size; ++x)
		//std::cin >> matrix[x + y * size];
			std::cin >> matrix[x];
	unsigned short left_of_max(0);
	unsigned short right_of_max(0);
	std::cout << FindMaxSubarray(matrix, size, left_of_max, right_of_max) << std::endl;
	//std::cout << ' ' << left_of_max << ' ' << right_of_max << std::endl;
	return 0;
}
