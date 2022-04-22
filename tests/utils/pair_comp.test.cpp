#include <vector>
#include <iostream>
#include <iomanip>


int main()
{
    std::cout << std::boolalpha;
 
	std::pair<int, std::string> p0( 56, "salut" );
	std::pair<int, std::string> p1( 55, "salut" );
	std::pair<int, std::string> p2( 56, "asalut" );
	std::pair<int, std::string> p3( 56, "zsalut" );

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