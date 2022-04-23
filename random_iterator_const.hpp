/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_map_iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:15:07 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/03 16:55:11 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ITERATOR_CONST_HPP
#	define RANDOM_ITERATOR_CONST_HPP

template <
	typename T,
	typename Allocator
>

class ft::const_random_iterator : public ft::random_iterator<T, Allocator>
{
	private:
		typedef ft::random_iterator<T, Allocator>		iterator_noconst;
	
	public:		
		typedef const T&								reference;
		typedef const T									value_type;
		typedef const T*								pointer;
		
		/* ************************************************************************** */
		/*                                                                            */
		/*            @CONSTRUCTOR                                                    */
		/*                                                                            */
		/* ************************************************************************** */
		
		const_random_iterator(void)
		{};

		const_random_iterator( iterator_noconst ite ) : iterator_noconst( ite )
		{
		};

		/*************************
		* @destructor
		* ***********************/
		virtual ~const_random_iterator(void) {};

		/* ************************************************************************** */
		/*                                                                            */
		/*            @overrided func                                                 */
		/*                                                                            */
		/* ************************************************************************** */
		reference operator*() const {

			return ( iterator_noconst::operator*() );
		};
		/*************************
		* @i->m equivalent (*i).m
		* ***********************/
		pointer operator->() const {

			return ( iterator_noconst::operator->() );
		};

		reference operator[]( const typename iterator_noconst::difference_type n ) {

			return ( iterator_noconst::operator[](n) );
		};
};

#endif
