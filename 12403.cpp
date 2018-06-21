#include <iostream>
#include <string>

int main()
{
    int n;
    while ( std::cin >> n )
    {
        int total{ 0 };
        for ( int i = 0; i < n; ++i )
        {
            std::string input;
            std::cin >> input;
            if ( input == "donate" )
            {
                int money;
                std::cin >> money;
                total += money;
            }
            else
                std::cout << total << std::endl;
        }
    }
    return 0;
}