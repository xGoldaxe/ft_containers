#include "../ft.hpp"
#include "../ft.hpp"
#include <vector>
#include <iostream>

int main( void ) {

    ft::vector<std::string> t( static_cast<std::size_t>(5), "" );
    t[0] = "salut";
    t[1] = "les";
    t[2] = "amis";
    t[3] = "comment";
    t[4] = "allez";

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << t[i] << std::endl;
    }
    return (0);
}