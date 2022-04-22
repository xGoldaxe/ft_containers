#include "../ft.hpp"
#include <iostream>
#include <vector>
#include <map>

int main( void ) {

    typedef ft::pair<std::string, int> pair_type;

    ft::map<std::string, int> bst;

	std::cout << bst.size() << std::endl;

    pair_type pair = ft::make_pair("aa", 1);
	bst.insert(pair);

	std::cout << bst.size() << std::endl;

	pair = ft::make_pair("bb", 2);
	bst.insert(pair);
	pair = ft::make_pair("cc", 3);
	bst.insert(pair);
	pair = ft::make_pair("dsd", 4);
	bst.insert(pair);
	pair = ft::make_pair("qewqe", 5);
	bst.insert(pair);
	pair = ft::make_pair("dsada", 6);
	bst.insert(pair);

	std::cout << bst.size() << std::endl;
	
    return (0);
}