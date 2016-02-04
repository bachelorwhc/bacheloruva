#include <cstdio>
#include <iostream>
#include <vector>

int main()
{
	unsigned int it;
	std::cin >> it;
	for (unsigned int i = 0; i < it; ++i)
	{
		unsigned int stu_num;
		std::cin >> stu_num;
		std::vector<unsigned short> grade(stu_num);
		double total_grade = 0.0f;
		for (unsigned int j = 0; j < stu_num; ++j)
		{
			std::cin >> grade[j];
			total_grade += grade[j];
		}
		double average = total_grade / stu_num;
		unsigned short above = 0;
		for (unsigned int j = 0; j < stu_num; ++j)
		{
			if ((double)grade[j] > average)
				++above;
		}

		printf("%.3f%%\n", above / (double)stu_num * 100.0f);
	}
	return 0;
}