#include "../ft.hpp"
#include <vector>
#include <iostream>

template < class vector >
void    print_vector( vector v ) {

    for (typename vector::iterator it = v.begin(); it != v.end(); ++it ) {

        std::cout << "<>" <<*it << std::endl;
    }
}

template < class vector >
void    print_mem( vector v ) {

    std::cout << "MEM_USAGE: " << v.size() << "/" << v.capacity() << std::endl;
}

int main( void ) {

    ft::vector<std::string> t( static_cast<std::size_t>(5), "yo" );
    t[0] = "salut";
    t[1] = "les";
    t[2] = "amis";
    t[3] = "comment";
    t[4] = "allez";


	t.resize(8, "--value");
	std::cout << "MEM_USAGE: " << t.size() << "/" << t.capacity() << std::endl;


	t.resize(11, "--value");
	std::cout << "MEM_USAGE: " << t.size() << "/" << t.capacity() << std::endl;

	t.resize(30, "--value");
	std::cout << "MEM_USAGE: " << t.size() << "/" << t.capacity() << std::endl;
	print_vector(t);

	t.resize(2, "--value");
	std::cout << "MEM_USAGE: " << t.size() << "/" << t.capacity() << std::endl;
	print_vector(t);

    t.resize(2, "--value");
	std::cout << "MEM_USAGE: " << t.size() << "/" << t.capacity() << std::endl;

    std::cout << "<-----------{with int}----------->" << std::endl;

    ft::vector<int> to( static_cast<std::size_t>(2), 666 );
	to.resize(4, 333);
	std::cout << "MEM_USAGE: " << to.size() << "/" << to.capacity() << std::endl;
	print_vector(to);

    std::cout << "<-----------{exception}----------->" << std::endl;
    try
    {
        t.resize(-1, "nop");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << "MEM_USAGE: " << t.size() << "/" << t.capacity() << std::endl;
    return (0);
}