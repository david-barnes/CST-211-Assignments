/****************************************************************
* Author:				David Barnes
* Date Created:			10/17/15
* Last Modification Date:	10/18/15
* Lab Number:			CST 211 Assignment 3
* Filename:				Iterator.h
*
* Overview: This is the header file for the Iterator class.
*			This file contains the class declarations.
*
*
*    Input: The input to create the iterator is a node pointer.
*
*   Output: N/A
*****************************************************************/
#include"Node.h"

#ifndef Iterator_H
#define Iterator_H

template<class T>
class Iterator
{
	public:

		// default constructor
		Iterator();

		// constructor
		Iterator(Node<T> *ptr);

		// copy constructor
		Iterator(const Iterator &rhs);

		// default destructor
		~Iterator();

		// override for == operator
		bool operator==(const Iterator<T> &rhs);

		// override for the != operator
		bool operator!=(const Iterator<T> &rhs);

		// copy function
		void copy(const Iterator &rhs);

		// override for the ++ prefix operator
		Iterator<T> &operator++();

		// override for the ++ postfix operator
		Iterator<T> operator++(int);

		// override for the -- prefix operator
		Iterator<T> &operator--();

		// override for the -- prefix operator
		Iterator<T> operator--(int);

		// override for the assigment operator
		Iterator<T> &operator=(const Iterator &rhs);

		// get node pointer
		Node<T>* getNode() const { return m_node; }

	private:

		Node<T> *m_node;
};
#include"Iterator.inc"
#endif