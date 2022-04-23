/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:40:37 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/23 15:39:53 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef REDBLACKTREE_HPP
#	define REDBLACKTREE_HPP

template < class T >
class DataType {
	private:
		DataType() : 
			data( NULL ), 
			_compare(NULL)
		{};
		
	public:
		T 	data;
		bool (*_compare)( T a, T b );

		DataType( const DataType& rhs ) : 
			data( rhs.data ),
			_compare( rhs._compare )
		{};

		DataType( const T &data, bool (*compare)( T a, T b ) ) : 
			data( T( data ) ),
			_compare( compare )
		{};
		
		~DataType() {
		};
		DataType &operator=( const DataType& rhs ) {
			this->data = rhs.data;
			return *this;
		};

		DataType &operator=( T* data ) { 
			this->data = data;
			return *this;
		};

		/*************************
		* @comparaison
		* ***********************/
	
		bool operator<( const DataType& b ) { 

			return !_compare(this->data, b.data); 
		}
		
		bool operator>( const DataType& b ) {
			
			return !_compare(b.data, this->data);
		}

		bool operator==( const DataType& b ) { 
			
			return ( !this->operator>(b) && !this->operator<(b) );
		};
	
		bool operator!=( const DataType& b ) { return !( this->operator==(b) ); };

		bool operator<=( const DataType& b ) { return ( this->operator==(b) || this->operator<(b) ); };
};

template < class Data >
class Node {
	public:
		Data data;
		Node *parent;
		Node *left;
		Node *right;
		int	color;

		Node( Data data ) : data(data) {};

		bool operator==( const Node& rhs ) {

			return (
				data == rhs.data &&
				parent == rhs.parent &&
				left == rhs.left &&
				right == rhs.right &&
				color == rhs.color
			);
		}
		bool operator!=( const Node& rhs ) {

			return !( this->operator==(rhs) );
		}
};

template < class T, class Allocator >
class RedBlackTree {
	private:
		typedef DataType<T>		data_t;
		typedef Node<data_t>	node_t; 
		typedef node_t			*NodePtr;

		Allocator				_alctr;
	protected:
		bool 					(*_compare)( T a, T b );
	private:
		NodePtr 				root;
		node_t					tnull_stack;
		NodePtr 				TNULL;

		/*************************
		* @utils
		* ***********************/
		typedef typename Allocator::template rebind<node_t>::other	node_allocator_type;
		NodePtr _constructNode( data_t data ) {

			node_t				node_value( data );
			node_allocator_type	node_allocator;
			NodePtr	node = node_allocator.allocate(1);
			node_allocator.construct(node, node_value);
			return node;
		}

		// Post order
		void postOrderFree(NodePtr node) {
			if (node != TNULL) {
				postOrderFree(node->left);
				postOrderFree(node->right);

				node_allocator_type	node_allocator;
				node_allocator.destroy(node);
				node_allocator.deallocate(node, 1);
			}
		}

		NodePtr searchTreeHelper(NodePtr node, data_t& key) {

			if (node == TNULL || node->data == key) {
				return node;
			}

			if (node->data > key) {
				return searchTreeHelper(node->left, key);
			}
			return searchTreeHelper(node->right, key);
		}

  		// For balancing the tree after deletion
  		void deleteFix(NodePtr x) {
			NodePtr s;
			while (x != root && x->color == 0) {
				if (x == x->parent->left) {
					s = x->parent->right;
					if (s->color == 1) {
						s->color = 0;
						x->parent->color = 1;
						leftRotate(x->parent);
						s = x->parent->right;
					}

				if (s->left->color == 0 && s->right->color == 0) {
					s->color = 1;
					x = x->parent;
					} else {
						if (s->right->color == 0) {
							s->left->color = 0;
							s->color = 1;
							rightRotate(s);
							s = x->parent->right;
						}

						s->color = x->parent->color;
						x->parent->color = 0;
						s->right->color = 0;
						leftRotate(x->parent);
						x = root;
					}
					} else {
						s = x->parent->left;
						if (s->color == 1) {
						s->color = 0;
						x->parent->color = 1;
						rightRotate(x->parent);
						s = x->parent->left;
					}

					if (s->right->color == 0 && s->right->color == 0) {
						s->color = 1;
						x = x->parent;
					} else {
					if (s->left->color == 0) {
						s->right->color = 0;
						s->color = 1;
						leftRotate(s);
						s = x->parent->left;
					}
	
					s->color = x->parent->color;
					x->parent->color = 0;
					s->left->color = 0;
					rightRotate(x->parent);
					x = root;
					}
				}
			}
		x->color = 0;
 		}

	void rbTransplant(NodePtr u, NodePtr v) {
		
		if (u->parent == NULL) {
			root = v;
		} else if (u == u->parent->left) {
			u->parent->left = v;
		} else {
			u->parent->right = v;
		}
		v->parent = u->parent;
	}

  	void deleteNodeHelper( NodePtr node ) {

		NodePtr z = node;
		NodePtr x, y;

		y = z;
		int y_original_color = y->color;
		if (z->left == TNULL) {
			x = z->right;
			rbTransplant(z, z->right);
		} else if (z->right == TNULL) {
			x = z->left;
			rbTransplant(z, z->left);
		} else {
			y = minimum(z->right);
			y_original_color = y->color;
			x = y->right;
			if (y->parent == z) {
				x->parent = y;
			} else {
				rbTransplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}

			rbTransplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		delete z;
		if (y_original_color == 0) {
			deleteFix(x);
		}
  	}

  	// For balancing the tree after insertion
  	void insertFix(NodePtr k) {
		NodePtr u;
		while (k->parent->color == 1) {
			if (k->parent == k->parent->parent->right) {
				u = k->parent->parent->left;
				if (u->color == 1) {
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				} else {
					if (k == k->parent->left) {
						k = k->parent;
						rightRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					leftRotate(k->parent->parent);
				}
			} else {
				u = k->parent->parent->right;

				if (u->color == 1) {
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				} else {
					if (k == k->parent->right) {
						k = k->parent;
						leftRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					rightRotate(k->parent->parent);
				}
			}
			if (k == root) {
				break;
			}
		}
		root->color = 0;
 	}

	void printHelper(NodePtr root, std::string indent, bool last) {
		if (root != TNULL) {
			std::cout << indent;
			if (last) {
				std::cout << "R----";
				indent += "   ";
			} else {
				std::cout << "L----";
				indent += "|  ";
			}

			std::string sColor = root->color ? "RED" : "BLACK";
			std::cout << root->data << "(" << sColor << ")" << std::endl;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
		}
	}
	RedBlackTree() {}

	public:
		~RedBlackTree(void) {
			
			cleanTree();
		}

		/*************************
		* @constructor
		* ***********************/

		RedBlackTree( bool (*compare)( T a, T b ) ) : 
			_alctr( Allocator() ),
			_compare( compare ),
			tnull_stack( data_t( T(), this->_compare ) )
		{
			this->tnull_stack.color = 0;
			this->tnull_stack.left = NULL;
			this->tnull_stack.right = NULL;
			
			this->TNULL = &tnull_stack;
			root = TNULL;
		}

		RedBlackTree( const RedBlackTree& ref ) :
			_alctr( ref.get_alloc() ),
			_compare( ref._compare ),
			tnull_stack( data_t( T(), ref._compare ) )
		{
			this->tnull_stack.color = 0;
			this->tnull_stack.left = NULL;
			this->tnull_stack.right = NULL;
			
			this->TNULL = &tnull_stack;
			root = TNULL;
		}

	protected:
		Allocator get_alloc(void) const {
			return this->_alctr;
		}

	public:

		void cleanTree() {
			postOrderFree(this->root);
			this->root = TNULL;
		}

		//return null in case key doesnt exist
		NodePtr searchTree( const T& k ) {
			data_t data_key(k, this->_compare);
			NodePtr ptr = searchTreeHelper(this->root, data_key);
			if ( ptr == TNULL )
				return NULL;
			return ( ptr );
		}

		NodePtr minimum(NodePtr node) const {
			while (node->left != TNULL) {
				node = node->left;
			}
			return node;
		}

		NodePtr maximum(NodePtr node) const {
			while (node->right != TNULL) {
				node = node->right;
			}
			return node;
		}

		NodePtr successor(NodePtr x) const {
			if (x == NULL) {
				return NULL;
			}
			
			if (x->right != TNULL) {
				return minimum(x->right);
			}

			NodePtr y = x->parent;
			while (y != NULL && y != TNULL && x == y->right) {
				x = y;
				y = y->parent;
			}
			return y;
		}

		NodePtr predecessor(NodePtr x) const {
			if (x == NULL) {
				return NULL;
			}

			if (x->left != TNULL) {
				return maximum(x->left);
			}

			NodePtr y = x->parent;
			while (y != NULL && y != TNULL && x == y->left) {
				x = y;
				y = y->parent;
			}

			return y;
		}

		void leftRotate(NodePtr x) {

			NodePtr y = x->right;
			x->right = y->left;
			if (y->left != TNULL) {
				y->left->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL) {
				this->root = y;
			} else if (x == x->parent->left) {
				x->parent->left = y;
			} else {
				x->parent->right = y;
			}
			y->left = x;
			x->parent = y;
		}

		void rightRotate(NodePtr x) {

			NodePtr y = x->left;
			x->left = y->right;
			if (y->right != TNULL) {
				y->right->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL) {
				this->root = y;
			} else if (x == x->parent->right) {
				x->parent->right = y;
			} else {
				x->parent->left = y;
			}
			y->right = x;
			x->parent = y;
		}

		// Inserting a node
		// we assume the key doesnt already exist
		NodePtr insert(T data) {

			data_t dt(data, this->_compare);
			NodePtr node = this->_constructNode( dt );
			node->parent = NULL;

			node->data._compare = this->_compare;
			
			node->left = TNULL;
			node->right = TNULL;
			node->color = 1;
			
			NodePtr y = NULL;
			NodePtr x = this->root;

			while (x != TNULL) {
				y = x;
				if (node->data < x->data) {
					x = x->left;
				} else {
					x = x->right;
				}
			}

			node->parent = y;
			if (y == NULL) {
				this->root = node;
			} else if (node->data < y->data) {
				y->left = node;
			} else {
				y->right = node;
			}

			if (node->parent == NULL) {
				node->color = 0;
				return node;
			}

			if (node->parent->parent == NULL) {
				return node;
			}

			insertFix(node);
			return node;
		}

		NodePtr getRoot() const {
			return this->root;
		}

		void deleteNode( NodePtr node ) {
			deleteNodeHelper( node );
		}

		NodePtr getBegin() const {
			if (this->root == TNULL)
				return NULL;
			return this->minimum( this->root );
		}

		NodePtr getEnd() const {
			if (this->root == TNULL)
				return NULL;
			return this->maximum( this->root );
		}

		//used to swap 2 trees
		void swapRoot( NodePtr otherRoot ) {
			NodePtr tmpRoot = otherRoot;
			this->root = otherRoot;
			otherRoot = tmpRoot;
		}
};

#endif