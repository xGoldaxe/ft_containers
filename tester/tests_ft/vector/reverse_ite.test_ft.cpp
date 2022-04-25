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

	ft::vector<std::string>::reverse_iterator it = t.rbegin();
	for (; it != t.rend(); it++ ) {
		
		std::cout << *it << std::endl;
	}

    std::cout << "<-----------{member types}----------->" << std::endl;
    std::cout << sizeof( ft::vector<std::string>::reverse_iterator::iterator_category ) << std::endl;
    std::cout << sizeof( ft::vector<std::string>::reverse_iterator::value_type ) << std::endl;
    std::cout << sizeof( ft::vector<std::string>::reverse_iterator::difference_type ) << std::endl;
    std::cout << sizeof( ft::vector<std::string>::reverse_iterator::pointer ) << std::endl;
    std::cout << sizeof( ft::vector<std::string>::reverse_iterator::reference ) << std::endl;

    return (0);
}