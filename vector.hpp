/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:54:09 by pleveque          #+#    #+#             */
/*   Updated: 2022/03/31 21:13:07 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#	define VECTOR_HPP

#include <iostream>
#include <string>
#include <typeinfo>
#include "ft_namespace.hpp"
#include <memory>

template <
	typename T,
	typename Allocator = std::allocator<T>
>


class ft::vector
{
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
	/*?*/
	typedef value_type iterator;
	typedef const value_type const_iterator;
	/*?*/
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	private:
		Allocator 	_alctr;
		size_type	_size;
		T* 			_arr;

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
			_arr( this->_alctr.allocate( this->_size ) )
		{

			std::cout << "ft_vector created!" << std::endl;
		};
		
		/*************************
		* @ALLOC CONSTRUCTOR
		* ***********************/
		explicit vector( const Allocator& alloc ) :
			_alctr( alloc ),
			_size( 0 ),
			_arr( this->_alctr.allocate( this->_size ) )
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
			_arr( this->_alctr.allocate( _size ) )
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
			_arr( this->_alctr.allocate( _size ) )
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
			_arr( this->_alctr.allocate( _size ) )
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
			_alctr.deallocate( this->_arr, this->_size );
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
		reference at( size_type pos );

		const_reference at( size_type pos ) const;

		/*************************
		* @[] OPERATOR OVERLOAD
		* FOR ACCESS
		* ***********************/
		reference operator[]( size_type pos );

		const_reference operator[]( size_type pos ) const;

		/*************************
		* @FRONT ACCESS
		* ***********************/
		reference front();

		const_reference front() const;

		/*************************
		* @BACK ACCESS
		* ***********************/
		reference back();

		const_reference back() const;

};


#endif