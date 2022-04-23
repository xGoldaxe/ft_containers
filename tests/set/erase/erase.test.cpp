#include <iostream>
#include <vector>
#include <set>

int main( void ) {

	std::cout << std::boolalpha; 

	std::set<std::string> b;
	b.insert( "-a" );
	b.insert( "-b" );
	b.insert( "-c" );
	b.insert( "-d" );
	b.insert( "-e" );
	
	std::cout << "<-----------{exist case}----------->" << std::endl;
	// std::map<std::string, int>::iterator itb = b.begin();

	b.erase( b.begin() );
	b.erase( b.begin() );

	std::set<std::string>::iterator it = b.begin();
	std::cout << "size: " << b.size() << std::endl;
	for (; it != b.end(); ++it) {
		std::cout << *it << std::endl;
	}

	//double free 
	// std::cout << "<-----------{doesnt exist case}----------->" << std::endl;
	// b.erase( itb );
	// it = b.begin();
	// std::cout << "size: " << b.size() << std::endl;
	// for (; it != b.end(); ++it) {
	// 	std::cout << it->first << ":" << it->second << std::endl;
	// }

    return (0);
}