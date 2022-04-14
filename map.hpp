/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:27:43 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/14 18:47:44 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#	define MAP_HPP

#include "ft.hpp"


template <
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<std::pair<const Key, T> >
>

class ft::map {

	public:
		/* ************************************************************************** */
		/*                                                                            */
		/*            @MEMBER TYPES                                                   */
		/*                                                                            */
		/* ************************************************************************** */
		typedef Key 								key_type;
		typedef T									mapped_type;
		typedef std::pair<const Key, T> 			value_type;
		typedef std::size_t 						size_type;
		typedef std::ptrdiff_t 						difference_type;
		typedef Compare								key_compare;
		typedef Allocator							allocator_type;
		typedef value_type&							reference;
		typedef const value_type& 					const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;

		/* pointer */
		// typedef ft::map_iterator<value_type>	iterator;
		// typedef const ft::map_iterator<value_type>	const_iterator;
		// typedef ft::reverse_iterator<iterator>	reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	private:
			typedef Node<std::pair<key_type, mapped_type> >	node_type;

			Allocator 	_alctr;
			Compare		_cmpr;
			size_type 	_size;
			node_type		*_root;


	public:
		/* ************************************************************************** */
		/*                                                                            */
		/*            @CONSTRUCTOR                                                    */
		/*                                                                            */
		/* ************************************************************************** */
		map() : _alctr(), _cmpr(), _size(0), _root(NULL) {};

		explicit map( const Compare& comp, const Allocator& alloc = Allocator() );

		template< class InputIt >
		map( InputIt first, InputIt last,
				const Compare& comp = Compare(), const Allocator& alloc = Allocator() );

		map( const map&other );

		/* ************************************************************************** */
		/*                                                                            */
		/*            @DESTRUCTOR                                                     */
		/*                                                                            */
		/* ************************************************************************** */
		~map(void) {};

		get_allocator(void) { return this->_alctr };

		/* ************************************************************************** */
		/*                                                                            */
		/*            @ELEMENT ACCESS                                                 */
		/*                                                                            */
		/* ************************************************************************** */

		/* ************************************************************************** */
		/*                                                                            */
		/*            @MODIFIERS                                                      */
		/*                                                                            */
		/* ************************************************************************** */
		// std::pair<iterator, bool> insert( const value_type& value);

		template < class IntputIt >
		void insert( IntputIT first, IntputIt last );
};



#endif