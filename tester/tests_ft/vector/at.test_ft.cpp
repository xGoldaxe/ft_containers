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

    std::cout << t.at(0) << std::endl;
    std::cout << t.at(1) << std::endl;
    std::cout << t.at(2) << std::endl;
    std::cout << t.at(3) << std::endl;
    std::cout << t.at(4) << std::endl;

    return (0);
}