#include<iostream>
#include<map>
#include<vector>

int main()
{
    int n;
    std::map<int, int> ans;
    std::vector<int> order;
    while ( std::cin >> n )
    {
        if ( ans.count( n ) == 0 )
        {
            order.push_back( n );
        }
        ++ans[ n ];
    }
    for ( auto n : order )
    {
        std::cout << n << ' ' << ans[ n ] << std::endl;
    }
    return 0;
}