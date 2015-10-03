/****************************************************************
* Author:				David Barnes
* Date Created:			10/2/15
* Last Modification Date:	10/3/15
* Lab Number:			CST 211 Assignment 1
* Filename:				Array.h
*
* Overview: This is the header file for the dynamic array class.
*			This file contains the class declarations and definitions.
*			
*
*    Input: The inputs to create the array objects are a length 
*			and starting index, and then what ever the user wants to fill
*			the array with.
*
*   Output: N/A
*****************************************************************/

#include"Exception.h"
#ifndef  Array_H
#define  Array_H

template<class T>
class Array
{
public:
	// Default Constructor
	Array();

	// Constructor that creates array objects
	Array(int length, int start_index = 0);

	// Copy Constructor
	Array(const Array &rhs);

	// Destructor
	~Array();

	// override for the [] operator
	T &operator[](const int idx);

	// override for the [] operator for const arrays
	const T &operator[](const int idx) const;

	// override for the = operator to allow array objects to be set to other array objects
	T &operator=(const T &rhs);

	// used to get the m_start_index variable
	int getStartIndex() const { return m_start_index; }

	// used to set the m_start_index variable
	void setStartIndex(int start_index);

	// used to get the m_length variable
	int getLength() const { return m_length; }

	// used to set the m_length variable
	void setLength(int lentgh);

private:

	T *m_array;
	int m_start_index;
	int m_length;
	mutable Exception xcept = "";

	// does the actual copying for the copy constructor, allows the copy constructor to be called
	void copy(const Array &rhs);

	// checks to see if the user input is valid
	bool isValid(const int idx) const;

};

#endif


/**************************************************************
*   Entry:  length that the user entered
*
*    Exit:  sets the m_length variable to the length specified
*			by the user.
*
* Purpose:  Sets the m_length variable
*
*Exceptions: If memory allocation fails a bad memory allocation is thrown,
*			and if the length entered by the user is below 0 
*			an invalid length exception will be thrown.
*
***************************************************************/
template<class T>
void Array<T>::setLength(int length)
{
	if (length > 0)
	{
		m_length = length;

		m_array = new T[m_length];

		if (!m_array)     /* Validate successful allocation */
		{
			xcept = "Bad Memory Allocation";
			throw xcept;
		}
	}
	else
	{
		xcept = "Invalid Length";
		throw xcept;
	}
}

/**************************************************************
*   Entry:  Starting index that the user entered
*
*    Exit:  sets the m_start_index variable to the value specified
*			by the user.
*
* Purpose:  Sets the m_start_index variable
*
***************************************************************/
template<class T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

/**************************************************************
*   Entry:  Starting index and length that the user entered
*
*    Exit:  Calls the setStartIndex and setLength functions, and
*			sets all elements in the array to 0.
*
* Purpose:  Instantiate array objects.
*
***************************************************************/
template<class T>
Array<T>::Array(int length, int start_index)
{
	setStartIndex(start_index);

	setLength(length);

	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = 0;
	}
}

/**************************************************************
*   Entry:  Array object to be copied
*
*    Exit:  Calls the setStartIndex and setLength functions, and
*			copies all the elements from the given array object into
*			the new array object.
*
* Purpose:  Copy array objects.
*
***************************************************************/
template<class T>
void Array<T>::copy(const Array &rhs)
{
	setStartIndex(rhs.getStartIndex());

	setLength(rhs.getLength());

	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = rhs.m_array[i];
	}
}

/**************************************************************
*   Entry:  Array object to be copied
*
*    Exit:  Calls the copy funtion 
*
* Purpose:  Copy array objects.
*
***************************************************************/
template<class T>
Array<T>::Array(const Array &rhs)
{
	copy(rhs);
}

/**************************************************************
*   Entry:  None
*
*    Exit:  Deletes the dynamic array
*
* Purpose:  Delete array objects.
*
***************************************************************/
template<class T>
Array<T>::~Array()
{
	delete[] m_array;
}

/**************************************************************
*   Entry:  Index entry to be checked
*
*    Exit:  Checks to see if the array index the user entered is
*			within bounds of the array.
*
* Purpose:  See if the array index the user entered is valid.
*
*Exceptions: If the index entered by the user is smaller than the
*			starting index then a lowerbound exception is thrown, and
*			if the index entered is larger than m_start_index + m_length
*			then an upperbound exception is thrown.
*
***************************************************************/
template<class T>
bool Array<T>::isValid(const int idx) const
{
	if (idx < m_start_index)
	{
		xcept = "Lowerbound exception";
		throw xcept;
		return false;
	}
	else if (idx >(m_start_index + m_length))
	{
		xcept = "Upperbound Exception";
		throw xcept;
		return false;
	}
	else
	{
		return true;
	}
}

/**************************************************************
*   Entry:  Array index entered by the user
*
*    Exit: Calls the isValid function to see if the index is within
*			the array. Then returns the element at the index entered
*
* Purpose:  Access array elements.
*
***************************************************************/
template<class T>
T &Array<T>::operator[](const int idx)
{
	if (isValid(idx))
		return m_array[idx - m_start_index];
}

/**************************************************************
*   Entry:  Array index entered by the user
*
*    Exit: Calls the isValid function to see if the index is within
*			the array. Then returns the element at the index entered
*
* Purpose:  Access array elements for const array objects.
*
***************************************************************/
template<class T>
const T &Array<T>::operator[](const int idx) const
{
if (isValid(idx))
return m_array[idx - m_start_index];
}

/**************************************************************
*   Entry:  Array object
*
*    Exit: Checks to see if the array on the left is equal to the 
*			array on the right, then clears the array object and creates
*			a copy of the object on the right and assigns it to the object
*			on the left.
*
* Purpose:  Assign array objects to other array objects.
*
***************************************************************/
template<class T>
T &Array<T>::operator=(const T &rhs)
{
	if (this != &rhs)
	{
		delete[] m_array;

		copy(rhs);
	}
	return *this;
}