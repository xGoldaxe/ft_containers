#include "../ft.hpp"
#include <iostream>
#include <vector>
#include <map>

int main( void ) {

	std::cout << std::boolalpha; 
    ft::map<std::string, int> bst;

	std::less<std::string> comp = bst.key_comp();
	std::cout << ( comp("salut", "les") ) << std::endl;
	std::cout << ( comp("les", "salut") ) << std::endl;

    return (0);
}