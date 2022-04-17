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

	std::map<std::string, int> b;
	bst.insert( std::make_pair("-a", 1) );
	bst.insert( std::make_pair("-b", 2) );
	bst.insert( std::make_pair("-c", 3) );
	bst.insert( std::make_pair("-d", 4) );
	bst.insert( std::make_pair("bb", 3) );
	
	std::cout << "<-----------{already exist case}----------->" << std::endl;
	bst.insert(b.begin(), b.end());
	std::map<std::string, int>::iterator it = bst.begin();
	std::cout << "size: " << bst.size() << std::endl;
	for (; it != bst.end(); ++it) {
		std::cout << it->first << ":" << it->second << std::endl;
	}

    return (0);
}