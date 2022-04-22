#include "../ft.hpp"
#include <vector>
#include <iostream>
#include <iomanip>


int main()
{
    std::cout << std::boolalpha;
 
	std::cout << "<-----------{default constructor}----------->" << std::endl;
	ft::pair<int, std::string> p;
	std::cout << (p.first == int() ) << ":" << (p.second == std::string() ) << std::endl;

	std::cout << "<-----------{arg constructor}----------->" << std::endl;
	ft::pair<int, std::string> p2( 56, "salut" );
	std::cout << (p2.first == 56 ) << ":" << (p2.second == "salut") << std::endl;

	std::cout << "<-----------{pair constructor}----------->" << std::endl;
	ft::pair<int, std::string> p3( p2 );
	std::cout << (p3.first == p2.first ) << ":" << (p3.second == p2.second) << std::endl;

	std::cout << "<-----------{= operator}----------->" << std::endl;
	p = p2;
	std::cout << (p.first == p2.first ) << ":" << (p.second == p2.second) << std::endl;

	std::cout << "<-----------{make_pair}----------->" << std::endl;
	ft::pair<int, std::string> pp = ft::make_pair<int, std::string>(666, "yo");
	std::cout << (pp.first == 666) << ":" << (pp.second == "yo") << std::endl;
}