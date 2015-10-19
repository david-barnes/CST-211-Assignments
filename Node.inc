/****************************************************************
* Author:				David Barnes
* Date Created:			10/16/15
* Last Modification Date:	10/18/15
* Lab Number:			CST 211 Assignment 3
* Filename:				Node.inc
*
* Overview: This is the Template file for the Node class.
*			This file contains the class definitions.
*
*
*    Input: The input to create the node is some data.
*
*   Output: N/A
*****************************************************************/

/**************************************************************
*   Entry:  data that the user entered
*
*    Exit:  Sets the m_data variable.
*
* Purpose:  Instantiate Node objects.
*
***************************************************************/
template<class T>
Node<T>::Node(T *data)
{
	m_data = data;
}

/**************************************************************
*   Entry:  data that the user entered
*
*    Exit:  Sets the m_data variable.
*
* Purpose:  Sets the m_data variable.
*
***************************************************************/
template<class T>
void Node<T>::setData(T *data)
{
	m_data = data;
}

/**************************************************************
*   Entry:  Next node in the list
*
*    Exit:  Sets the m_next variable.
*
* Purpose:  Sets the m_next variable.
*
***************************************************************/
template<class T>
void Node<T>::setNext(Node *nn)
{
	m_next = nn;
}

/**************************************************************
*   Entry:  Previous node in the list
*
*    Exit:  Sets the m_prev variable.
*
* Purpose:  Sets the m_prev variable.
*
***************************************************************/
template<class T>
void Node<T>::setPrev(Node *nn)
{
	m_prev = nn;
}

/**************************************************************
*   Entry:  Node to be copied.
*
*    Exit:  takes the input and creates a copy
*
* Purpose:  Copy Node objects.
*
***************************************************************/
template<class T>
void Node<T>::copy(const Node &rhs)
{
	setData(rhs.getData());

	setNext(rhs.getNext());

	setPrev(rhs.getPrev());
}

/**************************************************************
*   Entry:  Node to be copied.
*
*    Exit:  Calls the copy function.
*
* Purpose:  Copy Node objects.
*
***************************************************************/
template<class T>
Node<T>::Node(const Node &rhs)
{
	copy(rhs);
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
bool Node<T>::operator==(const Node<T> &rhs)
{
	return (*this).getData() == rhs.getData();
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
bool Node<T>::operator!=(const Node<T> &rhs)
{
	return !((*this) == rhs);
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
Node<T> &Node<T>::operator=(const Node &rhs)
{
	if (this != &rhs)
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
* Purpose:  Destruct Node objects.
*
***************************************************************/
template<class T>
Node<T>::~Node()
{

}