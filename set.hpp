/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:27:43 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/25 23:22:42 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#	define SET_HPP

#include "pair.hpp"
#include "redBlackTree.hpp"
#include "map_iterator.hpp"
#include "map_iterator_const.hpp"
#include "reverse_iterator.hpp"
#include <limits>

template < class value_type, class compare >
bool	compare_template_single( value_type a, value_type b ) {

	return !compare()( a, b );
};

namespace ft
{

	template <
		class Key,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<Key>
	>
	
	class set {

		public:
			/* ************************************************************************** */
			/*                                                                            */
			/*            @MEMBER TYPES                                                   */
			/*                                                                            */
			/* ************************************************************************** */
			typedef Key 								key_type;
			typedef Key 								value_type;
			typedef std::size_t 						size_type;
			typedef std::ptrdiff_t 						difference_type;
			typedef Compare								key_compare;
			typedef Compare								value_compare;
			typedef Allocator							allocator_type;
			typedef value_type&							reference;
			typedef const value_type& 					const_reference;
			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;

			/* pointer */


		private:
				typedef RedBlackTree<value_type, Allocator>		tree_type;
				typedef tree_type*								tree_ptr;
				typedef Node<DataType<value_type> >				node_t;

				key_compare		_cmpr;
				Allocator		_alctr;
				size_type		_size;
				tree_ptr		_tree;


			/* ************************************************************************** */
			/*                                                                            */
			/*            @utils                                                          */
			/*                                                                            */
			/* ************************************************************************** */
			node_t* _search( value_type value_key ) const {

				return ( this->_tree->searchTree( value_key ) );
			}
			node_t* _search_key( const Key &key ) const {
				return this->_search( key );
			}
			
			typedef typename Allocator::template rebind<tree_type>::other	tree_allocator_t;
			tree_ptr _construct_tree() {
			
				tree_type			tree_value( &compare_template_single<value_type, Compare> );
				tree_allocator_t	tree_allocator( this->_alctr );
				tree_ptr tree = tree_allocator.allocate(1);
				tree_allocator.construct(tree, tree_value);
				return tree;
			}
			void	_delete_tree(tree_ptr tree) {
				
				tree_allocator_t	tree_allocator;
				tree_allocator.destroy(tree);
				tree_allocator.deallocate(tree, 1);
				tree = NULL;
			}
			
		protected:
			/* ************************************************************************** */
			/*                                                                            */
			/*            @utils                                                          */
			/*                                                                            */
			/* ************************************************************************** */
			tree_ptr getTree() const {
				return (this->_tree);
			}
			void setTree( tree_ptr newTree ) {
				this->_tree = newTree;
			}
			void setSize( size_type newSize ) {
				this->_size = newSize;
			}

			key_compare _get_compare(void) const {
				return (this->_cmpr);
			}

		public:
			/* ************************************************************************** */
			/*                                                                            */
			/*            @CONSTRUCTOR                                                    */
			/*                                                                            */
			/* ************************************************************************** */
			set() : 
				_cmpr( Compare() ),
				_alctr( Allocator() ),
				_size(0),
				_tree( this->_construct_tree() )
			{};

			explicit set( const Compare& comp, const Allocator& alloc = Allocator() ) :
				_cmpr( comp ),
				_alctr( alloc ),
				_size(0),
				_tree( this->_construct_tree() )
			{};

			template< class InputIt >
			set( 	InputIt first, InputIt last,
					const Compare& comp = Compare(),
					const Allocator& alloc = Allocator() ) :
				_cmpr( comp ),
				_alctr( alloc ),
				_size( 0 ),
				_tree( this->_construct_tree() )
			{
				/* insert from first to last */
				this->insert( first, last );
			};

			set( const set &other ) :
				_cmpr( other._get_compare() ),
				_alctr( other.get_allocator() ),
				_size( 0 ), //will be updated at insert
				_tree( this->_construct_tree() )
			{
				/* we must copy the tree */
				this->insert( other.begin(), other.end() );
			};

			set& operator=( const set& other ) {

				// if (*this == other)
				// 	return (*this);
				this->_delete_tree( this->_tree );
				this->_tree = this->_construct_tree();
				this->_size = 0;
				this->insert( other.begin(), other.end() );
				return *this;
			}
			/* ************************************************************************** */
			/*                                                                            */
			/*            @DESTRUCTOR                                                     */
			/*                                                                            */
			/* ************************************************************************** */
			~set(void) {
				this->_delete_tree( this->_tree );
			};

			Allocator get_allocator(void) const { 
				
				return this->_alctr; 
			};

			/* ************************************************************************** */
			/*                                                                            */
			/*            @ITERATORS                                                      */
			/*                                                                            */
			/* ************************************************************************** */
			private:
				typedef ft::map_iterator<value_type, tree_type>				_iterator;
			public:
			typedef ft::const_map_iterator<value_type, tree_type>		iterator;
			typedef ft::const_map_iterator<value_type, tree_type>		const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

			iterator begin(void) {

				Node<DataType<value_type> > *begin = this->_tree->getBegin();
				return const_iterator( this->_tree, begin );
			}

			const_iterator begin(void) const {

				Node<DataType<value_type> > *begin = this->_tree->getBegin();
				return const_iterator( this->_tree, begin );
			}

			iterator end() {

				return const_iterator( this->_tree, NULL );
			}

			const_iterator end() const {

				return const_iterator( this->_tree, NULL );
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
			/*            @CAPACITY                                                       */
			/*                                                                            */
			/* ************************************************************************** */
			
			bool empty() const {

				return ( this->begin() == this->end() );
			};

			size_type size() const {

				return this->_size;
			}

			size_type max_size() const {

				return (std::numeric_limits<difference_type>::max() / sizeof(Node<DataType<value_type> >) );
			}

			/* ************************************************************************** */
			/*                                                                            */
			/*            @MODIFIERS                                                      */
			/*                                                                            */
			/* ************************************************************************** */
			void clear() {

				this->_tree->cleanTree();
				this->_size = 0;
			};

			/*************************
			* @insert
			* ***********************/

			ft::pair<iterator, bool> insert( const value_type& value) {

				node_t* ptr = this->_search(value);

				if (ptr != NULL) {
					return ( ft::make_pair( iterator( this->_tree, ptr ), false ) );
				}
				//else
				node_t* it = this->_tree->insert(value);
				this->_size++;
				return ( ft::make_pair( iterator( this->_tree, it ), true ) );
			};

			iterator insert( iterator hint, const value_type& value ) {

				node_t* ptr = this->_search(value);
				(void)hint;
				if (ptr != NULL)
					return iterator( this->_tree, ptr );

				node_t* it = this->_tree->insert(value);
				this->_size++;
				return iterator( this->_tree, it );
			};

			template < class IntputIt >
			void insert( IntputIt first, IntputIt last ) {

				for (; first != last; ++first) {

					insert(*first);
				}
			};

			/*************************
			* @erase
			* ***********************/
			void erase( iterator pos ) {

				this->_tree->deleteNode( pos.getActual() );
				this->_size--;
			};

			void erase( iterator first, iterator last) {
				
				iterator next;

				while (first != last) {

					next = first;
					++next;
					this->erase( first );
					first = next;
				}
			};

			size_type erase( const Key& key ) {

				node_t* ptr = _search_key( key );
				if (ptr == NULL)
					return ( static_cast<size_type>(0) );
					
				this->_tree->deleteNode( ptr );
				this->_size--;
				return ( static_cast<size_type>(1) );
			};

			/*************************
			* @swap
			* ***********************/
			void swap( set& other ) {
				tree_ptr tmpTree = this->_tree;
				this->_tree = other.getTree();
				other.setTree( tmpTree );

				size_type tmpSize = this->size();
				this->_size = other.size();
				other.setSize( tmpSize );
			};

			/* ************************************************************************** */
			/*                                                                            */
			/*            @lookup                                                         */
			/*                                                                            */
			/* ************************************************************************** */
			size_type count( const Key& key ) const {

				if ( this->_search_key( key ) == NULL )
					return static_cast<size_type>(0);
				return static_cast<size_type>(1);
			};

			iterator find( const Key& key ) {

				node_t* ptr = _search_key( key );
				if (ptr == NULL)
					return ( this->end() );

				return ( iterator( this->_tree, ptr ) );
			};

			const_iterator find( const Key& key ) const {

				node_t* ptr = _search_key( key );
				if (ptr == NULL)
					return ( this->end() );

				return ( const_iterator( iterator( this->_tree, ptr ) ) );
			};

			/*************************
			* @equal range
			* ***********************/
		private:
			template < class Ite >
			ft::pair<Ite, Ite> _equal_range( const Key& key ) const {

				Ite first = lower_bound(key);
				Ite last = upper_bound(key);
				return ft::pair<Ite, Ite>(first, last);
			};

		public:
			ft::pair<iterator, iterator> equal_range( const Key& key ) {

				return _equal_range<iterator>(key);
			};

			ft::pair<const_iterator, const_iterator> equal_range( const Key& key ) const {

				return _equal_range<const_iterator>(key);
			}
		
			/*************************
			* @lower bound
			* ***********************/
		private:
			iterator _lower_bound( const Key& key ) const {

				for (iterator it = this->begin(); it != this->end(); ++it) {
					
					if ( !Compare()( *it, key ) )
						return (it);
				}
				return ( this->end() );
			}
		public:
			iterator lower_bound( const Key& key ) {

				return _lower_bound( key );
			}
			const_iterator lower_bound( const Key& key ) const {

				return const_iterator( _lower_bound( key ) );
			}

			/*************************
			* @upper bound
			* ***********************/
		private:
			iterator _upper_bound( const Key& key ) const {

				for (iterator it = this->begin(); it != this->end(); ++it) {
					
					if ( Compare()( key, *it ) )
						return (it);
				}
				return ( this->end() );
			}
		public:
			iterator upper_bound( const Key& key ) {

				return _upper_bound( key );
			}
			const_iterator upper_bound( const Key& key ) const {

				return const_iterator( _upper_bound( key ) );
			}

			/* ************************************************************************** */
			/*                                                                            */
			/*            @observers                                                      */
			/*                                                                            */
			/* ************************************************************************** */
			value_compare key_comp(void) const {

				return ( value_compare() );
			}

			value_compare value_comp(void) const {

				return ( value_compare( this->_cmpr ) );
			}
	};
};

namespace ft {

	/* ************************************************************************** */
	/*                                                                            */
	/*            @COMPARAISON                                                    */
	/*                                                                            */
	/* ************************************************************************** */

	template <class Key, class Compare, class Allocator>
		bool operator==( const ft::set<Key,Compare,Allocator>& lhs, const ft::set<Key,Compare,Allocator>& rhs )
		{
			if ( lhs.size() != rhs.size() )
				return false;
			typename ft::set<Key, Compare, Allocator>::iterator it = lhs.begin();
			typename ft::set<Key, Compare, Allocator>::iterator itr = rhs.begin();
			for ( ; it != lhs.end(); ++it, ++itr ) {

				if ( *it != *itr )
					return false;
			}
			return true;
		}

	template <class Key, class Compare, class Allocator>
		bool operator!=( const ft::set<Key,Compare,Allocator>& lhs, const ft::set<Key,Compare,Allocator>& rhs )
		{
			return ( !(lhs == rhs) );
		}

	/*************************
	* @> / >=
	* ***********************/

	template <class Key, class Compare, class Allocator>
		bool operator<( const ft::set<Key,Compare,Allocator>& lhs, const ft::set<Key,Compare,Allocator>& rhs )
		{
			typename ft::set<Key, Compare, Allocator>::iterator it = lhs.begin();
			typename ft::set<Key, Compare, Allocator>::iterator itr = rhs.begin();
			for (; it != lhs.end(); ++it, ++itr ) {

				if ( *it < *itr )
					return true;
				else if ( *it > *itr )
				 	return false;
			}
			if ( it == lhs.end() && itr != rhs.end() )
				return true;
			return false;
		}

	template <class Key, class Compare, class Allocator>
		bool operator<=( const ft::set<Key,Compare,Allocator>& lhs, const ft::set<Key,Compare,Allocator>& rhs )
		{
			return ( lhs < rhs || lhs == rhs );
		}

	/*************************
	* @< / <=
	* ***********************/

	template <class Key, class Compare, class Allocator>
		bool operator>( const ft::set<Key,Compare,Allocator>& lhs, const ft::set<Key,Compare,Allocator>& rhs )
		{
			return !( lhs <= rhs );
		}

	template <class Key, class Compare, class Allocator>
		bool operator>=( const ft::set<Key,Compare,Allocator>& lhs, const ft::set<Key,Compare,Allocator>& rhs )
		{
			return !( lhs < rhs );
		}
}

/*************************
* @specialize std::swap
* ***********************/

namespace std {
	template <class Key, class Compare, class Allocator>
		void swap ( ft::set<Key,Compare,Allocator>& lhs, ft::set<Key,Compare,Allocator>& rhs )
		{
			lhs.swap(rhs);
		}
}

#endif