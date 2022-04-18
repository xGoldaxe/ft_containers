/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:15:07 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/03 16:55:11 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.hpp"

template <
	typename T,
	typename Tree
>

class ft::map_iterator : public std::iterator
		<
			std::random_access_iterator_tag, //category
			T, //type
			std::ptrdiff_t, //difference 
			T*, //pointer
			T& // reference
		> 
	{
	public:
		/* ************************************************************************** */
		/*                                                                            */
		/*            @iterator traits                                                */
		/*                                                                            */
		/* ************************************************************************** */
		typedef map_iterator						iterator;
		typedef std::random_access_iterator_tag		iterator_category;
		typedef T									value_type;
		typedef std::ptrdiff_t						difference_type;
		typedef T*									pointer;
		typedef T&									reference;
	
	private:		
		typedef Tree*								tree_ptr;
		typedef Node<DataType<T> >					node_t;
		
		tree_ptr			_tree;
		node_t*				_actual;
	
	protected:
		/*************************
		* @some gettters
		* ***********************/
		tree_ptr getTree( void ) const {

			return ( this->_tree );
		}
		/* ************************************************************************** */
		/*                                                                            */
		/*            @utils                                                          */
		/*                                                                            */
		/* ************************************************************************** */
		void getSuccessor(void) {

			if (this->_actual == NULL)
				this->_actual = this->_tree->getBegin();
			else
				this->_actual = this->_tree->successor( this->_actual );
		}

		void getPredecessor(void) {

			if (this->_actual == NULL)
				this->_actual = this->_tree->getEnd();
			else
				this->_actual = this->_tree->predecessor( this->_actual );
		}

	public:
		/* ************************************************************************** */
		/*                                                                            */
		/*            @utils                                                          */
		/*                                                                            */
		/* ************************************************************************** */
		node_t* getActual( void ) const	{
		
			return ( this->_actual );
		}

		/* ************************************************************************** */
		/*                                                                            */
		/*            @LEGACY CONSTRUCTOR                                             */
		/*                                                                            */
		/* ************************************************************************** */
		
		/*************************
		* @default constructor
		* ***********************/
		map_iterator(void) :  _tree( NULL ), _actual( NULL ) {};

		/*************************
		* @parameter constructor
		* ( should be hided from final user )
		* ***********************/
		map_iterator( tree_ptr tree, node_t* actual ) :
			_tree( tree ) ,_actual( actual )
		{};
		
		/*************************
		* @copy constructor
		* ***********************/
		map_iterator( const map_iterator & reference ) :
			_tree( reference.getTree() ),
			_actual( reference.getActual() )
		{};

		/*************************
		* @copy assignement
		* ***********************/
		map_iterator &operator=( const map_iterator & rhs ) {

			this->_actual = rhs.getActual();
			this->_tree = rhs.getTree();
			return (*this);
		};

		/*************************
		* @destructor
		* ***********************/
		~map_iterator(void) {};

		/* ************************************************************************** */
		/*                                                                            */
		/*            @legacyOutput      _iterator                                    */
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
		bool	operator==( const map_iterator &b ) const {

			if ( ( this->_actual && b.getActual() && *this->_actual == *b.getActual() ) ||
					(this->_actual == NULL && b.getActual() == NULL) )
				return true;
			return false;
		};
		bool	operator!=( const map_iterator &b ) const {
			return ( !( this->operator==(b) ) );
		};

		/*************************
		* @casting the value to
		* control as much as possible
		* the end value, but still
		* remain a undefined behavior
		* ***********************/
		reference operator*(void) const {

			if (this->_actual == NULL)
				return *this->_tree->getRoot()->data.data;
			return ( *this->_actual->data.data );
		};
		/*************************
		* @i->m equivalent (*i).m
		* ***********************/
		value_type *operator->() const {

			if (this->_actual == NULL)
				return this->_tree->getRoot()->data.data;
			return ( this->_actual->data.data );
		};
		map_iterator& operator++(void) {

			this->getSuccessor();
			return ( *this );
		};
		/* ************************************************************************** */
		/*                                                                            */
		/*            @legacyForwardIterator                                          */
		/*                                                                            */
		/* ************************************************************************** */
		map_iterator operator++(int) {

			map_iterator tmp = *this;
			this->getSuccessor();
			return tmp;
		};

		/* ************************************************************************** */
		/*                                                                            */
		/*            @legacyBidirectionalIterator                                    */
		/*                                                                            */
		/* ************************************************************************** */
		/* past end map_iterator = undefined */
		map_iterator& operator--(void) {

			this->getPredecessor();
			return ( *this );
		};
		map_iterator operator--(int) {

			map_iterator tmp = *this;
			this->getPredecessor();
			return tmp;
		};		
};
