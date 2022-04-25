#include "../ft.hpp"
#include <iostream>
#include <vector>
#include <set>

int main( void ) {

    ft::set<std::string> bst;

	bst.insert("aa");
	bst.insert("bb");
	bst.insert("cc");
	bst.insert("dsd");
	bst.insert("qewqe");
	bst.insert("dsada");

	ft::set<std::string>::iterator it = bst.begin();

	bst.insert( "zzzz" );
	bst.insert( "assa" );
	bst.insert( "dwqdqwd" );
	bst.insert( "qdqwdqdas" );

	ft::set<std::string>::iterator it2 = bst.begin();

	std::cout << "<-----{we dont care about comparaison since it point to a particular node in the same tree}----------->" << std::endl;
	std::cout << (it == it2) << std::endl;

	std::cout << "<-----------{normal case}----------->" << std::endl;
    for (; it != bst.end(); ++it) {

		std::cout << *it << std::endl;
	}
	std::cout << "<-----------{past end then backward case}----------->" << std::endl;
	it--;
	for (; it != bst.begin(); --it) {

		std::cout << *it << std::endl;
	}
	--it;
	--it;
	std::cout << *it << std::endl;
	--it;
	std::cout << *it << std::endl;

    std::cout << "<-----------{emptry tree}----------->" << std::endl;
    ft::set<std::string> b;
	ft::set<std::string>::iterator itb = b.begin();

	for (; itb != b.end(); ++itb) {

		//will never fire
		std::cout << *itb << std::endl;
	}


	std::cout << "<-----------{const ite}----------->" << std::endl;
	const ft::set<std::string>::iterator bbit = bst.begin();
	ft::set<std::string>::const_iterator bit = bbit;
	ft::set<std::string>::const_iterator cbit = bit;
	ft::set<std::string>::const_iterator abit;
	abit = cbit;
	std::cout << *bit << std::endl;
	std::cout << *cbit << std::endl;
	std::cout << *abit << std::endl;


    std::cout << "<-----------{member types}----------->" << std::endl;
    std::cout << sizeof( ft::set<std::string>::const_iterator::iterator_category ) << std::endl;
    std::cout << sizeof( ft::set<std::string>::const_iterator::value_type ) << std::endl;
    std::cout << sizeof( ft::set<std::string>::const_iterator::difference_type ) << std::endl;
    std::cout << sizeof( ft::set<std::string>::const_iterator::pointer ) << std::endl;
    std::cout << sizeof( ft::set<std::string>::const_iterator::reference ) << std::endl;

	std::cout << "<-----------{cbegin}----------->" << std::endl;
	const ft::set<std::string>::const_iterator cbeg = bst.begin();
	std::cout << *cbeg << std::endl;


	// std::cout << "<-----------{impossible}----------->" << std::endl;
	// bit->second = 666;
	// (*abit).second = 666;

    return (0);
}