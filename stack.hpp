/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:22:52 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/23 12:06:49 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#	define STACK_HPP

#include "ft.hpp"

template< class T, class Container = ft::vector<T> >
class ft::stack {
	
	protected:
		Container c;

	public:
		/*************************
		* @member types
		* ***********************/
		typedef Container								container_type;
		typedef typename Container::value_type			value_type;
		typedef typename Container::size_type			size_type;
		typedef typename Container::reference			reference;
		typedef typename Container::const_reference		const_reference;

		/*************************
		* @constructor
		* ***********************/
		explicit stack( const Container& cont = Container() ) : c( cont ) {};
		stack( const stack& other ) : c( other.c ) {};

		stack& operator=( const stack& other ) {

			c = other.c;
			return *this;
		}

		/*************************
		* @element access
		* ***********************/
		reference top() {
			return c.back();
		}

		const_reference top() const {
			return c.back();
		}

		/*************************
		* @capacity
		* ***********************/
		bool empty(void) const {
			return c.empty();
		}

		size_type size() const {
			return c.size();
		}
		
		/*************************
		* @modifiers
		* ***********************/
		void push( const value_type& value ) {
			c.push_back(value);
		}

		void pop(void) {
			c.pop_back();
		}

		/*************************
		* @comparaison
		* ***********************/
	private:
		template<typename T_o, typename Container_o>
		friend bool operator==(const stack<T_o, Container_o>&, const stack<T_o, Container_o>&);

		template<typename T_o, typename Container_o>
		friend bool operator<(const stack<T_o, Container_o>&, const stack<T_o, Container_o>&);
};

namespace ft
{
	template< class T, class Container >
	bool operator==( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {
		return (lhs.c == rhs.c);
	};

	template< class T, class Container >
	bool operator!=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {
		return !(lhs == rhs);
	}

	template< class T, class Container >
	bool operator<( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {
		return (lhs.c < rhs.c);
	}

	template< class T, class Container >
	bool operator<=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {
		return (lhs == rhs || lhs < rhs);
	}

	template< class T, class Container >
	bool operator>( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {
		return !(lhs <= rhs);
	}

	template< class T, class Container >
	bool operator>=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {
		return (lhs == rhs || lhs > rhs);
	}
}

#endif