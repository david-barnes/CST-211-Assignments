/****************************************************************
* Author:				David Barnes
* Date Created:			10/9/15
* Last Modification Date:	10/19/15
* Lab Number:			CST 211 Lab 1
* Filename:				Array2D.h
*
* Overview: This is the header file for the dynamic two dimensional array class.
*			This file contains the class declarations.
*
*
*    Input: The inputs to create the array objects are a row
*			and colum, and then what ever the user wants to fill
*			the array with.
*
*   Output: N/A
*****************************************************************/

#include"Exception.h"
#include"Row.h"
#ifndef  Array2D_H
#define  Array2D_H

template<class T>
class Array2D
{
public:

	// Constructor that creates array2D objects
	Array2D(int row = 0, int col = 0);

	// Copy Constructor
	Array2D(const Array2D &rhs);

	// Destructor
	~Array2D();

	// override for the [] operator
	Row<T> operator[](const int idx);

	// override for the [] operator for const arrays
	const Row<T> operator[](const int idx) const;

	// override for the = operator to allow array2D objects to be set to other array2D objects
	T &operator=(const T &rhs);

	// used to get the m_row variable
	int getRow() const { return m_row; }

	// used to set the number of rows
	void setRow(int row);

	// used to get the m_col variable
	int getColumn() const { return m_col; }

	// used to set the number of colums variable
	void setColumn(int col);

	// used to select a cell in the array
	T &Select(int row, int col) const;

	// get exception thrown
	Exception getException() const { return xcept; }

private:

	mutable T **m_array;

	mutable int m_row;

	mutable int m_col;

	mutable Exception xcept = "";

	// reallocates memory for new 2D array
	void memory(int row, int col);

	// does the actual copying for the copy constructor, allows the copy constructor to be called
	void copy(const Array2D &rhs);

	// checks to see if the row input is valid 
	bool isValidRow(const int idx) const;

};
#include"Array2D.inc"
#endif
