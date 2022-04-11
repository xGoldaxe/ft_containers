/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorComparaison.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:27:48 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/11 12:59:55 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORCOMPARAISON_HPP
#	define VECTORCOMPARAISON_HPP


#include "ft.hpp"


namespace ft {

	/* ************************************************************************** */
	/*                                                                            */
	/*            @COMPARAISON                                                    */
	/*                                                                            */
	/* ************************************************************************** */

	template< class T, class Alloc >
		bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
		{
			return !(lexicographical_compare( 
						lhs.begin(), lhs.end(),
						rhs.begin(), rhs.end() 
					)) && 
					!(lexicographical_compare( 
						rhs.begin(), rhs.end(),
						lhs.begin(), lhs.end() 
					));
		}

	template< class T, class Alloc >
		bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
		{
			return ( !(lhs == rhs) );
		}

	/*************************
	* @> / >=
	* ***********************/

	template< class T, class Alloc >
		bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
		{
			return ( std::lexicographical_compare( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() ) );
		}

	template< class T, class Alloc >
		bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
		{
			return ( lhs < rhs || lhs == rhs );
		}

	/*************************
	* @< / <=
	* ***********************/

	template< class T, class Alloc >
		bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
		{
			return ( rhs < lhs );
		}

	template< class T, class Alloc >
		bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
		{
			return ( rhs <= lhs );
		}

	/*************************
	* @specialize std::swap
	* ***********************/
}

namespace std {
	template< class T, class Alloc >
		void swap ( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
		{
			lhs.swap(rhs);
		}
}



#endif