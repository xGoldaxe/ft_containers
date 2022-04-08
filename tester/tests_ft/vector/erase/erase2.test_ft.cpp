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

    ft::vector<std::string> t( static_cast<std::size_t>(8), "" );
    t[0] = "salut";
    t[1] = "les";
    t[2] = "amis";
    t[3] = "comment";
    t[4] = "allez";
    t[5] = "je";
    t[6] = "suis";
    t[7] = "pleveque";

	    // //
    std::cout << "<-----------{erase in the middle}----------->" << std::endl;
    std::cout << *t.erase( t.begin() + 1, t.begin() + 3 ) << std::endl;
    std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;
    print_vector<ft::vector<std::string> >(t);

    std::cout << "<-----------{begin = end}----------->" << std::endl;
    std::cout << *t.erase( t.begin() + 1, t.begin() + 1 ) << std::endl;
    std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;
    print_vector<ft::vector<std::string> >(t);


	std::cout << "<-----------{erase first last}----------->" << std::endl;
    std::cout << *t.erase( t.begin(), t.end() ) << std::endl;
    std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;
    print_vector<ft::vector<std::string> >(t);

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
    // print_vector<ft::vector<std::string> >(t);

    
    // std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;
    // print_vector<ft::vector<std::string> >(t);

	// std::cout << "<-----------{erase invalid}----------->" << std::endl;
    // ft::vector<std::string> to( static_cast<std::size_t>(2), "dsda" );
	// try
	// {
	// 	std::cout << *t.erase( t.begin(), to.end() ) << std::endl;
	// 	std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;
	// 	print_vector<ft::vector<std::string> >(t);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	


    return (0);
}
