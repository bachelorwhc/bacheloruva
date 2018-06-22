#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int num;
    while ( std::cin >> num )
    {
        std::cout << "Lumberjacks:" << std::endl;
        for ( int j = 0; j < num; ++j )
        {
            std::vector<int> beards( 10 );
            for ( int i = 0; i < 10; ++i )
            {
                std::cin >> beards[ i ];
            }
            auto sorted = beards;
            std::sort( sorted.begin(), sorted.end() );
            bool asc = true;
            bool des = true;
            for ( int i = 0; i < 10; ++i )
            {
                if ( sorted[ i ] != beards[ i ] )
                {
                    asc = false;
                    break;
                }
            }
            for ( int i = 0; i < 10; ++i )
            {
                if ( sorted[ 9 - i ] != beards[ i ] )
                {
                    des = false;
                    break;
                }
            }

            if ( des || asc )
            {
                std::cout << "Ordered" << std::endl;
            }
            else
            {
                std::cout << "Unordered" << std::endl;
            }
        }
    }
    return 0;
}