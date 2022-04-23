#include "../ft.hpp"
#include <stack>
#include <list>
#include <iostream>

int main() {
	std::cout << std::boolalpha;

	std::cout << "<-----------{member types}----------->" << std::endl;
	std::cout << sizeof( ft::stack<int, std::list<int> >::container_type ) << std::endl;
	std::cout << sizeof( ft::stack<int, std::list<int> >::value_type ) << std::endl;
	std::cout << sizeof( ft::stack<int, std::list<int> >::size_type ) << std::endl;
	std::cout << sizeof( ft::stack<int, std::list<int> >::reference ) << std::endl;
	std::cout << sizeof( ft::stack<int, std::list<int> >::const_reference ) << std::endl;

	std::cout << "<-----------{constructors}----------->" << std::endl;
	const std::list<std::string> t(5, "yo");
	ft::stack< std::string, std::list<std::string> > s( t );
	std::cout << s.top() << " " << s.size() << " " << s.empty() << std::endl;

	ft::stack< std::string, std::list<std::string> > c( s );
	std::cout << c.top() << " " << c.size() << " " << c.empty() << std::endl;

	ft::stack< std::string, std::list<std::string> > op;
	std::cout << op.empty() << std::endl;
	op = s;
	std::cout << op.top() << " " << op.size() << " " << op.empty() << std::endl;

	std::cout << "<-----------{modifiers}----------->" << std::endl;
	ft::stack< std::string, std::list<std::string> > m;
	m.push("hey");
	m.push("ho");
	m.push("lol");
	while ( !m.empty() )
	{
		std::cout << m.top() << " " << m.size() << std::endl;
		m.pop();
	}
	
	std::cout << "<-----------{comparaison}----------->" << std::endl;
	std::cout << "<-----------{self}----------->" << std::endl;
	std::cout << (op == op) << std::endl;
	std::cout << (op != op) << std::endl;
	std::cout << (op > op) << std::endl;
	std::cout << (op < op) << std::endl;
	std::cout << (op <= op) << std::endl;
	std::cout << (op >= op) << std::endl;

	std::cout << "<-----------{same shape}----------->" << std::endl;
	std::cout << (op == s) << std::endl;
	std::cout << (op != s) << std::endl;
	std::cout << (op > s) << std::endl;
	std::cout << (op < s) << std::endl;
	std::cout << (op <= s) << std::endl;
	std::cout << (op >= s) << std::endl;

	std::cout << "<-----------{different shape}----------->" << std::endl;
	std::cout << (op == m) << std::endl;
	std::cout << (op != m) << std::endl;
	std::cout << (op > m) << std::endl;
	std::cout << (op < m) << std::endl;
	std::cout << (op <= m) << std::endl;
	std::cout << (op >= m) << std::endl;
}