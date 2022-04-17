#include <iostream>
#include <vector>
#include <map>

int main( void ) {

	std::cout << std::boolalpha; 
    std::map<std::string, int> bst;

	std::cout << "<-----------{key comp}----------->" << std::endl;
	std::less<std::string> comp = bst.key_comp();
	std::cout << ( comp("salut", "les") ) << std::endl;
	std::cout << ( comp("les", "salut") ) << std::endl;

	std::cout << "<-----------{value comp}----------->" << std::endl;
	std::less<std::string> comp = bst.key_comp();
	std::cout << ( comp("salut", "les") ) << std::endl;
	std::cout << ( comp("les", "salut") ) << std::endl;

    return (0);
}