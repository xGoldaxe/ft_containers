#include "../ft.hpp"
#include <iostream>
#include <vector>
#include <map>

int main( void ) {

    typedef ft::pair<std::string, int> pair_type;

    ft::map<std::string, int> bst;

    pair_type pair = ft::make_pair("aa", 1);
	bst.insert(pair);
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

	ft::reverse_iterator<ft::map<std::string, int>::iterator> it = bst.rbegin();
	std::cout << "<-----------{normal case}----------->" << std::endl;
    for (; it != bst.rend(); ++it) {

		std::cout << (*it).first << ":" << it->second << std::endl;
	}

	std::cout << "<-----------{empty case}----------->" << std::endl;
    ft::map<std::string, int> be;
	ft::reverse_iterator<ft::map<std::string, int>::iterator> rite = be.rbegin();
    for (; rite != be.rend(); ++rite) {

		std::cout << (*rite).first << ":" << rite->second << std::endl;
	}

	std::cout << "<-----------{const ite}----------->" << std::endl;
	ft::map<std::string, int>::const_iterator r = bst.end();
	ft::reverse_iterator<ft::map<std::string, int>::const_iterator> rr(r);
	std::cout << rr->first << ":" << rr->second << std::endl;
	
    return (0);
}