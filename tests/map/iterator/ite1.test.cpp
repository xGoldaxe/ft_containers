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

	std::map<std::string, int>::iterator it = bst.begin();

	bst.insert( std::make_pair("zzzz", 1) );
	bst.insert( std::make_pair("assa", 1) );
	bst.insert( std::make_pair("dwqdqwd", 1) );
	bst.insert( std::make_pair("qdqwdqdas", 1) );

	std::map<std::string, int>::iterator it2 = bst.begin();

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
    std::map<std::string, int> b;
	std::map<std::string, int>::iterator itb = b.begin();

	for (; itb != b.end(); ++itb) {

		//will never fire
		std::cout << (*itb).first << ":" << itb->second << std::endl;
	}


	std::cout << "<-----------{const ite}----------->" << std::endl;
	const std::map<std::string, int>::iterator bbit = bst.begin();
	std::map<std::string, int>::const_iterator bit = bbit;
	std::map<std::string, int>::const_iterator cbit = bit;
	std::map<std::string, int>::const_iterator abit;
	abit = cbit;
	std::cout << bit->first << ":" << bit->second << std::endl;
	std::cout << cbit->first << ":" << cbit->second << std::endl;
	std::cout << abit->first << ":" << abit->second << std::endl;


    std::cout << "<-----------{member types}----------->" << std::endl;
    std::cout << sizeof( std::map<std::string, int>::const_iterator::iterator_category ) << std::endl;
    std::cout << sizeof( std::map<std::string, int>::const_iterator::value_type ) << std::endl;
    std::cout << sizeof( std::map<std::string, int>::const_iterator::difference_type ) << std::endl;
    std::cout << sizeof( std::map<std::string, int>::const_iterator::pointer ) << std::endl;
    std::cout << sizeof( std::map<std::string, int>::const_iterator::reference ) << std::endl;

	std::cout << "<-----------{cbegin}----------->" << std::endl;
	const std::map<std::string, int>::const_iterator cbeg = bst.begin();
	std::cout << cbeg->first << ":" << cbeg->second << std::endl;


	// std::cout << "<-----------{impossible}----------->" << std::endl;
	// bit->second = 666;
	// (*abit).second = 666;

    return (0);
}