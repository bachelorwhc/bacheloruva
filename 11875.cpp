#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> team;
    team.reserve( 10 );
    int set;
    std::cin >> set;
    for( int i = 0; i < set; ++i )
    {
        int n;
        std::cin >> n;
        team.clear();
        team.resize( n );
        for ( int p = 0; p < n; ++p )
            std::cin >> team[ p ];
        std::sort( team.begin(), team.end() );
        std::cout << "Case " << i + 1 << ": " << team[ n / 2 ] << std::endl;
    }
    return 0;
}