#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
const int MAX_NODE_COUNT = 8192 + 1;
const int MAX_K = 12;
const int MAX_PICK = 6;
struct Node;
Node* _node_pool;
int _next_allo_node = 1;

struct Node
{
    int value;
    Node* parent;
    Node* left;
    Node* right;
};

void Init()
{
    _node_pool = new Node[ MAX_NODE_COUNT ];
}

void Finalize()
{
    delete[] _node_pool;
}

void AssignNode( Node*& pn )
{
    pn = _node_pool + _next_allo_node;
    ++_next_allo_node;
}

void CreateDecisionTree( int depth )
{
    auto root = _node_pool + 0;
    root->value = -1;
    root->parent = nullptr;
    std::vector<Node*> nodes ={ root };
    nodes.reserve( MAX_NODE_COUNT );
    while ( depth > 0 )
    {
        std::vector<Node*> copy = nodes;
        nodes.clear();
        for ( auto pn : copy )
        {
            AssignNode( pn->left );
            AssignNode( pn->right );
            pn->left->parent = pn;
            pn->right->parent = pn;
            pn->left->value = 1;
            pn->right->value = 0;
            nodes.push_back( pn->left );
            nodes.push_back( pn->right );
        }
        --depth;
    }
}

void PrintAnswer( const std::vector<int>& numbers, Node* curr, int depth )
{
    std::vector<int>ans( MAX_PICK );
    int index = MAX_PICK - 1;
    --depth;
    while ( curr && index >= 0 && depth >= 0 )
    {
        if ( curr->value > 0 )
        {
            ans[ index ] = numbers[ depth ];
            --index;
        }
        curr = curr->parent;
        --depth;
    }
    std::cout << ans[ 0 ];
    for ( int i = 1; i < MAX_PICK; ++i )
        std::cout << ' ' << ans[ i ];
    std::cout << '\n';
}

void TraverseCombinationAndPrintAnswer( int k, const std::vector<int>& numbers, Node* curr, int depth, int picked )
{
    if ( depth != -1 && depth > numbers.size() )
        return;
    if ( curr->value > 0 )
        ++picked;
    if ( picked == MAX_PICK )
    {
        PrintAnswer( numbers, curr, depth );
        return;
    }
    TraverseCombinationAndPrintAnswer( k, numbers, curr->left, depth + 1, picked );
    TraverseCombinationAndPrintAnswer( k, numbers, curr->right, depth + 1, picked );
}

int main()
{
    Init();
    Node* root = _node_pool + 0;
    int k;
    CreateDecisionTree( 12 );
    int first = true;
    while ( std::cin >> k )
    {
        if ( k == 0 )
            break;
        else
        {
            if ( !first )
                std::cout << '\n';
            first = false;
        }
        std::vector<int> ns( k );
        for ( int i = 0; i < k; ++i )
            std::cin >> ns[ i ];
        std::sort( ns.begin(), ns.end() );
        TraverseCombinationAndPrintAnswer( k, ns, root, 0, 0 );
    }
    Finalize();
    return 0;
}