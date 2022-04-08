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

    std::cout << t.front() << std::endl;

    ft::vector<int> at( static_cast<std::size_t>(1), 666 );

    std::cout << at.front() << std::endl;

    return (0);
}