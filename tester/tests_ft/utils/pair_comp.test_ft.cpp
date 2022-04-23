#include "../ft.hpp"
#include <vector>
#include <iostream>
#include <iomanip>


int main()
{
    std::cout << std::boolalpha;
 
	ft::pair<int, std::string> p0( 56, "salut" );
	ft::pair<int, std::string> p1( 55, "salut" );
	ft::pair<int, std::string> p2( 56, "asalut" );
	ft::pair<int, std::string> p3( 56, "zsalut" );

	std::cout << "<-----------{==}----------->" << std::endl;
	std::cout << (p0 == p0) << std::endl;
	std::cout << (p0 == p1) << std::endl;
	std::cout << (p0 == p2) << std::endl;
	std::cout << (p0 == p3) << std::endl;

	std::cout << "<-----------{!=}----------->" << std::endl;
	std::cout << (p0 != p0) << std::endl;
	std::cout << (p0 != p1) << std::endl;
	std::cout << (p0 != p2) << std::endl;
	std::cout << (p0 != p3) << std::endl;
	
	std::cout << "<-----------{>}----------->" << std::endl;
	std::cout << (p0 > p0) << std::endl;
	std::cout << (p0 > p1) << std::endl;
	std::cout << (p0 > p2) << std::endl;
	std::cout << (p0 > p3) << std::endl;

	std::cout << "<-----------{<}----------->" << std::endl;
	std::cout << (p0 < p0) << std::endl;
	std::cout << (p0 < p1) << std::endl;
	std::cout << (p0 < p2) << std::endl;
	std::cout << (p0 < p3) << std::endl;

	std::cout << "<-----------{<=}----------->" << std::endl;
	std::cout << (p0 <= p0) << std::endl;
	std::cout << (p0 <= p1) << std::endl;
	std::cout << (p0 <= p2) << std::endl;
	std::cout << (p0 <= p3) << std::endl;

	std::cout << "<-----------{>=}----------->" << std::endl;
	std::cout << (p0 >= p0) << std::endl;
	std::cout << (p0 >= p1) << std::endl;
	std::cout << (p0 >= p2) << std::endl;
	std::cout << (p0 >= p3) << std::endl;
}