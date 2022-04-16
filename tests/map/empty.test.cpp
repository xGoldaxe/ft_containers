#include <iostream>
#include <vector>
#include <map>

int main( void ) {

    typedef std::pair<std::string, int> pair_type;
	std::cout << std::boolalpha; 

    std::map<std::string, int> bst;

	std::cout << bst.empty() << std::endl;

    pair_type pair = std::make_pair("aa", 1);
	bst.insert(pair);

	std::cout << bst.empty() << std::endl;

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

	std::cout << bst.empty() << std::endl;
	
    return (0);
}