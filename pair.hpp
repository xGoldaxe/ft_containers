/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:18:44 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/23 18:36:04 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#	define PAIR_HPP


namespace ft
{

	template< class T1, class T2 >
	struct pair {

		public:
			typedef T1		first_type;
			typedef T2		second_type;

			T1 first;
			T2 second;

			/*************************
			* @constructors
			* ***********************/
			pair() : first( T1() ), second( T2() ) {};

			pair( const T1& x, const T2& y ) : first( x ), second( y ) {};

			template< class U1, class U2 >
			pair( const pair<U1, U2>& p ) : first( p.first ), second( p.second ) {};

			/*************************
			* @copy
			* ***********************/
			pair& operator=( const pair& other ) {

				this->first = other.first;
				this->second = other.second;
				return (*this);
			};
	};

	template< class T1, class T2 >
	ft::pair<T1, T2> make_pair( T1 t, T2 u ) {

		return ft::pair<T1, T2>(t,u);
	};

	/*************************
	* @comparaison
	* ***********************/
	template< class T1, class T2 >
	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return ( lhs.first == rhs.first &&
				 lhs.second == rhs.second );
	}

	template< class T1, class T2 >
	bool operator!=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs )
	{
		return !( lhs == rhs );
	}

	template< class T1, class T2 >
	bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		if ( lhs.first < rhs.first )
			return true;
		else if ( lhs.first == rhs.first )
			return ( lhs.second < rhs.second );
		return false;
	}

	template< class T1, class T2 >
	bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return ( lhs < rhs || lhs == rhs );
	}

	template< class T1, class T2 >
	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return !(lhs <= rhs);
	}

	template< class T1, class T2 >
	bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return ( lhs > rhs || lhs == rhs );
	}
}

#endif