/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:30:41 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/23 20:12:43 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REVERSE_ITERATOR_HPP
#	define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{

	template <typename Iter>

	class reverse_iterator
	{
		protected:
			Iter	current;

		public:
			/* ************************************************************************** */
			/*                                                                            */
			/*            @MEMBER TYPES                                                   */
			/*                                                                            */
			/* ************************************************************************** */
			typedef reverse_iterator											iterator;
			typedef Iter														iterator_type;
			typedef reverse_iterator<Iter>										reverse_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category		iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type				value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type			difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer					pointer;
			typedef typename ft::iterator_traits<Iter>::reference				reference;
			
			/* ************************************************************************** */
			/*                                                                            */
			/*            @CONSTRUCTORS                                                   */
			/*                                                                            */
			/* ************************************************************************** */
			/*************************
			* @will just create an 
			* empty iterator that won't
			* be usable without assignation
			* ***********************/

			reverse_iterator(void) : current() {};

			explicit reverse_iterator( Iter x ) : current( x ) {};

			reverse_iterator( const reverse_iterator& other ) : current( other.base() ) {};

			reverse_iterator operator=( const reverse_iterator& other ) {

				this->current = other.base();
				return (*this);
			}

			virtual ~reverse_iterator(void) {}

			/*************************
			* @getter for _iterator
			* ***********************/
			iterator_type base(void) const {

				return (this->current);
			}

			/* ************************************************************************** */
			/*                                                                            */
			/*            @DEREFERENCING                                                  */
			/*                                                                            */
			/* ************************************************************************** */
			reference operator*(void) const {
		
				Iter	tmp = this->current;
				return *--tmp;
			}

			pointer operator->(void) const {
				
				return &( operator*() );
			}

			reference operator[]( difference_type n ) const {

				return (this->base()[-n-1]);
			};

			/* ************************************************************************** */
			/*                                                                            */
			/*            @INCR                                                           */
			/*                                                                            */
			/* ************************************************************************** */
			reverse_iterator& operator++(void) {

				--(this->current);
				return ( *this );
			}
			reverse_iterator& operator--(void) {

				++(this->current);
				return ( *this );
			}
			reverse_iterator operator++(int) {

				reverse_iterator tmp = *this;
				--(this->current);
				return (tmp);
			}
			reverse_iterator operator--(int) {

				reverse_iterator tmp = *this;
				++(this->current);
				return (tmp);
			}
			reverse_iterator operator+( difference_type n ) const {

				reverse_iterator tmp = *this;
				for (difference_type i = 0; i < n; ++i)
					++tmp;
				return ( tmp );
			}
			reverse_iterator operator-( difference_type n ) const {

				reverse_iterator tmp = *this;
				for (difference_type i = 0; i < n; ++i)
					--tmp;
				return ( tmp );
			}
			reverse_iterator& operator+=( difference_type n ) {

				if ( n < 0 )
					return (*this -= -n);

				for (difference_type i = 0; i < n; ++i) {
					++*this;
				}
				return (*this);
			}
			reverse_iterator& operator-=( difference_type n ) {

				if ( n < 0 )
					return (*this += -n);

				for (difference_type i = 0; i < n; ++i) {
					--*this;
				}
				return (*this);
			}
	};

	/* ************************************************************************** */
	/*                                                                            */
	/*            @outside comparaison                                            */
	/*                                                                            */
	/* ************************************************************************** */

	template <class Iter1, class Iter2>
	bool operator==( const ft::reverse_iterator<Iter1>&lhs,
		const ft::reverse_iterator<Iter2>&rhs ) {

		return ( lhs.base() == rhs.base() );
	}

	template <class Iter1, class Iter2>
	bool operator!=( const ft::reverse_iterator<Iter1>&lhs,
		const ft::reverse_iterator<Iter2>&rhs ) {

		return ( lhs.base() != rhs.base() );
	}

	template <class Iter1, class Iter2>
	bool operator>( const ft::reverse_iterator<Iter1>&lhs,
		const ft::reverse_iterator<Iter2>&rhs ) {

		return ( lhs.base() > rhs.base() );
	}

	template <class Iter1, class Iter2>
	bool operator>=( const ft::reverse_iterator<Iter1>&lhs,
		const ft::reverse_iterator<Iter2>&rhs ) {

		return ( lhs.base() >= rhs.base() );
	}

	template <class Iter1, class Iter2>
	bool operator<( const ft::reverse_iterator<Iter1>&lhs,
		const ft::reverse_iterator<Iter2>&rhs ) {

		return ( lhs.base() < rhs.base() );
	}

	template <class Iter1, class Iter2>
	bool operator<=( const ft::reverse_iterator<Iter1>&lhs,
		const ft::reverse_iterator<Iter2>&rhs ) {

		return ( lhs.base() <= rhs.base() );
	}

	/*************************
	* @use for symetric additon
	* (x + it) instead of (it + x)
	* ***********************/

	template< class Iter >
	ft::reverse_iterator<Iter> operator+( typename ft::reverse_iterator<Iter>::difference_type n,
		const ft::reverse_iterator<Iter>& it ) {

		return ( ft::reverse_iterator<Iter>(it.base() - n) );
	}

	/*************************
	* @compare two iterators
	* distance
	* ***********************/

	template< class Iter >
	typename ft::reverse_iterator<Iter> ::difference_type
		operator-( const ft::reverse_iterator<Iter>& lhs,
			const ft::reverse_iterator<Iter>& rhs ) {

		return ( rhs.base() - lhs.base() );
	}

};

#endif