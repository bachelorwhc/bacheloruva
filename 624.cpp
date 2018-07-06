#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <algorithm>

bool is_possible( const std::vector<int>& table, 
                  std::list<int>& songs,
                  int total, 
                  const int pick,
                  std::map<int, int> unpicked_song_table,
                  std::map<int, int>& compare )
{
    --unpicked_song_table[ pick ];
    total -= pick;
    if ( total == 0 )
    {
        compare = unpicked_song_table;
        return true;
    }
    for ( const auto l : songs )
    {
        if ( total >= l && unpicked_song_table[ l ] && table[ total - l ] )
        {
            if ( is_possible( table, songs, total, l, unpicked_song_table, compare ) )
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    while ( std::cin >> n )
    {
        std::vector<int> table( n + 1 );
        int song_count;
        std::cin >> song_count;
        std::map<int, int> unpicked_song_table;
        std::list<int> songs( song_count );
        for ( auto& l : songs )
        {
            std::cin >> l;
            ++unpicked_song_table[ l ];
        }

        int max{ 0 };
        table[ 0 ] = 1;
        songs.sort();
        for ( auto l : songs )
        {
            for ( int i = n; i >= l; --i )
            {
                table[ i ] = table[ i ] || table[ i - l ];
                if ( table[ i ] )
                {
                    if ( i > max )
                        max = i;
                }
            }
        }

        std::reverse( songs.begin(), songs.end() );

        auto compare = unpicked_song_table;
        for ( auto l : songs )
            if ( is_possible( table, songs, max, l, unpicked_song_table, compare ) )
                break;
        for ( const auto& kv : unpicked_song_table )
        {
            int l = kv.first;
            int times = kv.second - compare[l];
            for ( int i = 0; i < times; ++i )
                std::cout << l << ' ';
        }
        std::cout << "sum:" << max << std::endl;
    }
    return 0;
}