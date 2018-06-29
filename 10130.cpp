#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#ifdef _DEBUG
#include <fstream>
#endif

struct ItemInfo
{
    int price;
    int weight;
};

ItemInfo operator+ ( const ItemInfo& lhs, const ItemInfo& rhs )
{
    ItemInfo ret;
    ret.price = lhs.price + rhs.price;
    ret.weight = lhs.weight + rhs.weight;
    return ret;
}

ItemInfo operator- ( const ItemInfo& lhs, const ItemInfo& rhs )
{
    ItemInfo ret;
    ret.price = lhs.price - rhs.price;
    ret.weight = lhs.weight - rhs.weight;
    return ret;
}

bool operator< ( const ItemInfo& lhs, const ItemInfo& rhs )
{
    return lhs.weight < rhs.weight;
}

int main()
{
    int set;
    std::cin >> set;

#ifdef _DEBUG
    std::ofstream file( "ans.txt" );
#endif

    for ( int _s = 0; _s < set; ++_s )
    {
#pragma region input
        int item_count;
        std::cin >> item_count;

        std::vector<ItemInfo> items( item_count );
        for ( int i = 0; i < item_count; ++i )
        {
            std::cin >> items[ i ].price >> items[ i ].weight;
        }

        std::sort( items.begin(), items.end() );

        int person_count;
        std::cin >> person_count;
        std::vector<int> persons( person_count );

        int max_carry = 0;
        for ( int i = 0; i < person_count; ++i )
        {
            std::cin >> persons[ i ];
            if ( persons[ i ] > max_carry )
                max_carry = persons[ i ];
        }
#pragma endregion input

        std::vector<int> weight_price_table;
        weight_price_table.reserve( max_carry );

        int total{ 0 };
        for ( auto curr_carry : persons )
        {
            weight_price_table.clear();
            weight_price_table.resize( curr_carry + 1 );

            for ( const auto& item : items )
            {
                if ( item.weight > curr_carry )
                    continue;
                
                for ( int i = curr_carry; i >= item.weight; --i )
                {
                    auto prev = weight_price_table[ i - item.weight ];
                    weight_price_table[ i ] = std::max( prev + item.price,
                                                        weight_price_table[ i ] );
                }
            }

            total += weight_price_table.back();
        }

#ifdef _DEBUG
        if ( file.is_open() )
        {
            file << total << std::endl;
        }
#endif
        std::cout << total << std::endl;
    }
#ifdef _DEBUG
    file.close();
#endif
    return 0;
}