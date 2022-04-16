#include <iostream>
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

	std::cout << "<-----------{normal usage}----------->" << std::endl;
	std::cout << bst[2] << std::endl;	
	std::cout << bst[4] << std::endl;	
	std::cout << bst[12] << std::endl;	

	std::cout << "<-----------{insert usage}----------->" << std::endl;
	std::cout << "\"" << bst[96] << "\"" << std::endl;
	bst[98] = "test";
	std::cout << "\"" << bst[98] << "\"" << std::endl;

	std::cout << "<-----------{modifictation}----------->" << std::endl;
	bst[2] = "yayayaya";
	std::cout << bst[2] << std::endl;

    return (0);
}