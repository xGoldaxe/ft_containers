#include <iostream>
#include <vector>
#include <map>

int main( void ) {

    typedef std::pair<std::string, int> pair_type;
	std::cout << std::boolalpha; 

    std::map<std::string, int> bst;

	std::cout << bst.size() << std::endl;

    pair_type pair = std::make_pair("aa", 1);
	bst.insert(pair);
	pair = std::make_pair("bb", 2);
	bst.insert(pair);
	pair = std::make_pair("cc", 3);
	bst.insert(pair);

	pair = std::make_pair("qewqe", 5);
	bst.insert(pair);
	pair = std::make_pair("bb", 3);
	
	std::cout << "<-----------{already exist case}----------->" << std::endl;
	std::map<std::string, int>::iterator it = bst.begin();
	++it;
	++it;
	++it;
	std::map<std::string, int>::iterator iter = bst.insert(it, pair);
	std::cout << "size: " << bst.size() << std::endl;
	for (; iter != bst.end(); ++iter) {
		std::cout << iter->first << ":" << iter->second << std::endl;
	}

	std::cout << "<-----------{normal case}----------->" << std::endl;
	pair = std::make_pair("salut", 3);
	iter = bst.insert(it, pair);
	std::cout << "size: " << bst.size() << std::endl;
	for (; iter != bst.end(); ++iter) {
		std::cout << iter->first << ":" << iter->second << std::endl;
	}

	std::cout << "<-----------{out iterator case}----------->" << std::endl;
	it = bst.end();
	pair = std::make_pair("...", 666);
	iter = bst.insert(it, pair);
	std::cout << "size: " << bst.size() << std::endl;
	for (; iter != bst.end(); ++iter) {
		std::cout << iter->first << ":" << iter->second << std::endl;
	}

    return (0);
}