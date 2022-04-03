/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:54:09 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/03 16:25:21 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#	define VECTOR_HPP

#include <iostream>
#include <string>
#include <typeinfo>
#include "ft_namespace.hpp"
#include <memory>
#include <stdexcept>
#include <stdlib.h>
#include <sstream>
#include <stdexcept>

template <
	typename T,
	typename Allocator = std::allocator<T>
>


class ft::vector
{
	public :
		/* ************************************************************************** */
		/*                                                                            */
		/*            @MEMBER TYPES                                                   */
		/*                                                                            */
		/* ************************************************************************** */
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		
		/* ************************************************************************** */
		/*                                                                            */
		/*            @ITERATORS                                                      */
		/*                                                                            */
		/* ************************************************************************** */
		
		class iterator: public std::iterator<
			std::random_access_iterator_tag, //category
			T, //type
			difference_type, //distance 
			T*, //pointer
			T& // reference
		> {
			private:
				typedef typename std::iterator_traits<iterator>::difference_type difference_type;
				T* _from;
				T* _to;
				difference_type _position;
			
			protected:
				/*************************
				* @some gettters
				* ***********************/
				T*	getFrom( void ) const	{
				
					return ( this->_from );
				}
				T*	getTo( void ) const	{
				
					return ( this->_to );
				}
				difference_type getPosition( void ) const	{
				
					return ( this->_position );
				}
				/* ************************************************************************** */
				/*                                                                            */
				/*            @utils                                                          */
				/*                                                                            */
				/* ************************************************************************** */
				void	_incr( difference_type n ) {
					
					this->_position += n;
					if ( this->_position < 0)
						this->_position = static_cast<difference_type>(0);
					//comparing the pointer adress
					if ( (this->_from + this->_position) > this->_to )
						this->_position = static_cast<difference_type>(0);
				}
				void	_incrNoLimit( difference_type n ) {
					
					this->_position += n;
				}

			public:
				/* ************************************************************************** */
				/*                                                                            */
				/*            @LEGACY CONSTRUCTOR                                             */
				/*                                                                            */
				/* ************************************************************************** */
				
				/*************************
				* @default constructor
				* ***********************/
				iterator(void) : _from( NULL ), _to( NULL ), _position( 0 ) {};

				/*************************
				* @parameter constructor
				* ( should be hided from final user )
				* ***********************/
				iterator( T* from, T* to, difference_type position ) :
					_from( from ), _to( to ), _position( position )
				{};
				
				/*************************
				* @copy constructor
				* ***********************/
				iterator( const iterator & ref ) :
					_from( ref.getFrom() ),
					_to( ref.getTo() ),
					_position( ref.getPosition() )
				{};

				/*************************
				* @copy assignement
				* ***********************/
				iterator &operator=( const iterator & rhs ) {

					this->_from = rhs.getFrom();
					this->_to = rhs.getTo();
					this->_position = rhs.getPosition();
					return (*this);
				};

				/*************************
				* @destructor
				* ***********************/
				~iterator(void) {};

				/* ************************************************************************** */
				/*                                                                            */
				/*            @legacyOutputIterator                                           */
				/*                                                                            */
				/* ************************************************************************** */
				
				/* ************************************************************************** */
				/*                                                                            */
				/*            @legacyInputOperator                                            */
				/*                                                                            */
				/* ************************************************************************** */
				
				/*************************
				* @equally combarable
				* since we need all value
				* to have the wanted behavior
				* we need to check every values
				* ***********************/
				bool	operator==( const iterator &b ) const {

					if ( this->_from == b.getFrom()
						&& this->_to == b.getTo()
						&& this->_position == b.getPosition()
					)
						return true;
					return false;
				};
				bool	operator!=( const iterator &b ) const {
					return ( !( this->operator==(b) ) );
				};

				/*************************
				* @casting the value to
				* control as much as possible
				* the end value, but still
				* remain a undefined behavior
				* ***********************/
				reference& operator*(void) {

					return ( *static_cast<value_type *>(this->_from + this->_position) );
				};
				/*************************
				* @i->m equivalent (*i).m
				* ***********************/
				value_type *operator->() {

					return ( this->_from + this->_position );
				};
				iterator& operator++(void) {

					this->_incr( static_cast<difference_type>(1) );
					return ( *this );
				};
				/* ************************************************************************** */
				/*                                                                            */
				/*            @legacyForwardIterator                                          */
				/*                                                                            */
				/* ************************************************************************** */
				iterator operator++(int) {

					iterator tmp = *this;
					this->_incr( static_cast<difference_type>(1) );
					return tmp;
				};
				//*i++;

				/* ************************************************************************** */
				/*                                                                            */
				/*            @legacyBidirectionalIterator                                    */
				/*                                                                            */
				/* ************************************************************************** */
				/* past end iterator = undefined */
				iterator& operator--(void) {

					this->_incr( static_cast<difference_type>(-1) );
					return ( *this );
				};
				iterator operator--(int) {

					iterator tmp = *this;
					this->_incr( static_cast<difference_type>(-1) );
					return tmp;
				};
				//*it-- ??

				/* ************************************************************************** */
				/*                                                                            */
				/*            @legacyRandomAccessIterator                                     */
				/*                                                                            */
				/* ************************************************************************** */
				
				/*************************
				* @random modifier
				* ***********************/
				iterator& operator+=( const difference_type n ) {

					this->_incrNoLimit( n );
					return ( *this );
				};
				iterator& operator-=( const difference_type n ) {

					return ( this->operator+=( -n ) );
				};
				/*************************
				* @addition and substratction
				* of iterators
				* ***********************/
			
				/* friend allow the function to be non-member and also overloaded operator 
				*  In our case we wanted asymetric operator,
				*/
				/*addition*/
				friend iterator operator+( const difference_type n,  const iterator &a ) {

					iterator temp = a;
					return temp += n;
				};
				iterator operator+( const difference_type n ) const {

					iterator temp = *this;
					return temp += n;
				};
				/*substratction*/
				iterator operator-( const difference_type n ) const {

					iterator temp = *this;
					return temp -= n;
				};

				/*************************
				* @difference between iterators
				* ***********************/
				difference_type operator-( const iterator &b ) const {
					
					difference_type diff = this->_position - b.getPosition();
					if ( *this == b + (diff) )
						return diff;
					return static_cast<difference_type>(0);
				};

				reference& operator[]( const difference_type n ) {

					return ( *static_cast<value_type *>(this->_from + this->_position + n) );
				};

				/*************************
				* @comparaison
				* ***********************/
				bool	operator<( const iterator &b ) const {

					return ( (b - *this) > 0 );
				};
				bool	operator>( const iterator &b ) const {

					return ( (b - *this) < 0 );
				};
				bool	operator>=( const iterator &b ) const {

					return ( !( this->operator<(b) ) );
				};
				bool	operator<=( const iterator &b ) const {

					return ( !( this->operator>(b) ) );
				};
		};
		typedef const iterator const_iterator;

		/*?*/
		// typedef value_type iterator;
		// typedef const iterator const_iterator;
		// /*?*/
		// typedef std::reverse_iterator<iterator> reverse_iterator;
		// typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	private:
		Allocator 	_alctr;
		size_type	_size;
		size_type	_capacity;
		T* 			_arr;

		/* ************************************************************************** */
		/*                                                                            */
		/*            @UTILS                                                          */
		/*                                                                            */
		/* ************************************************************************** */
		bool	_M_range_check( size_type __n ) const {

			if ( __n >= this->_size ) {

				std::string error = "vector::_M_range_check: __n (which is " + ft::toString( __n )
					+ ") >= this->size() (wich is " + ft::toString( this->_size ) + ")";
				throw ( std::out_of_range( error ) );
			}
			return true;
		}

		value_type*	copy_arr( size_type new_cap, value_type *ref, size_type ref_size ) {

			value_type *new_arr = this->_alctr.allocate( new_cap );
			for ( size_t i = 0; i < ref_size; ++i )
				this->_alctr.construct( new_arr + i, ref[i] );
			return ( new_arr );
		}

		iterator _move_array( iterator begin, iterator end, iterator dest ) {

			iterator real_dest = dest;
			std::cout << "<-----------{}----------->" << std::endl;			
			for (; end > begin; --end, --dest)
			{
				std::cout << *end << std::endl;
				*dest = *end;
			}
			std::cout << "<-----------{}----------->" << std::endl;
			return real_dest;
		}

		//could use a non member function with args instead of this
		value_type* replace_arr( value_type *new_arr ) {

			this->_alctr.deallocate( this->_arr, this->_capacity );
			this->_arr = new_arr;
			return (this->_arr);
		}

		bool	_verify_capacity( size_type incr = 1 ) {

			if ( this->_size + incr > this->_capacity ) {
				
				this->reserve(this->_capacity * 2);
				return true;
			}
			return false;
		}

	protected:
		/* ************************************************************************** */
		/*                                                                            */
		/*            @PROTECTED GETTERS                                              */
		/*                                                                            */
		/* ************************************************************************** */
		size_type	getSize( void ) const	{
		
			return ( this->_size );
		}

		T*	getArr( void ) const	{
		
			return ( this->_arr );
		}

		size_type	getCapacity( void ) const {

			return ( this->_capacity );
		}

	public:
		/* ************************************************************************** */
		/*                                                                            */
		/*            @CONSTRUCTOR                                                    */
		/*                                                                            */
		/* ************************************************************************** */
		
		/*************************
		* @DEFAULT CONSTRUCTOR
		* ***********************/
		vector( void ) : 
			_alctr(),
			_size( 0 ),
			_capacity( _size ),
			_arr( this->_alctr.allocate( _capacity ) )
		{

			std::cout << "ft_vector created!" << std::endl;
		};
		
		/*************************
		* @ALLOC CONSTRUCTOR
		* ***********************/
		explicit vector( const Allocator& alloc ) :
			_alctr( alloc ),
			_size( 0 ),
			_capacity( _size ),
			_arr( this->_alctr.allocate( _capacity ) )
		{

			std::cout << "ft_vector alloc constructor" << std::endl;
		};

		/*************************
		* @COUNT CONSTRUCTOR
		* fill the vector with
		* the given value
		* ***********************/
		explicit vector(
			size_type count,
			const T& value = T(),
			const Allocator& alloc = Allocator()
		) :
			_alctr( alloc ),
			_size ( count ),
			_capacity( _size ),
			_arr( this->_alctr.allocate( _capacity ) )
		{

			for (size_type i = 0; i < count; ++i)
				this->_alctr.construct( this->_arr + i, value );
			std::cout << "ft_vector count constructor" << std::endl;
		}

		/*************************
		* @RANGE CONSTRUCTOR
		* ***********************/
		//look for error when first > last
		template< class InputIt >
		vector( InputIt first, InputIt last,
				const Allocator& alloc = Allocator()
		) :
			_alctr( alloc ),
			_size( std::distance(first, last) ),
			_capacity( _size ),
			_arr( this->_alctr.allocate( _capacity ) )
		{
			
			size_t i = 0;
			for ( InputIt it = first; it != last; ++it)
			{
				this->_alctr.construct( this->_arr + i, *it );
				++i;
			}
			std::cout << "ft_vector range constructor, size: " << this->_size << std::endl;
		}

		/*************************
		* @COPY CONSTRUCTOR
		* ***********************/ 
		vector( const vector& other ) :
			_alctr( other.get_allocator() ),
			_size( other.getSize() ),
			_capacity( other.getCapacity() ),
			_arr( this->_alctr.allocate( _capacity ) )
		{

			T* arr = other.getArr();
			for ( size_t i = 0; i < this->_size; ++i)
				this->_arr[i] = arr[i];
			std::cout << "ft_vector copy constructor" << std::endl;
		}

		/* ************************************************************************** */
		/*                                                                            */
		/*            @DESTRUCTOR                                                     */
		/*                                                                            */
		/* ************************************************************************** */
		
		/*************************
		* @DESTRUCTOR
		* ***********************/
		~vector( void ) {
			//cleanup
			_alctr.deallocate( this->_arr, this->_capacity );
			std::cout << "ft_vector destroyed!" << std::endl;
		};

		/* ************************************************************************** */
		/*                                                                            */
		/*            @OTHER ASSIGNATIONS                                             */
		/*                                                                            */
		/* ************************************************************************** */

		/*************************
		* @OPERATOR OVELOAD
		* ASSIGNATION =
		* ***********************/
		vector &   operator=( vector const & other );

		/*************************
		* @ASSIGN BY SIZE
		* ***********************/
		void    assign( size_type count, const T& value );

		/*************************
		* @ASSING BY ITERATION
		* ***********************/
		template < class InputIt >
		void    assign( InputIt first, InputIt last );

		/*************************
		* @GETTER FOR ALLOCATOR
		* ***********************/
		allocator_type get_allocator() const {

			return ( this->_alctr );
		};

		/* ************************************************************************** */
		/*                                                                            */
		/*            @ELEMENT ACCESS                                                 */
		/*                                                                            */
		/* ************************************************************************** */

		/*************************
		* @AT
		* ***********************/
		reference at( size_type pos ) {

			/* may throw an exception */
			this->_M_range_check( pos );
			return ( this->_arr[pos] );
		};

		const_reference at( size_type pos ) const {

			/* may throw an exception */
			this->_M_range_check( pos );
			return ( const_cast<const_reference>(this->_arr[pos]) );
		};

		/*************************
		* @[] OPERATOR OVERLOAD
		* FOR ACCESS
		* accessing to value >= _size
		* will result to undefine behavior
		* ***********************/
		reference operator[]( size_type pos ) {

			return ( this->_arr[pos] );
		};

		const_reference operator[]( size_type pos ) const {

			return ( const_cast<const_reference>(this->_arr[pos]) );
		};

		/*************************
		* @FRONT ACCESS
		* ***********************/
		reference front( void ) {

			return ( this->_arr[0] );
		};

		const_reference front() const {

			return ( const_cast<const_reference>(this->_arr[0]) );
		};

		/*************************
		* @BACK ACCESS
		* ***********************/
		reference back( void ) {

			return ( this->_arr[this->_size - 1] );
		};

		const_reference back( void ) const {

			return ( const_cast<const_reference>(this->_arr[this->_size - 1]) );
		};

		/*************************
		* @DATA ACCESS
		* return ptr NULL in case of 
		* size of 0 to avoid invalid
		* range
		* ***********************/
		T* data( void ) {

			if ( this->_size == 0 ) {

				return ( NULL );
			}
			return ( this->_arr );
		};

		const T* data( void ) const {

			if ( this->_size == 0 ) {

				return ( NULL );
			}
			return ( const_cast<const_reference>(this->_arr) );
		};

		/* ************************************************************************** */
		/*                                                                            */
		/*            @ITARATOR GETTERS                                               */
		/*                                                                            */
		/* ************************************************************************** */


		iterator begin() {

			return iterator( this->_arr, this->_arr + this->_size, 0 );
		};		
		iterator end() {

			return iterator( this->_arr, this->_arr + this->_size, this->_size );
		};
		const iterator begin() const {
			
			return iterator( this->_arr, this->_arr + this->_size, 0 );
		};
		const iterator end() const {
			
			return iterator( this->_arr, this->_arr + this->_size, this->_size );
		};
		
		// reverse_iterator rbegin();
		// const reverse_iterator rbegin() const;

		// reverse_iterator rend();
		// const reverse_iterator rend() const;

		/* ************************************************************************** */
		/*                                                                            */
		/*            @CAPACITY                                                       */
		/*                                                                            */
		/* ************************************************************************** */

		bool empty(void) const {

			return ( this->begin() == this->end() );
		};

		size_type size(void) const {

			return this->_size;
		};

		size_type max_size(void) const {

			return this->_alctr.max_size();
		};

		size_type capacity(void) const {

			return this->_capacity;
		};

		/*************************
		* @reserve
		* increase memory allocation
		* and reallocate
		* ***********************/
		void reserve( size_type new_cap ) {

			if ( new_cap > this->max_size() ) 
				throw ( std::length_error("vector::reserve") );
			if ( new_cap <= this->_capacity )
				return ;

			replace_arr( copy_arr( new_cap, this->_arr, this->_size ) );
			this->_capacity = new_cap;
		};

		/* ************************************************************************** */
		/*                                                                            */
		/*            @MODIFIERS                                                      */
		/*                                                                            */
		/* ************************************************************************** */
		
		/*************************
		* @clear the vector and set
		* size to 0, capacity stay
		* unchanged.
		* ***********************/
		void clear(void) {

			for (iterator it = this->begin(); it != this->end(); ++it)
				this->_alctr.destroy(&(*it));
			this->_size = 0;
		}

		/*************************
		* @insert
		* ***********************/
		//we need reverse iterator for ths
		iterator insert( iterator pos, const T& value ) {
			
			this->_verify_capacity(1);
			pos = this->begin() + (pos - this->begin() );
			this->_move_array(pos, this->end() - 1, this->end() );
			this->_size++;
			*pos = value;
			return (pos);
		};

		iterator insert( iterator pos, size_type count, const T& value );

		template< class InputIt >
		void insert( const_iterator pos, InputIt first, InputIt last );

		/*************************
		* @erase
		* ***********************/

		//check must be *(possible)
		iterator erase( iterator pos );

		//if first == last, do nothing
		iterator erase( iterator first, iterator last );

		/*************************
		* @push_back
		* ***********************/
		void push_back( const T& value ) {

			this->_verify_capacity(1);
			this->_size++;
			this->_alctr.construct( &*(this->end() - 1), value );
		};

		/*************************
		* @pop_back
		* ***********************/
		void pop_back() {

			this->_alctr.destroy( &*(this->end() - 1) );
			this->_size--;
		};
};


#endif