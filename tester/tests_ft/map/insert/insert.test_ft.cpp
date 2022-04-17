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
	pair = std::make_pair("LAST INSERTED", 6);
	
	std::pair<ft::map<std::string, int>::iterator, bool> iteros = bst.insert(pair);
	std::cout << "Is inserted: " << iteros.second << std::endl; 
	ft::map<std::string, int>::iterator iter = iteros.first;
	for (; iter != bst.end(); ++iter) {
		std::cout << iter->first << ":" << iter->second << std::endl;
	}

	std::cout << bst.size() << std::endl;
	for (ft::map<std::string, int>::iterator it = bst.begin(); it != bst.end(); ++it) {
		std::cout << it->first << ":" << it->second << std::endl;
	}

	std::cout << "<-----------{error case}----------->" << std::endl;
	pair = std::make_pair("LAST INSERTED", 8);
	iteros = bst.insert(pair);
	std::cout << "Is inserted: " << iteros.second << std::endl; 
	std::cout << "Value: " << bst.at("LAST INSERTED") << std::endl; 
	std::cout << "size: " << bst.size() << std::endl;

	iter = iteros.first;
	for (; iter != bst.end(); ++iter) {
		std::cout << iter->first << ":" << iter->second << std::endl;
	}
    return (0);
}