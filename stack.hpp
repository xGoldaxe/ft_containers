/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:22:52 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/22 17:44:04 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#	define STACK_HPP

#include "ft.hpp"

template< class T, class Container = ft::vector<T> >
class ft::stack {

	public:
		typedef Container								container_type;
		typedef typename Container::value_type			value_type;
		typedef typename Container::size_type			size_type;
		typedef typename Container::reference			reference;
		typedef typename Container::const_reference		const_reference;

		explicit stack( const Container& cont = Container() );
		stack( const stack& other );
};

#endif