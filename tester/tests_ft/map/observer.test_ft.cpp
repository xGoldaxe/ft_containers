#include "../ft.hpp"
#include <iostream>
#include <vector>
#include <map>

int main( void ) {

	std::cout << std::boolalpha; 
    ft::map<std::string, int> bst;

	std::cout << "<-----------{key comp}----------->" << std::endl;
	std::less<std::string> comp = bst.key_comp();
	std::cout << ( comp("salut", "les") ) << std::endl;
	std::cout << ( comp("les", "salut") ) << std::endl;

	std::cout << "<-----------{value comp}----------->" << std::endl;
	ft::map<std::string, int>::value_compare comp_func = bst.value_comp();

	std::pair<std::string, int> val = std::make_pair("salut", 2);
	std::pair<std::string, int> it = std::make_pair("bonjour", 4);
	bool before = comp_func(it, val);
	bool after = comp_func(val, it);
	std::cout << before << std::endl;
	std::cout << after << std::endl;
    return (0);
}