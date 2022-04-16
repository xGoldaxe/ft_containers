/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:27:43 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/16 17:40:08 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#	define MAP_HPP

#include "ft.hpp"

template < class value_type, class compare >
bool	compare_template( value_type a, value_type b ) {

	return !compare()( a.first, b.first );
};


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
		typedef std::pair<Key, T> 					value_type;
		// typedef std::pair<const Key, T> 			value_type;
		typedef std::size_t 						size_type;
		typedef std::ptrdiff_t 						difference_type;
		typedef Compare								key_compare;
		typedef Allocator							allocator_type;
		typedef value_type&							reference;
		typedef const value_type& 					const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;

		/* pointer */


	private:
			typedef RedBlackTree<value_type>	tree_type;

			Allocator		_alctr;
			// Compare			_cmpr;
			size_type		_size;
			tree_type		_tree;




	public:
		/* ************************************************************************** */
		/*                                                                            */
		/*            @CONSTRUCTOR                                                    */
		/*                                                                            */
		/* ************************************************************************** */
		map() : 
			_alctr( Allocator() ),
			_size(0),
			_tree( tree_type( &compare_template<value_type, Compare> ) )
		{};

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

		Allocator get_allocator(void) { 
			
			return this->_alctr; 
		};

		/* ************************************************************************** */
		/*                                                                            */
		/*            @ELEMENT ACCESS                                                 */
		/*                                                                            */
		/* ************************************************************************** */

		T& at( const Key& key ) {
			
			value_type pair( key, T() );
			return ( this->_tree.searchTree( pair ).second );
		};

		T& operator[]( const Key& key ) {

			try
			{
				return ( this->at(key) );
			}
			catch(const std::exception& e)
			{
				this->insert( std::make_pair( key, T() ) );
				return ( this->at(key) );
			}
		};

		/* ************************************************************************** */
		/*                                                                            */
		/*            @ITERATORS                                                      */
		/*                                                                            */
		/* ************************************************************************** */
		typedef ft::map_iterator<value_type>			iterator;
		typedef const ft::map_iterator<value_type>		const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		iterator begin() {

			Node<DataType<value_type> > *begin = this->_tree.getBegin();
			return iterator( &this->_tree, begin );
		}

		const_iterator begin() const {

			Node<DataType<value_type> > *begin = this->_tree.getBegin();
			return const_iterator( &this->_tree, begin );
		}

		iterator end() {

			return iterator( &this->_tree, NULL );
		}

		const_iterator end() const {

			return const_iterator( &this->_tree, NULL );
		}

		reverse_iterator rbegin() {

			return reverse_iterator( this->end() );
		}

		const_reverse_iterator rbegin() const {

			return const_reverse_iterator( this->end() );
		}

		reverse_iterator rend() {

			return reverse_iterator( this->begin() );
		}

		const_reverse_iterator rend() const {

			return const_reverse_iterator( this->begin() );
		}

		/* ************************************************************************** */
		/*                                                                            */
		/*            @MODIFIERS                                                      */
		/*                                                                            */
		/* ************************************************************************** */
		// std::pair<iterator, bool> insert( const value_type& value);
		void insert( value_type value ) {

			this->_tree.insert(value);
			this->_size++;
		};

		template < class IntputIt >
		void insert( IntputIt first, IntputIt last );
};



#endif