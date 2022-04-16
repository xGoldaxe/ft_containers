#include <iostream>
#include <vector>
#include <map>

int main( void ) {

    typedef std::pair<std::string, int> pair_type;

    std::map<std::string, int> bst;

    pair_type pair = std::make_pair("aa", 1);
	bst.insert(pair);
	pair = std::make_pair("bb", 2);
	bst.insert(pair);
	pair = std::make_pair("cc", 3);
	bst.insert(pair);
	pair = std::make_pair("dsd", 4);
	bst.insert(pair);
	pair = std::make_pair("qewqe", 5);
	bst.insert(pair);
	pair = std::make_pair("dsada", 6);
	bst.insert(pair);

	std::reverse_iterator<std::map<std::string, int>::iterator> it = bst.rbegin();
	std::cout << "<-----------{normal case}----------->" << std::endl;
    for (; it != bst.rend(); ++it) {

		std::cout << (*it).first << ":" << it->second << std::endl;
	}

	std::cout << "<-----------{empty case}----------->" << std::endl;
    std::map<std::string, int> be;
	std::reverse_iterator<std::map<std::string, int>::iterator> rite = be.rbegin();
    for (; rite != be.rend(); ++rite) {

		std::cout << (*rite).first << ":" << rite->second << std::endl;
	}
    return (0);
}