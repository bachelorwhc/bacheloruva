#include <cstdio>

int main()
{
	unsigned int i;
	bool first(true);
	while (scanf("%u", &i))
	{
		if(i == 0)
			break;
		if(first)
		{
			printf("PERFECTION OUTPUT\n");
			first = false;
		}
		printf("%5u  ", i);
		unsigned int count(0);
		for(unsigned int j = 1; j < i; ++j)
		{
			if(i % j == 0)
				count += j;
		}
		if(count == i)
			printf("PERFECT");
		else if(count < i)
			printf("DEFICIENT");
		else
			printf("ABUNDANT");
		printf("\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}