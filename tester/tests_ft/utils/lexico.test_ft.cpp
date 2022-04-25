#include "../ft.hpp"
// E_ARGS --COMPILFLAG=-std=c++98
#include <vector>
#include <iostream>
#include <iomanip>
 
int main()
{
    std::cout << std::boolalpha;

    std::vector<std::string> v(6, "salut");
    std::vector<std::string> v1(6, "salut");
    std::cout << ft::lexicographical_compare(v.begin(), v.end(), v1.begin(), v1.end()) << std::endl;
    std::cout << ft::lexicographical_compare(v.begin(), v.end(), v1.begin(), v1.end(), std::greater<std::string>() ) << std::endl;

    v.pop_back();
    std::cout << ft::lexicographical_compare(v.begin(), v.end(), v1.begin(), v1.end()) << std::endl;
    std::cout << ft::lexicographical_compare(v.begin(), v.end(), v1.begin(), v1.end(), std::greater<std::string>() ) << std::endl;

    v1[0] = "aa";
    std::cout << ft::lexicographical_compare(v.begin(), v.end(), v1.begin(), v1.end()) << std::endl;
    std::cout << ft::lexicographical_compare(v.begin(), v.end(), v1.begin(), v1.end(), std::greater<std::string>() ) << std::endl;

    std::vector<std::string> v2(7, "salut");
    std::vector<std::string> v3(6, "salut");
    std::cout << ft::lexicographical_compare(v2.begin(), v2.end(), v3.begin(), v3.end()) << std::endl;
    std::cout << ft::lexicographical_compare(v2.begin(), v2.end(), v3.begin(), v3.end(), std::greater<std::string>() );
}