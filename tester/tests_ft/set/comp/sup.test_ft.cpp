#include "../ft.hpp"
#include <set>
#include <iostream>

int main( void ) {

	std::cout << std::boolalpha; 

	ft::set<std::string> b;
	b.insert( "-a" );
	b.insert( "-b" );
	b.insert( "-c" );
	b.insert( "-d" );
	b.insert( "-e" );

	ft::set<std::string> bcopy(b);


	ft::set<std::string> b2;
	b2.insert( "--a" );
	b2.insert( "--d" );
	b2.insert( "--e" );

    std::cout << "<-----------{self}----------->" << std::endl;
	std::cout << "== :" << (b == b) << std::endl;
	std::cout << "< :" << (b < b) << std::endl;
	std::cout << "<= :" << (b <= b) << std::endl;
    std::cout << ">= :"  << (b >= b) << std::endl;
	std::cout << ">:"  << (b > b) << std::endl;

    std::cout << "<-----------{same shape}----------->" << std::endl;
	std::cout << "== :"  << (b == bcopy) << std::endl;
	std::cout << "< :"  << (b < bcopy) << std::endl;
	std::cout << "<= :"  << (b <= bcopy) << std::endl;
	std::cout << ">= :"  << (b >= bcopy) << std::endl;
	std::cout << ">:"  << (b > bcopy) << std::endl;

    std::cout << "<-----------{different content, same size}----------->" << std::endl;



    std::cout << "<-----------{different size)}----------->" << std::endl;
	std::cout << "== :"  << (b == b2) << std::endl;
	std::cout << "< :"  << (b < b2) << std::endl;
	std::cout << "<= :"  << (b <= b2) << std::endl;
	std::cout << ">= :"  << (b >= b2) << std::endl;
    std::cout << "> :"  << (b > b2) << std::endl;

    std::cout << "<-----------{bcop size)}----------->" << std::endl;
    std::cout << "> :"  << (bcopy == b) << std::endl;

    std::cout << "<-----------{add size)}----------->" << std::endl;

	bcopy.insert( "zzzzzz" );
    std::cout << "< :"  << (b < bcopy) << std::endl;
	std::cout << "<= :"  << (b <= bcopy) << std::endl;
	std::cout << ">= :"  << (b >= bcopy) << std::endl;
	std::cout << ">:"  << (b > bcopy) << std::endl;


    return (0);
}