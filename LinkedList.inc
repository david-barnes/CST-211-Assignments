/****************************************************************
* Author:				David Barnes
* Date Created:			10/17/15
* Last Modification Date:	10/18/15
* Lab Number:			CST 211 Assignment 3
* Filename:				LinkedList.h
*
* Overview: This is the template file for the linked list class.
*			This file contains the class declarations.
*
*
*    Input: The input to create the Linked list object is a node
*			objects.
*
*   Output: N/A
*****************************************************************/

/**************************************************************
*   Entry:  Node to be compared.
*
*    Exit:  Compares the two nodes.
*
* Purpose:  Compare Node objects.
*
***************************************************************/
template<class T>
bool LinkedList<T>::operator==(const LinkedList<T> &rhs)
{
	return (*this).first() == rhs.first() && (*this).last() == rhs.last();
}

/**************************************************************
*   Entry:  Node to be compared.
*
*    Exit:  Compares the two nodes.
*
* Purpose:  Compare Node objects.
*
***************************************************************/
template<class T>
bool LinkedList<T>::operator!=(const LinkedList<T> &rhs)
{
	return !((*this) == rhs);
}

/**************************************************************
*   Entry:  LinkedList object
*
*    Exit:  Assigns a Linked list object to another.
*
* Purpose:  Assign Linked list objects.
*
***************************************************************/
template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList &rhs)
{
	if (*this != rhs)
	{
		*m_head = rhs.first();
		*m_tail = rhs.last();
	}
	return *this;
}

/**************************************************************
*   Entry:  Data
*
*    Exit:  Sets the head and tail pointers.
*
* Purpose:  Instantiate linked list objetcs.
*
***************************************************************/
template<class T>
LinkedList<T>::LinkedList()
{
	m_head = 0;
	m_tail = m_head;
}

/**************************************************************
*   Entry:  Data 
*
*    Exit:  Sets the head and tail pointers.
*
* Purpose:  Instantiate linked list objetcs.
*
***************************************************************/
template<class T>
LinkedList<T>::LinkedList(T *data)
{
	m_head = new Node<T>(data);
	m_tail = m_head;
}

/**************************************************************
*   Entry:  N/A
*
*    Exit:  Checks to see if the list is empty.
*
* Purpose:  To see if the list is empty.
*
***************************************************************/
template<class T>
bool LinkedList<T>::isEmpty()
{
	if (m_head == null)
	{
		return true;
	}
	else
		return false;
}

/**************************************************************
*   Entry:  Linked list to be copied
*
*    Exit:  Makes a copy of the linked list.
*
* Purpose:  Make a copy.
*
***************************************************************/
template<class T>
LinkedList<T>::LinkedList(const LinkedList &rhs)
{
	*m_head = rhs.first();
	*m_tail = rhs.last();
}

/**************************************************************
*   Entry:  Node that the user entered
*
*    Exit:  Adds new node to the front of the list.
*
* Purpose:  Adds a new node.
*
***************************************************************/
template<class T>
void LinkedList<T>::prepend(T *data)
{
	Node<T> *nn = new Node<T>(data);
	
	(*nn).setNext(m_head);

	m_head = nn;
}

/**************************************************************
*   Entry:  Node that the user entered
*
*    Exit:  Adds new node to the end of the list.
*
* Purpose:  Adds a new node.
*
***************************************************************/
template<class T>
void LinkedList<T>::append(T *data)
{
	Node<T> *nn = new Node<T>(data);

	(*nn).setPrev(m_tail);

	last().setNext(nn);

	m_tail = nn;
}

/**************************************************************
*   Entry:  N/A
*
*    Exit:  Creates and returns an iterator object.
*
* Purpose:  Create and return an iterator object.
*
***************************************************************/
template<class T>
Iterator<T> LinkedList<T>::begin()
{
	Iterator<T> temp(m_head);

	return temp;
}

/**************************************************************
*   Entry:  N/A
*
*    Exit:  Creates and returns an iterator object.
*
* Purpose:  Create and return an iterator object.
*
***************************************************************/
template<class T>
Iterator<T> LinkedList<T>::end()
{
	Iterator<T> temp(m_tail);

	return temp;
}

/**************************************************************
*   Entry:  N/A
*
*    Exit:  Removes all nodes from the list.
*
* Purpose:  Remove all nodes.
*
***************************************************************/
template<class T>
void LinkedList<T>::purge()
{
	for (Iterator<T> i = (*this).begin(); i != 0;)
	{
		Node<T> *pDel = 0;

		pDel = m_head;

		m_head = (*i.getNode()).getNext();
		
		++i;

		delete pDel;
	}
}

/**************************************************************
*   Entry:  Data to be extracted.
*
*    Exit:  Removes a node from the list.
*
* Purpose:  Remove a node.
*
***************************************************************/
template<class T>
Node<T>& LinkedList<T>::extract(T nn)
{
	for (Iterator<T> i = (*this).begin(); i != 0; ++i)
	{
		if ((*(*i.getNode()).getData()) == nn)
		{
			(*(*i.getNode()).getPrev()).setNext((*i.getNode()).getNext());

			(*(*i.getNode()).getNext()).setPrev((*i.getNode()).getPrev());

			return (*i.getNode());
		}
	}
}

/**************************************************************
*   Entry:  Data and the location it is to be added .
*
*    Exit:  Adds a node to the list after the specified data.
*
* Purpose:  Add data to the list.
*
***************************************************************/
template<class T>
void LinkedList<T>::insertAfter(T on, T *data)
{
	for (Iterator<T> i = (*this).begin(); i != 0; ++i)
	{
		if (*(*i.getNode()).getData() == on)
		{
			Node<T> *nn = new Node<T>(data);

			(*nn).setPrev(i.getNode());

			(*nn).setNext((*i.getNode()).getNext());

			(*(*i.getNode()).getNext()).setPrev(nn);

			if (i.getNode() != 0)
			{
				(*i.getNode()).setNext(nn);
			}

			if (i.getNode() == m_tail)
			{
				m_tail = nn;
			}
		}
	}
}

/**************************************************************
*   Entry:  Data and the location it is to be added .
*
*    Exit:  Adds a node to the list after the specified data.
*
* Purpose:  Add data to the list.
*
***************************************************************/
template<class T>
void LinkedList<T>::insertBefore(T on, T *data)
{
	for (Iterator<T> i = (*this).begin(); i != 0; ++i)
	{
		if (*(*i.getNode()).getData() == on)
		{
			Node<T> *nn = new Node<T>(data);

			(*nn).setNext(i.getNode());

			(*nn).setPrev((*i.getNode()).getPrev());

			if ((*i.getNode()).getPrev() != 0)
			{
				(*(*i.getNode()).getPrev()).setNext(nn);
			}
			(*i.getNode()).setPrev(nn);

			if (i.getNode() == m_head)
			{
				m_head = nn;
			}
		}
	}
}

/**************************************************************
*   Entry:  N/A
*
*    Exit:  N/A
*
* Purpose:  Destruct LinkedList objects.
*
***************************************************************/
template<class T>
LinkedList<T>::~LinkedList()
{
	purge();
	delete (*this);
}