#include <iostream>
#include <string>

int main()
{
    std::string input;
    int count = 0;
    while ( std::cin >> input )
    {
        if ( input == "*" )
            return 0;
        ++count;
        std::cout << "Case " << count << ": ";
        if ( input == "Hajj" )
            std::cout << "Hajj-e-Akbar";
        else
            std::cout << "Hajj-e-Asghar";
        std::cout << std::endl;
    }
    return 0;
}