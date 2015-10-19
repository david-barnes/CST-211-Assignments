/****************************************************************
* Author:				David Barnes
* Date Created:			10/16/15
* Last Modification Date:	10/18/15
* Lab Number:			CST 211 Assignment 3
* Filename:				Node.h
*
* Overview: This is the header file for the Node class.
*			This file contains the class declarations.
*
*
*    Input: The input to create the node is some data input.
*
*   Output: N/A
*****************************************************************/

#ifndef Node_H
#define Node_H

template<class T>
class Node
{
	public:

		// default constructor
		Node();

		// constructor
		Node(T *data);

		// copy constructor
		Node(const Node &rhs);

		// destructor
		~Node();

		// creates a copy
		void copy(const Node &rhs);

		// override for == operator
		bool operator==(const Node<T> &rhs);

		// override for the != operator
		bool operator!=(const Node<T> &rhs);

		// override for the assignment operator
		Node<T> &operator=(const Node &rhs);

		// return m_data
		T* getData() const { return m_data; }

		// set m_data
		void setData(T *data);

		// set next node
		void setNext(Node *nn);

		// return next node
		Node<T>* getNext() const { return m_next; }

		// set previous node
		void setPrev(Node *nn);

		// return previous node
		Node<T>* getPrev() const { return m_prev; }

	private:

		T *m_data;
		Node<T> *m_next;
		Node<T> *m_prev;
};

#include"Node.inc"
#endif