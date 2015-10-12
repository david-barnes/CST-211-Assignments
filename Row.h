/****************************************************************
* Author:				David Barnes
* Date Created:			10/9/15
* Last Modification Date:	10/9/15
* Lab Number:			CST 211 Assignment 2
* Filename:				Row.h
*
* Overview: This is the header file for the Row class.
*			This file contains the class declarations.
*
*
*    Input: The inputs to create the Row objects are an Array2D object and
*			a row.
*
*   Output: N/A
*****************************************************************/

#ifndef Row_H
#define Row_H

template<class T>
class Array2D;

template<class T>
class Row
{
	public:

		// Constructor that creates the row object
		Row(const Array2D<T> &temp, int row);

		// override for the [] operator used to access the colum
		T &operator[](const int col);

		// override for the [] operator for const objects
		const T &operator[](const int col) const;

	private:

		
		const Array2D<T> &m_array2D;
		
		mutable int m_row;

		// checks to see if the colum input is valid
		bool isValidColumn(const int idx) const;
};

#include"Row.inc"
#endif