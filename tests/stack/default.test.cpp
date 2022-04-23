#include <stack>
#include <vector>
#include <iostream>

int main() {
	std::cout << std::boolalpha;

	std::cout << "<-----------{member types}----------->" << std::endl;
	std::cout << sizeof( std::stack<int>::value_type ) << std::endl;
	std::cout << sizeof( std::stack<int>::size_type ) << std::endl;
	std::cout << sizeof( std::stack<int>::reference ) << std::endl;
	std::cout << sizeof( std::stack<int>::const_reference ) << std::endl;

	std::cout << "<-----------{constructors}----------->" << std::endl;
	std::stack< std::string> s;
	s.push("first");
	std::cout << s.top() << " " << s.size() << " " << s.empty() << std::endl;

	std::stack< std::string> c( s );
	std::cout << c.top() << " " << c.size() << " " << c.empty() << std::endl;

	std::stack< std::string> op;
	std::cout << op.empty() << std::endl;
	op = s;
	std::cout << op.top() << " " << op.size() << " " << op.empty() << std::endl;

	std::cout << "<-----------{modifiers}----------->" << std::endl;
	std::stack< std::string> m;
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