#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct Hotel
{
    int cost;
    std::vector<int> availables;
};

auto comparator = [ = ]( Hotel* lhs, Hotel* rhs )
{
    return lhs->cost < rhs->cost;
};

int main()
{
    int persons, budget, weeks, hotel_count;
    while ( std::cin >> persons >> budget >> hotel_count >> weeks )
    {
        std::vector<Hotel*> hotels;
        for ( int i = 0; i < hotel_count; ++i )
        {
            Hotel* p_hotel = new Hotel;;
            p_hotel->availables.resize( weeks );
            std::cin >> p_hotel->cost;
            for( int j = 0; j < weeks; ++j )
                std::cin >> p_hotel->availables[ j ];
            hotels.push_back( p_hotel );
        }
        std::sort( hotels.begin(), hotels.end(), comparator );

        bool solution_exist{ true };
        int min_cost{ std::numeric_limits<int>::max() };

        for ( int i = 0; i < weeks; ++i )
        {
            for ( int j = 0; j < hotel_count; ++j )
            {
                int total_cost{ 0 };
                const auto& hotel = *hotels[ j ];
                int available{ hotel.availables[ i ] };

                if ( available < persons )
                    continue;

                total_cost += persons * hotel.cost;

                if ( min_cost > total_cost )
                    min_cost = total_cost;
            }
        }
        if( min_cost > budget )
            solution_exist = false;

        if ( solution_exist )
            std::cout << min_cost << std::endl;
        else
            std::cout << "stay home" << std::endl;

        std::for_each( hotels.begin(), hotels.end(), [ = ]( Hotel* p ) { if ( p ) delete p; } );
    }
    return 0;
}