#include "../ft.hpp"
#include <iostream>
#include <vector>
#include <map>

int main( void ) {

    typedef std::pair<std::string, int> pair_type;
	std::cout << std::boolalpha; 

    ft::map<std::string, int> bst;

	std::cout << bst.size() << std::endl;

    pair_type pair = std::make_pair("aa", 1);
	bst.insert(pair);
	pair = std::make_pair("bb", 2);
	bst.insert(pair);
	pair = std::make_pair("cc", 3);
	bst.insert(pair);

	pair = std::make_pair("qewqe", 5);
	bst.insert(pair);
	pair = std::make_pair("dsada", 6);
	bst.insert(pair);

	std::cout << bst.size() << std::endl;
	bst.clear();
	std::cout << bst.size() << std::endl;
	std::cout << "lets iterate" << std::endl;
	for (ft::map<std::string, int>::iterator it = bst.begin(); it != bst.end(); ++it) {

		std::cout << it->first << ":" << it->second;
	}
	pair = std::make_pair("dsd", 4);
	bst.insert(pair);
	pair = std::make_pair("qewqe", 5);
	bst.insert(pair);
	pair = std::make_pair("dsada", 6);
	bst.insert(pair);
	for (ft::map<std::string, int>::iterator it = bst.begin(); it != bst.end(); ++it) {

		std::cout << it->first << ":" << it->second << std::endl;
	}
	
    return (0);
}