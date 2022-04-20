#include <map>
#include <iostream>

int main( void ) {

	std::cout << std::boolalpha; 

	std::map<std::string, int> b;
	b.insert( std::make_pair("-a", 1) );
	b.insert( std::make_pair("-b", 2) );
	b.insert( std::make_pair("-c", 3) );
	b.insert( std::make_pair("-d", 4) );
	b.insert( std::make_pair("-e", 3) );

	std::map<std::string, int> bcopy(b);


	std::map<std::string, int> b2;
	b2.insert( std::make_pair("*a", 1) );
	b2.insert( std::make_pair("*d", 666) );
	b2.insert( std::make_pair("*e", 333) );

    std::cout << "<-----------{self}----------->" << std::endl;
	std::cout << "< :" << (b < b) << std::endl;
	std::cout << "<= :" << (b <= b) << std::endl;
    std::cout << ">= :"  << (b >= b) << std::endl;
	std::cout << ">:"  << (b > b) << std::endl;

    std::cout << "<-----------{same shape}----------->" << std::endl;
	std::cout << "< :"  << (b < bcopy) << std::endl;
	std::cout << "<= :"  << (b <= bcopy) << std::endl;
	std::cout << ">= :"  << (b >= bcopy) << std::endl;
	std::cout << ">:"  << (b > bcopy) << std::endl;

    std::cout << "<-----------{different content, same size}----------->" << std::endl;



    std::cout << "<-----------{different size)}----------->" << std::endl;
	std::cout << "< :"  << (b < b2) << std::endl;
	std::cout << "<= :"  << (b <= b2) << std::endl;
	std::cout << ">= :"  << (b >= b2) << std::endl;
    std::cout << "> :"  << (b > b2) << std::endl;

	
    std::cout << "> :"  << (bcopy == b) << std::endl;
	bcopy.insert( std::make_pair("zzzzzz", 3) );
    std::cout << "< :"  << (b < bcopy) << std::endl;
	std::cout << "<= :"  << (b <= bcopy) << std::endl;
	std::cout << ">= :"  << (b >= bcopy) << std::endl;
	std::cout << ">:"  << (b > bcopy) << std::endl;


    return (0);
}