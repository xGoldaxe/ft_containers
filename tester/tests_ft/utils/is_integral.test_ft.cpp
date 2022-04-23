#include "../ft.hpp"
// E_ARGS --COMPILFLAG=-std=c++11
#include <vector>
#include <iostream>
#include <iomanip>
#include <type_traits>

#define SHOW(...) std::cout << __VA_ARGS__ << '\n'
 
class A {};

int main()
{
    std::cout << std::boolalpha;
 
	std::cout << "<-----------{false}----------->" << std::endl;
    SHOW( ft::is_integral<A>::value );
    SHOW( ft::is_integral<float>::value );
    std::cout << "<-----------{true}----------->" << std::endl;
    SHOW( ft::is_integral<int>::value );
    SHOW( ft::is_integral<const int>::value );
    SHOW( ft::is_integral<const bool>::value );
}