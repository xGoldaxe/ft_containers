#include "../ft.hpp"
#include <vector>
#include <iostream>
#include <iomanip>


int main()
{
    std::cout << std::boolalpha;

	std::cout << sizeof( ft::iterator_traits<std::vector<int>::iterator >::difference_type ) << std::endl;
	std::cout << sizeof( ft::iterator_traits<std::vector<int>::iterator >::value_type ) << std::endl;
	std::cout << sizeof( ft::iterator_traits<std::vector<int>::iterator >::pointer ) << std::endl;
	std::cout << sizeof( ft::iterator_traits<std::vector<int>::iterator >::reference ) << std::endl;
	std::cout << sizeof( ft::iterator_traits<std::vector<int>::iterator >::iterator_category ) << std::endl;

	std::cout << "<-----------{ptr spec}----------->" << std::endl;
	std::cout << sizeof( ft::iterator_traits<long *>::difference_type ) << std::endl;
	std::cout << sizeof( ft::iterator_traits<long *>::value_type ) << std::endl;
	std::cout << sizeof( ft::iterator_traits<long *>::pointer ) << std::endl;
	std::cout << sizeof( ft::iterator_traits<long *>::reference ) << std::endl;
	std::cout << sizeof( ft::iterator_traits<long *>::iterator_category ) << std::endl;
}