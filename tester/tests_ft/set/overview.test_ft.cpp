#include "../ft.hpp"
#include <iostream>
#include <vector>
#include <set>

int main( void ) {

    std::cout << "<-----------{member types}----------->" << std::endl;
    std::cout << sizeof( ft::set<std::string>::key_type ) << std::endl;
    std::cout << sizeof( ft::set<std::string>::value_type ) << std::endl;
    std::cout << sizeof( ft::set<std::string>::size_type ) << std::endl;
    std::cout << sizeof( ft::set<std::string>::difference_type ) << std::endl;
    std::cout << sizeof( ft::set<std::string>::key_compare ) << std::endl;
    std::cout << sizeof( ft::set<std::string>::value_compare ) << std::endl;
    std::cout << sizeof( ft::set<std::string>::allocator_type ) << std::endl;
    std::cout << sizeof( ft::set<std::string>::reference ) << std::endl;
    std::cout << sizeof( ft::set<std::string>::const_reference ) << std::endl;
    std::cout << sizeof( ft::set<std::string>::pointer ) << std::endl;
    std::cout << sizeof( ft::set<std::string>::const_pointer ) << std::endl;
	
    return (0);
}