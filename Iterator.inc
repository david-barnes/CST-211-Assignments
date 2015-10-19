/****************************************************************
* Author:				David Barnes
* Date Created:			10/17/15
* Last Modification Date:	10/18/15
* Lab Number:			CST 211 Assignment 3
* Filename:				Iterator.cpp
*
* Overview: This is the template file for the Iterator class.
*			This file contains the class declarations.
*
*
*    Input: The input to create the iterator is a node pointer.
*
*   Output: N/A
*****************************************************************/

/**************************************************************
*   Entry:  Node pointer
*
*    Exit:  Sets the m_node variable.
*
* Purpose:  Sets the m_node variable.
*
***************************************************************/
template<class T>
Iterator<T>::Iterator(Node<T> *ptr)
{
	m_node = ptr;
}

/**************************************************************
*   Entry:  Iterator to be copied
*
*    Exit:  Creates a copy of the Iterator.
*
* Purpose:  Copy the Iterator object.
*
***************************************************************/
template<class T>
void Iterator<T>::copy(const Iterator &rhs)
{
	m_node = rhs.getNode();
}

/**************************************************************
*   Entry:  Iterator to be copied
*
*    Exit:  Creates a copy of the Iterator.
*
* Purpose:  Copy the Iterator object.
*
***************************************************************/
template<class T>
Iterator<T>::Iterator(const Iterator &rhs)
{
	copy(rhs);
}

/**************************************************************
*   Entry:  Two Iterator objects.
*
*    Exit:  Compares two Iterator objects.
*
* Purpose:  Compares two Iterator objects.
*
***************************************************************/
template<class T>
bool Iterator<T>::operator==(const Iterator<T> &rhs)
{
	return (*this).getNode() == rhs.getNode();
}

/**************************************************************
*   Entry:  Two Iterator objects.
*
*    Exit:  Compares two Iterator objects.
*
* Purpose:  Compares two Iterator objects.
*
***************************************************************/
template<class T>
bool Iterator<T>::operator!=(const Iterator<T> &rhs)
{
	return !((*this) == rhs);
}

/**************************************************************
*   Entry:  N/A
*
*    Exit:  Sets the Node pointer to the next node pointer of the node object.
*
* Purpose:  Sets the Node pointer to the next node pointer of the node object.
*
***************************************************************/
template<class T>
Iterator<T> &Iterator<T>::operator++()
{
	m_node = (*getNode()).getNext();

	return *this;
}

/**************************************************************
*   Entry:  N/A
*
*    Exit:  Sets the Node pointer to the next node pointer of the node object.
*
* Purpose:  Sets the Node pointer to the next node pointer of the node object.
*
***************************************************************/
template<class T>
Iterator<T> Iterator<T>::operator++(int)
{
	Iterator temp(*this);

	m_node = (*getNode()).getNext();

	return temp;
}

/**************************************************************
*   Entry:  N/A
*
*    Exit:  Sets the Node pointer to the previous node pointer of the node object.
*
* Purpose:  Sets the Node pointer to the previous node pointer of the node object.
*
***************************************************************/
template<class T>
Iterator<T> &Iterator<T>::operator--()
{
	m_node = (*getNode()).getPrev();

	return *this;
}

/**************************************************************
*   Entry:  N/A
*
*    Exit:  Sets the Node pointer to the previous node pointer of the node object.
*
* Purpose:  Sets the Node pointer to the previous node pointer of the node object.
*
***************************************************************/
template<class T>
Iterator<T> Iterator<T>::operator--(int)
{
	Iterator temp(*this);

	m_node = (*getNode()).getPrev();

	return temp;
}

/**************************************************************
*   Entry:  Node used to set another node
*
*    Exit:  Calls the copy function.
*
* Purpose:  Assign nodes to other nodes.
*
***************************************************************/
template<class T>
Iterator<T> &Iterator<T>::operator=(const Iterator &rhs)
{
	if (*this != rhs)
	{
		copy(rhs);
	}
	return *this;
}

/**************************************************************
*   Entry:  N/A
*
*    Exit:  N/A
*
* Purpose:  Destruct Iterator objects.
*
***************************************************************/
template<class T>
Iterator<T>::~Iterator()
{

}