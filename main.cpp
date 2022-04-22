/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:55:49 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/22 17:45:18 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ft.hpp"
#include <vector>
#include <map>
#include <stack>

int main( void ) {

	std::stack<int, std::vector<int> > ss;
	std::stack<int> s;

	std::cout << sizeof( std::stack<int, std::vector<int> >::container_type )
		<< ":" << sizeof( std::stack<int>::container_type ) << std::endl;

	s.push(666);
	s.push(333);
	s.push(999);
	s.push(111);
	s.push(0);
	s.push(666);

	for (std::stack<std::vector<int> >::size_type i = 0; i < 6; ++i) {

		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::vector<int> si(6, 666);
	std::stack<int, std::vector<int> > so( si );
	for (std::stack<std::vector<int> >::size_type i = 0; i < 6; ++i) {

		std::cout << so.top() << std::endl;
		so.pop();
	}
	
    return (0);
}