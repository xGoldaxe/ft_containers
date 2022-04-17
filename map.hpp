/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:27:43 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/17 19:25:25 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#	define MAP_HPP

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
			typedef tree_type*					tree_ptr;
			typedef Node<DataType<value_type> >	node_t;

			key_compare		_cmpr;
			Allocator		_alctr;
			size_type		_size;
			tree_ptr		_tree;


		/* ************************************************************************** */
		/*                                                                            */
		/*            @utils                                                          */
		/*                                                                            */
		/* ************************************************************************** */
		node_t* _search( value_type pair ) const {

			return ( this->_tree->searchTree( pair ) );
		}
		node_t* _search_pair( const Key &key ) const {
			value_type pair( key, T() );
			return this->_search( pair );
		}
	protected:
		/* ************************************************************************** */
		/*                                                                            */
		/*            @utils                                                          */
		/*                                                                            */
		/* ************************************************************************** */
		tree_ptr getTree() {
			return (this->_tree);
		}
		void setTree( tree_ptr newTree ) {
			this->_tree = newTree;
		}
		void setSize( size_type newSize ) {
			this->_size = newSize;
		}


	public:
		/* ************************************************************************** */
		/*                                                                            */
		/*            @CONSTRUCTOR                                                    */
		/*                                                                            */
		/* ************************************************************************** */
		map() : 
			_cmpr( Compare() ),
			_alctr( Allocator() ),
			_size(0),
			_tree( new tree_type( &compare_template<value_type, Compare> ) )
		{};


		explicit map( const Compare& comp, const Allocator& alloc = Allocator() );

		template< class InputIt >
		map( InputIt first, InputIt last,
				const Compare& comp = Compare(), const Allocator& alloc = Allocator() );

		map( const map &other );

		/* ************************************************************************** */
		/*                                                                            */
		/*            @DESTRUCTOR                                                     */
		/*                                                                            */
		/* ************************************************************************** */
		~map(void) {
			delete this->_tree;
		};

		Allocator get_allocator(void) { 
			
			return this->_alctr; 
		};

		/* ************************************************************************** */
		/*                                                                            */
		/*            @ELEMENT ACCESS                                                 */
		/*                                                                            */
		/* ************************************************************************** */

		T& at( const Key& key ) {
			
			node_t* ptr = _search_pair( key );
			if (!ptr)
				throw std::out_of_range("map::at");

			return ( ptr->data.data.second );
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

			Node<DataType<value_type> > *begin = this->_tree->getBegin();
			return iterator( this->_tree, begin );
		}

		const_iterator begin() const {

			Node<DataType<value_type> > *begin = this->_tree->getBegin();
			return const_iterator( this->_tree, begin );
		}

		iterator end() {

			return iterator( this->_tree, NULL );
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

		std::pair<iterator, bool> insert( const value_type& value) {

			node_t* ptr = this->_search(value);

			if (ptr != NULL) {
				return ( std::make_pair( iterator( this->_tree, ptr ), false ) );
			}
			//else
			node_t* it = this->_tree->insert(value);
			this->_size++;
			return ( std::make_pair( iterator( this->_tree, it ), true ) );
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

			node_t* ptr = _search_pair( key );
			if (ptr == NULL)
				return ( static_cast<size_type>(0) );
				
			this->_tree->deleteNode( ptr );
			this->_size--;
			return ( static_cast<size_type>(1) );
		};

		/*************************
		* @swap
		* ***********************/
		void swap( map& other ) {
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

			if ( this->_search_pair( key ) == NULL )
				return static_cast<size_type>(0);
			return static_cast<size_type>(1);
		};

		iterator find( const Key& key ) {

			node_t* ptr = _search_pair( key );
			if (ptr == NULL)
				return ( this->end() );

			return ( iterator( this->_tree, ptr ) );
		};

		const_iterator find( const Key& key ) const {

			node_t* ptr = _search_pair( key );
			if (ptr == NULL)
				return ( this->end() );

			return ( const_iterator( this->_tree, ptr ) );
		};

		/*************************
		* @equal range
		* ***********************/
		std::pair<iterator, iterator> equal_range( const Key& key ) {

			iterator first = lower_bound(key);
			iterator last = upper_bound(key);
			return std::pair<iterator, iterator>(first, last);
		};
	
		/*************************
		* @lower bound
		* ***********************/
		iterator lower_bound( const Key& key ) {

			for (iterator it = this->begin(); it != this->end(); ++it) {
				
				if ( !Compare()( it->first, key ) )
					return (it);
			}
			return ( this->end() );
		}

		/*************************
		* @upper bound
		* ***********************/
		iterator upper_bound( const Key& key ) {

			for (iterator it = this->begin(); it != this->end(); ++it) {
				
				if ( Compare()( key, it->first ) )
					return (it);
			}
			return ( this->end() );
		}

		/* ************************************************************************** */
		/*                                                                            */
		/*            @observers                                                      */
		/*                                                                            */
		/* ************************************************************************** */
		key_compare key_comp(void) const {

			return ( key_compare() );
		}

		class value_compare {
			protected:
				Compare comp;

			public:
				typedef bool 			result_type;
				typedef value_type		first_argument_type;
				typedef value_type		second_argument_type;

				value_compare(Compare c) : comp(c) {};
				virtual ~value_compare(void) {};

				bool operator() ( const value_type& lhs, const value_type& rhs ) const {

					return comp(lhs.first, rhs.first);
				}
		};

		value_compare value_comp(void) const {

			return ( value_compare( this->_cmpr ) );
		}
};



#endif