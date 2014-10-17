#include <iostream>
#include <string>

char TrueIn(char i)
{
	char r;
	switch (i)
	{
	case '=': r = '-'; break;
	case '-': r = '0'; break;
	case '0': r = '9'; break;
	case '9': r = '8'; break;
	case '8': r = '7'; break;
	case '7': r = '6'; break;
	case '6': r = '5'; break;
	case '5': r = '4'; break;
	case '4': r = '3'; break;
	case '3': r = '2'; break;
	case '2': r = '1'; break;
	case '1': r = '`'; break;
	case '\\': r = ']'; break;
	case ']': r = '['; break;
	case '[': r = 'P'; break;
	case 'P': r = 'O'; break;
	case 'O': r = 'I'; break;
	case 'I': r = 'U'; break;
	case 'U': r = 'Y'; break;
	case 'Y': r = 'T'; break;
	case 'T': r = 'R'; break;
	case 'R': r = 'E'; break;
	case 'E': r = 'W'; break;
	case 'W': r = 'Q'; break;
	case '\'': r = ';'; break;
	case ';': r = 'L'; break;
	case 'L': r = 'K'; break;
	case 'K': r = 'J'; break;
	case 'J': r = 'H'; break;
	case 'H': r = 'G'; break;
	case 'G': r = 'F'; break;
	case 'F': r = 'D'; break;
	case 'D': r = 'S'; break;
	case 'S': r = 'A'; break;
	case '/': r = '.'; break;
	case '.': r = ','; break;
	case ',': r = 'M'; break;
	case 'M': r = 'N'; break;
	case 'N': r = 'B'; break;
	case 'B': r = 'V'; break;
	case 'V': r = 'C'; break;
	case 'C': r = 'X'; break;
	case 'X': r = 'Z'; break;
	default:
		break;
	}
	return r;
}

int main()
{
	std::string s;
	while (std::getline(std::cin, s))
	{
		unsigned int len = s.length();
		for (unsigned int i = 0; i < len; ++i)
			if (s[i] == ' ')
				std::cout << ' ';
			else
				std::cout << TrueIn(s[i]);

		std::cout << std::endl;
	}
	return 0;
}