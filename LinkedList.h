/****************************************************************
* Author:				David Barnes
* Date Created:			10/16/15
* Last Modification Date:	10/18/15
* Lab Number:			CST 211 Assignment 3
* Filename:				LinkedList.h
*
* Overview: This is the header file for the linked list class.
*			This file contains the class declarations.
*
*
*    Input: The inputs to create the Linked list object is two node
*			objects.
*
*   Output: N/A
*****************************************************************/

#include"Iterator.h"

#ifndef LinkedList_H
#define LinkedList_H

template<class T>
class LinkedList
{
	public:
		// default constructor
		LinkedList();
	
		// constructor
		LinkedList(T *data);

		// copy constructor
		LinkedList(const LinkedList &rhs);

		// default destructor
		~LinkedList();

		// override for == operator
		bool operator==(const LinkedList &rhs);

		// override for the != operator
		bool operator!=(const LinkedList &rhs);

		// override for the assignment operator
		LinkedList<T> &operator=(const LinkedList &rhs);

		// check to see if the list is empty
		bool isEmpty();

		// return the head pointer
		Node<T>& first() const { return *m_head; }

		// return the tail pointer
		Node<T>& last() const { return *m_tail; }

		// add a node to the head of the list
		void prepend(T *data);

		// add a node to the tail of the list
		void append(T *data);

		// remove all nodes from the list
		void purge();

		// remove a single node from the list
		Node<T>& extract(T nn);

		// insert a node after the specified node
		void insertAfter(T on, T *data);

		// insert a node before the specified node
		void insertBefore(T on, T *data);

		// create an iterator containing the head node
		Iterator<T> begin();

		//create an iterator containing the tail pointer
		Iterator<T> end();

	private:

		Node<T> *m_head;
		Node<T> *m_tail;
};
#include"LinkedList.inc"
#endif