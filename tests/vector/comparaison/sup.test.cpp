#include "../ft.hpp"
#include <vector>
#include <iostream>

int main( void ) {

    std::vector<std::string> t( static_cast<std::size_t>(5), "aa" );
    std::vector<std::string> to( static_cast<std::size_t>(5), "aa" );

    std::cout << "<-----------{self}----------->" << std::endl;
	std::cout << "< :" << (t < t) << std::endl;
	std::cout << "<= :" << (t <= t) << std::endl;
    std::cout << ">= :"  << (t >= t) << std::endl;
	std::cout << ">:"  << (t > t) << std::endl;

    std::cout << "<-----------{same shape}----------->" << std::endl;
	std::cout << "< :"  << (t < to) << std::endl;
	std::cout << "<= :"  << (t <= to) << std::endl;
	std::cout << ">= :"  << (t >= to) << std::endl;
	std::cout << ">:"  << (t > to) << std::endl;

    std::cout << "<-----------{different content}----------->" << std::endl;
    to[0] = "bb";
    std::cout << "< :"  << (t < to) << std::endl;
    std::cout << "> :"  << (t > to) << std::endl;

    std::cout << "<-----------{different size}----------->" << std::endl;
    to = t;
    to.resize(6, "");
    std::cout << "< :"  << (t < to) << std::endl;
    std::cout << "> :"  << (t > to) << std::endl;

    std::cout << "<-----------{WITH INT}----------->" << std::endl;

    std::vector<int> tint( static_cast<std::size_t>(5), 10 );
    std::vector<int> toint( static_cast<std::size_t>(5), 10 );

    std::cout << "<-----------{self}----------->" << std::endl;
	std::cout << "< :" << (tint< tint) << std::endl;
	std::cout << "<= :" << (tint<= tint) << std::endl;
    std::cout << ">= :"  << (tint>= toint) << std::endl;
	std::cout << ">:"  << (tint> toint) << std::endl;

    std::cout << "<-----------{same shape}----------->" << std::endl;
	std::cout << "< :"  << (tint< toint) << std::endl;
	std::cout << "<= :"  << (tint<= toint) << std::endl;
	std::cout << ">= :"  << (tint>= toint) << std::endl;
	std::cout << ">:"  << (tint > toint) << std::endl;

    std::cout << "<-----------{different content}----------->" << std::endl;
    toint[0] = 5;
    std::cout << "< :"  << (tint < toint) << std::endl;
    std::cout << "> :"  << (tint > toint) << std::endl;

    std::cout << "<-----------{different size}----------->" << std::endl;
    toint = tint;
    toint.resize(6, -99);
    std::cout << "< :"  << (tint < toint) << std::endl;
    std::cout << "> :"  << (tint > toint) << std::endl;

    return (0);
}