#include "../ft.hpp"
#include <iostream>
#include <vector>
#include <map>

int main( void ) {

    typedef ft::pair<std::string, int> pair_type;
	std::cout << std::boolalpha; 

    ft::map<std::string, int> bst;

	std::cout << bst.size() << std::endl;

    pair_type pair = ft::make_pair("aa", 1);
	bst.insert(pair);
	pair = ft::make_pair("bb", 2);
	bst.insert(pair);
	pair = ft::make_pair("cc", 3);
	bst.insert(pair);
	pair = ft::make_pair("qewqe", 5);
	bst.insert(pair);
	pair = ft::make_pair("bb", 3);

	ft::map<std::string, int> b;
	bst.insert( ft::make_pair("-a", 1) );
	bst.insert( ft::make_pair("-b", 2) );
	bst.insert( ft::make_pair("-c", 3) );
	bst.insert( ft::make_pair("-d", 4) );
	bst.insert( ft::make_pair("bb", 3) );
	
	std::cout << "<-----------{already exist case}----------->" << std::endl;
	bst.insert(b.begin(), b.end());
	ft::map<std::string, int>::iterator it = bst.begin();
	std::cout << "size: " << bst.size() << std::endl;
	for (; it != bst.end(); ++it) {
		std::cout << it->first << ":" << it->second << std::endl;
	}

    return (0);
}