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

	// get exception thrown
	Exception getException() const { return xcept; }

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
#include"Array.inc"
#endif
