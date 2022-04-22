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

	ft::map<std::string, int>::iterator it = bst.begin();

	bst.insert( ft::make_pair("zzzz", 1) );
	bst.insert( ft::make_pair("assa", 1) );
	bst.insert( ft::make_pair("dwqdqwd", 1) );
	bst.insert( ft::make_pair("qdqwdqdas", 1) );

	ft::map<std::string, int>::iterator it2 = bst.begin();

	std::cout << "<-----{we dont care about comparaison since it point to a particular node in the same tree}----------->" << std::endl;
	std::cout << (it == it2) << std::endl;

	std::cout << "<-----------{normal case}----------->" << std::endl;
	it->second = 666;
    for (; it != bst.end(); ++it) {

		std::cout << (*it).first << ":" << it->second << std::endl;
	}
	std::cout << "<-----------{past end then backward case}----------->" << std::endl;
	it--;
	for (; it != bst.begin(); --it) {

		std::cout << (*it).first << ":" << it->second << std::endl;
	}
	--it;
	--it;
	std::cout << (*it).first << ":" << it->second << std::endl;
	--it;
	std::cout << (*it).first << ":" << it->second << std::endl;

    std::cout << "<-----------{emptry tree}----------->" << std::endl;
    ft::map<std::string, int> b;
	ft::map<std::string, int>::iterator itb = b.begin();

	for (; itb != b.end(); ++itb) {

		//will never fire
		std::cout << (*itb).first << ":" << itb->second << std::endl;
	}


	std::cout << "<-----------{const ite}----------->" << std::endl;
	const ft::map<std::string, int>::iterator bbit = bst.begin();
	ft::map<std::string, int>::const_iterator bit = bbit;
	ft::map<std::string, int>::const_iterator cbit = bit;
	ft::map<std::string, int>::const_iterator abit;
	abit = cbit;
	std::cout << bit->first << ":" << bit->second << std::endl;
	std::cout << cbit->first << ":" << cbit->second << std::endl;
	std::cout << abit->first << ":" << abit->second << std::endl;

	std::cout << "<-----------{cbegin}----------->" << std::endl;
	const ft::map<std::string, int>::const_iterator cbeg = bst.begin();
	std::cout << cbeg->first << ":" << cbeg->second << std::endl;


	// std::cout << "<-----------{impossible}----------->" << std::endl;
	// bit->second = 666;
	// (*abit).second = 666;

    return (0);
}