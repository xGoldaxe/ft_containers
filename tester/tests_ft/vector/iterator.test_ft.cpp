#include "../ft.hpp"
#include "../ft.hpp"
#include <vector>
#include <iostream>

int main( void ) {

    ft::vector<std::string> t( static_cast<std::size_t>(5), "yo" );
    t[0] = "salut";
    t[1] = "les";
    t[2] = "amis";
    t[3] = "comment";
    t[4] = "allez";

	ft::vector<std::string>::iterator it = t.begin();
    *it = "modif";
	for (; it != t.end(); it++ ) {
		
		std::cout << *it << std::endl;
	}
	std::cout << (it + 5 == t.end() + 5) << std::endl;


    ft::vector<std::string>::const_iterator cit = t.begin();
    for (; cit != t.end(); cit++ ) {
		
		std::cout << *cit << std::endl;
	}

    std::cout << "<-----------{member types}----------->" << std::endl;
    std::cout << sizeof( ft::vector<std::string>::const_iterator::iterator_category ) << std::endl;
    std::cout << sizeof( ft::vector<std::string>::const_iterator::value_type ) << std::endl;
    std::cout << sizeof( ft::vector<std::string>::const_iterator::difference_type ) << std::endl;
    std::cout << sizeof( ft::vector<std::string>::const_iterator::pointer ) << std::endl;
    std::cout << sizeof( ft::vector<std::string>::const_iterator::reference ) << std::endl;

    return (0);
}