#include <iostream>
#include <vector>
#include <set>

int main( void ) {

	std::cout << std::boolalpha; 
    std::set<std::string> bst;

	std::cout << "<-----------{key comp}----------->" << std::endl;
	std::less<std::string> comp = bst.key_comp();
	std::cout << ( comp("salut", "les") ) << std::endl;
	std::cout << ( comp("les", "salut") ) << std::endl;

	std::cout << "<-----------{value comp}----------->" << std::endl;
	std::set<std::string>::value_compare comp_func = bst.value_comp();

	std::string val = "salut";
	std::string it = "bonjour";
	bool before = comp_func(it, val);
	bool after = comp_func(val, it);
	std::cout << before << std::endl;
	std::cout << after << std::endl;
    return (0);
}