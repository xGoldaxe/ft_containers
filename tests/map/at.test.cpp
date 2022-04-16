#include <iostream>
#include "../ft.hpp"
#include <vector>
#include <map>

int main( void ) {

    typedef std::pair<int, std::string> pair_type;

    std::map<int, std::string> bst;

    pair_type pair = std::make_pair(9, "salut");
	bst.insert(pair);
	pair = std::make_pair(2, "les");
	bst.insert(pair);
	pair = std::make_pair(4, "amis");
	bst.insert(pair);
	pair = std::make_pair(12, "comment");
	bst.insert(pair);
	pair = std::make_pair(14, "allez");
	bst.insert(pair);
	pair = std::make_pair(7, "vous");
	bst.insert(pair);

	bst.at(2) = "blabla";
    std::cout << bst.at(2) << std::endl;
    std::cout << bst.at(9) << std::endl;
    std::cout << bst.at(12) << std::endl;

	try
	{
		std::cout << bst.at(19) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	


    return (0);
}