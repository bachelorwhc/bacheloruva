#include <iostream>

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
	for (unsigned short x = 0; x < size; ++x)
			std::cin >> matrix[x];
	unsigned short left_of_max(0);
	unsigned short right_of_max(0);
	std::cout << FindMaxSubarray(matrix, size, left_of_max, right_of_max) << std::endl;
	return 0;
}
