/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:54:09 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/25 23:31:15 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#	define VECTOR_HPP

#include "reverse_iterator.hpp"
#include "to_string.hpp"
#include "random_iterator.hpp"
#include "random_iterator_const.hpp"
#include "reverse_iterator.hpp"
#include "is_integral.hpp"
#include "enable_if.hpp"
#include <limits>

namespace ft
{

	template <
		class T,
		class Allocator = std::allocator<T>
	>

	class vector
	{
		public :
			/* ************************************************************************** */
			/*                                                                            */
			/*            @MEMBER TYPES                                                   */
			/*                                                                            */
			/* ************************************************************************** */
			typedef T 									value_type;
			typedef Allocator 							allocator_type;
			typedef std::size_t 						size_type;
			typedef std::ptrdiff_t 						difference_type;
			typedef value_type& 						reference;
			typedef const value_type& 					const_reference;
			typedef typename Allocator::pointer 		pointer;
			typedef typename Allocator::const_pointer	const_pointer;

			/* ************************************************************************** */
			/*                                                                            */
			/*            @ITERATORS                                                      */
			/*                                                                            */
			/* ************************************************************************** */

			typedef ft::random_iterator<value_type, Allocator> iterator;
			typedef ft::const_random_iterator<value_type, Allocator> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		private:
			Allocator 	_alctr;
			size_type	_size;
			size_type	_capacity;
			pointer 	_arr;

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

			template < typename InputIt >
			difference_type _get_distance( InputIt begin, InputIt end ) {

				difference_type diff = 0;
				while (begin != end) {
					++diff;
					++begin;
					if ( diff == std::numeric_limits<difference_type>::max() )
						throw ( std::length_error("_get_distance") );
				}
				return diff;
			}

			void _self_construct( iterator it, value_type value ) {

				if ( ( it - this->begin() ) >= static_cast<difference_type>(this->_size) )
					this->_alctr.construct( &*it, value );
				else
					*it = value;
			}

			pointer _safe_allocate(size_type cap) {
				
				if ( cap == 0 )
					return NULL;

				return this->_alctr.allocate(cap);
			}

			void _safe_deallocate( pointer ptr, size_type cap ) {
				
				if ( ptr == NULL )
					return ;
					
				this->_alctr.deallocate( ptr, cap );
				ptr = NULL;
			}

			template < typename InputIt >
			InputIt	_move_array_forward( InputIt begin, InputIt end, InputIt dest ) {

				typedef typename ft::reverse_iterator<InputIt> r_ite;
				r_ite dest_it( dest + (end - begin) - static_cast<difference_type>(1) );
				r_ite end_r( begin );

				if ( begin > end )
					return (dest);
				for ( r_ite it(end); it != end_r; ++dest_it, ++it ) {

					this->_self_construct( dest_it.base(), *it );
				}
				return (dest);
			}

			iterator	_move_array_backward( iterator begin, iterator end, iterator dest ) {

				if ( begin > end )
					return (dest);
				for ( iterator it = begin; it != end; ++dest, ++it ) {

					this->_self_construct( dest, *it );
				}
				return (dest);
			}


			value_type*	copy_arr( size_type new_cap, value_type *ref, size_type ref_size ) {

				if ( new_cap == 0 )
					return NULL;
				value_type *new_arr = this->_safe_allocate( new_cap );
				for ( size_t i = 0; i < ref_size; ++i )
					this->_alctr.construct( new_arr + i, *(ref + i) );
				return ( new_arr );
			}

			//could use a non member function with args instead of this
			value_type* replace_arr( value_type *new_arr ) {

				for ( size_type i = 0; i < this->_size; ++i )
					_alctr.destroy( this->_arr + i );
				this->_safe_deallocate( this->_arr, this->_capacity );
				this->_arr = new_arr;
				return (this->_arr);
			}

			bool _verify_capacity( size_type incr = 1 ) {

				size_type new_cap = incr + this->_size;
				if ( incr > this->max_size() || new_cap > this->max_size() ) {

					throw ( std::length_error("vector::_verify_capacity") );
				}
				if ( new_cap > this->_capacity ) {

					if ( new_cap <= this->size() * 2 )
						new_cap = this->size() * 2;

					this->reserve(new_cap);
					return true;
				}
				return false;
			}

			value_type *_size_cpy( size_type count, const value_type &value, value_type *dst ) {

				for ( size_type i = 0; i < count; ++i ) {

					// this->_alctr.destroy( dst + i );
					// this->_alctr.construct( dst + i, value );
					*(dst + i) = value;
				}
				return dst;
			};

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
				_arr( this->_safe_allocate( _capacity ) )
			{

				// std::cout << "ft_vector created!" << std::endl;
			};

			/*************************
			* @ALLOC CONSTRUCTOR
			* ***********************/
			explicit vector( const Allocator& alloc ) :
				_alctr( alloc ),
				_size( 0 ),
				_capacity( _size ),
				_arr( this->_safe_allocate( _capacity ) )
			{

				// std::cout << "ft_vector alloc constructor" << std::endl;c
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
				_arr( this->_safe_allocate( _capacity ) )
			{

				for (size_type i = 0; i < count; ++i)
					this->_alctr.construct( this->_arr + i, value );
				// std::cout << "ft_vector count constructor" << std::endl;
			}

			/*************************
			* @RANGE CONSTRUCTOR
			* ***********************/
			template< class InputIt >
			vector( InputIt first, InputIt last,
					const Allocator& alloc = Allocator(),
					typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0
			) :
				_alctr( alloc ),
				_size( this->_get_distance(first, last) ),
				_capacity( _size ),
				_arr( this->_safe_allocate( _capacity ) )
			{

				size_type i = 0;
				for ( InputIt it = first; it != last; ++it)
				{
					this->_alctr.construct( this->_arr + i, *it );
					++i;
				}
			}

			/*************************
			* @COPY CONSTRUCTOR
			* ***********************/
			vector( const vector& other ) :
				_alctr( other.get_allocator() ),
				_size( other.getSize()  ),
				_capacity( other.getSize() ),
				_arr(
					copy_arr( this->_capacity, other.getArr(), other.getSize() )
				)
			{
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
				if (this->_arr == NULL)
					return ;
				for ( size_type i = 0; i < this->_size; ++i )
					this->_alctr.destroy( this->_arr + i );
				this->_safe_deallocate( this->_arr, this->_capacity );
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
			vector &   operator=( vector const & other ) {
				
				if (*this == other)
					return (*this);
				//cleanup before modification
				for ( size_type i = 0; i < this->_size; ++i )
					_alctr.destroy( this->_arr + i );
				this->_safe_deallocate( this->_arr, this->_capacity );

				this->_alctr = other.get_allocator();
				this->_size = other.getSize();
				this->_capacity = other.getSize();
				this->_arr = copy_arr( this->_capacity, other.getArr(), other.getSize() );
				return (*this);
			};

			/*************************
			* @ASSIGN BY SIZE
			* ***********************/
			void    assign( size_type count, const T& value ) {

				this->reserve( count );
				for ( size_type i = 0; i < count; ++i ) {
					this->_self_construct( this->begin() + i, value );
				}
				if (this->_size > count) {
					for ( size_type i = 0; i < (this->_size - count); ++i)
						this->_alctr.destroy( this->_arr + i );
				}
				this->_size = count;
	
			};

			/*************************
			* @ASSING BY ITERATION
			* ***********************/
			template<typename InputIt>
			typename ft::enable_if<!ft::is_integral<InputIt>::value>::type
			assign( InputIt first, InputIt last ) {

				
				size_type distance = 0;
				for (InputIt tmp = first; tmp != last; ++tmp ) {
					++distance;
				}
				
				this->reserve( distance );
				for ( size_type i = 0; first != last; ++i, ++first ) {

					this->_self_construct( this->begin() + i, *first );
				}
				if (this->_size > distance) {
					for ( size_type i = 0; i < (this->_size - distance); ++i)
						this->_alctr.destroy( this->_arr + i );
				}
				this->_size = distance;

			};

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

			const_reference front( void ) const {

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

			/*************************
			* @iterators
			* ***********************/
			iterator begin(void) {

				return iterator( this->_arr, this->_arr + this->_size, 0 );
			};
			iterator end(void) {

				return iterator( this->_arr, this->_arr + this->_size, this->_size );
			};
			const_iterator begin(void) const {

				return const_iterator( iterator( this->_arr, this->_arr + this->_size, 0 ) );
			};
			const_iterator end(void) const {

				return const_iterator( iterator( this->_arr, this->_arr + this->_size, this->_size ) );
			};
			/*************************
			* @reverse iterators
			* ***********************/

			reverse_iterator rbegin(void) {

				return reverse_iterator( this->end() );
			}
			reverse_iterator rend(void) {

				return reverse_iterator( this->begin() );
			}

			const_reverse_iterator rbegin(void) const {

				return reverse_iterator( this->begin() );
			}
			const_reverse_iterator rend(void) const {

				return reverse_iterator( this->end() );
			}

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

				value_type *new_arr = copy_arr( new_cap, this->_arr, this->_size );
				for ( size_type i = 0; i < this->_size; ++i)
					this->_alctr.destroy( this->_arr + i );
				this->_safe_deallocate( this->_arr, this->_capacity );
				this->_arr = new_arr;
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
			iterator insert( iterator pos, const T& value ) {

				//in case of reallocation
				difference_type diff = pos - this->begin();
				this->_verify_capacity( 1 );
				pos = this->begin() + diff;

				this->_alctr.construct( &*this->end(), *(this->end() - 1) );
				this->_move_array_forward( pos, this->end(), pos + 1);
				this->_size++;
				*pos = value;

				return (pos);
			};

			void insert( iterator pos, size_type count, const T& value ) {

				if ( pos > this->end() || pos < this->begin() )
					throw ( std::length_error("vector::insert") );
				//in case of reallocation
				size_type index = pos - this->begin();
				this->_verify_capacity(count);
				iterator new_pos = this->begin() + index;

				this->_move_array_forward( new_pos, this->end(), new_pos + count );
				for ( size_type i = 0; i < count; ++i ) {
					this->_self_construct( new_pos + i, value );
				}
				this->_size += count;
			};

			template< class InputIt >
			typename ft::enable_if<!ft::is_integral<InputIt>::value>::type
			insert( iterator pos, InputIt first, InputIt last ) {

				difference_type distance = _get_distance( first, last );
				difference_type index = pos - this->begin();
				this->_verify_capacity(distance);
				iterator new_pos = this->begin() + index;

				this->_move_array_forward( new_pos, this->end(), new_pos + distance );
				for (; first != last; ++first, ++new_pos ) {
					this->_self_construct( new_pos, *first );
				}
				this->_size += distance;
			};

			/*************************
			* @erase
			* ***********************/

			//check must be *(possible)
			//i added a security to avoid unitialized
			//access that is not here on stl,
			//i assume its a undefined behaviour
			iterator erase( iterator pos ) {

				return this->erase(pos, pos + 1);
			};

			//if first == last, do nothing
			iterator erase( iterator first, iterator last ) {

				if ( !(first > this->end() || first < this->end() || first == this->end()) ) {
					this->_size--;
					return first;
				}
				if ( !(last > this->end() || last < this->end() || last == this->end()) ) {
					this->_size--;
					return first;
				}

				difference_type distance_beg = first - this->begin();
				this->_move_array_backward( last, this->end(), this->begin() + distance_beg );
				size_type new_s = this->_size - static_cast<size_type>( last - first );
				for ( size_type i = 0; i < (this->_size - new_s); ++i ) {
					this->_alctr.destroy( &*( this->begin() + new_s + i ) );
				}
				this->_size = new_s;
				return this->begin() + distance_beg;
			};

			/*************************
			* @resize
			* ***********************/
			void resize( size_type count, T value = T() ) {

				if ( count > ( 2 * this->size() ) ) 
					this->reserve(count);
				else if ( count > this->capacity() )
					this->reserve( 2 * this->size() );

				if ( count > this->_size ) {
					
					size_type to_add = count - this->size();
					for (size_type i = 0; i < to_add; i++)
					{
						this->_alctr.construct( &*(this->end() + i), value );
					}
				}
				else {

					for ( iterator it = this->begin() + count; it != this->end(); ++it )
						this->_alctr.destroy( &*it );
				}

				this->_size = count;
			};
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

			/* ************************************************************************** */
			/*                                                                            */
			/*            @swap                                                           */
			/*                                                                            */
			/* ************************************************************************** */
			void	swap( vector& other ) {

				T* 			tmp_arr = other.data();
				size_type	tmp_capacity = other.capacity();
				size_type	tmp_size = other.size();

				other._arr = this->_arr; 
				other._capacity = this->_capacity; 
				other._size = this->_size; 

				this->_arr = tmp_arr; 
				this->_capacity = tmp_capacity; 
				this->_size = tmp_size; 
			}
	};
	
};

#include "lexicographical_compare.hpp"

namespace ft {

	/* ************************************************************************** */
	/*                                                                            */
	/*            @COMPARAISON                                                    */
	/*                                                                            */
	/* ************************************************************************** */

	template< class T, class Alloc >
		bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
		{
			return !(ft::lexicographical_compare( 
						lhs.begin(), lhs.end(),
						rhs.begin(), rhs.end() 
					)) && 
					!(ft::lexicographical_compare( 
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
			return ( ft::lexicographical_compare( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() ) );
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