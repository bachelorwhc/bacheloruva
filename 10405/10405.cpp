#include <iostream>
#include <vector>
#include <string>
typedef std::vector<unsigned int> Row;
typedef std::vector<Row> Map;

int main()
{
	std::string strf, strb;
	while (std::getline(std::cin, strf))
	{
		std::getline(std::cin, strb);
		unsigned int f_len (strf.length());
		unsigned int b_len (strb.length());
		Map map;
		for(unsigned int i = 0; i <= b_len; ++i)
			map.push_back(Row(f_len + 1));

		for(unsigned int i = 1; i <= b_len; ++i)
		{
			for(unsigned int j = 1; j <= f_len; ++j)
			{
				if(strf[j - 1] == strb[i - 1])
					map[i][j] = map[i - 1][j - 1] + 1;
				else
					map[i][j] = map[i][j - 1] > map[i - 1][j] ? map[i][j - 1] : map[i - 1][j];
			}
		}
		std::cout << map[b_len][f_len] << std::endl;
	}
	return 0;
}