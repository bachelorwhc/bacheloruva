#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define HEAP_PARENT(POS) ((POS) / 2)

int main()
{
    int times;
    while ( std::cin >> times )
    {
        if ( times == 0 )
            break;
        std::priority_queue< int, std::vector<int>, std::greater<int> > queue;
        int n;
        for ( int i = 1; i <= times; ++i )
        {
            std::cin >> n;
            queue.push( n );
        }

        int cost{ 0 };
        int total_cost{ 0 };

        while( queue.size() > 1 )
        {
            cost = queue.top();
            queue.pop();
            cost += queue.top();
            queue.pop();
            queue.push( cost );
            total_cost += cost;
        }
        std::cout << total_cost << std::endl;
    }
    return 0;
}