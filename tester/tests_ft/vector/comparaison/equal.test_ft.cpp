#include "../ft.hpp"
#include <vector>
#include <iostream>

int main( void ) {

    ft::vector<std::string> t( static_cast<std::size_t>(5), "" );
    ft::vector<std::string> to( static_cast<std::size_t>(5), "" );

    std::cout << "<-----------{self}----------->" << std::endl;
	std::cout << (t == t) << std::endl;
    std::cout << "<-----------{same shape}----------->" << std::endl;
	std::cout << (t == to) << std::endl;
    std::cout << "<-----------{different storage}----------->" << std::endl;
    to.reserve(10);
    std::cout << (t == to) << std::endl;
    std::cout << "<-----------{different size}----------->" << std::endl;
    to.push_back("");
    std::cout << (t == to) << std::endl;

    std::cout << "<-----------{NOT EQUAL}----------->" << std::endl;

    ft::vector<std::string> t2( static_cast<std::size_t>(5), "" );
    ft::vector<std::string> to2( static_cast<std::size_t>(5), "" );

    std::cout << "<-----------{self}----------->" << std::endl;
	std::cout << (t2 != t2) << std::endl;
    std::cout << "<-----------{same shape}----------->" << std::endl;
	std::cout << (t2 != to2) << std::endl;
    std::cout << "<-----------{different storage}----------->" << std::endl;
    to2.reserve(10);
    std::cout << (t2 != to2) << std::endl;
    std::cout << "<-----------{different size}----------->" << std::endl;
    to2.push_back("");
    std::cout << (t2 != to2) << std::endl;

    return (0);
}