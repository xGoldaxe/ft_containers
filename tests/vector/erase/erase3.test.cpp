#include "../ft.hpp"
#include <vector>
#include <iostream>

template < class vector >
void    print_vector( vector v ) {

    for (typename vector::iterator it = v.begin(); it != v.end(); ++it ) {

        std::cout << "<>" <<*it << std::endl;
    }
}

class test {
    int *res;

    public:
        test() : res( new int[6] ) {};
        ~test() { delete[] res; };
};

int main( void ) {

    std::vector<int> r( 3, 2 );

    std::vector<std::vector<int> > t( static_cast<std::size_t>(8), r );

	    // //
    std::cout << "<-----------{erase in the middle}----------->" << std::endl;
    *t.erase( t.begin() + 1, t.begin() + 3 );
    std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;

    std::cout << "<-----------{begin = end}----------->" << std::endl;
    *t.erase( t.begin() + 1, t.begin() + 1 );
    std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;


	std::cout << "<-----------{erase first last}----------->" << std::endl;
    *t.erase( t.begin(), t.end() );
    std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;

    /*************************
    * @OTHER TEST ARE UNDEFINED
    * by this i mean they throw
    * errors or bad comportement
    * wich is not define is the
    * reference
    * ***********************/



	// std::cout << "<-----------{error case}----------->" << std::endl;

	// std::cout << "<-----------{invalid iterators}----------->" << std::endl;
    // std::cout << *t.erase( t.begin() + 3, t.begin() + 1 ) << std::endl;
    // std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;
    // print_vector<std::vector<std::string> >(t);

    
    // std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;
    // print_vector<std::vector<std::string> >(t);

	// std::cout << "<-----------{erase invalid}----------->" << std::endl;
    // std::vector<std::string> to( static_cast<std::size_t>(2), "dsda" );
	// try
	// {
	// 	std::cout << *t.erase( t.begin(), to.end() ) << std::endl;
	// 	std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;
	// 	print_vector<std::vector<std::string> >(t);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	


    return (0);
}
