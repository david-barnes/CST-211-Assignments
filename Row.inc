/****************************************************************
* Author:				David Barnes
* Date Created:			10/10/15
* Last Modification Date:	10/11/15
* Lab Number:			CST 211 Assignment 2
* Filename:				Row.h
*
* Overview: This is the template file for the Row class.
*			This file contains the class definitions.
*
*
*    Input: The inputs to create the Row objects are an Array2D object and
*			a row.
*
*   Output: N/A
*****************************************************************/

/**************************************************************
*   Entry:  Row and column that the user entered
*
*    Exit:  Sets the m_row and m_col variables, calls the memory function,
*			and sets all elements in the array to 0.
*
* Purpose:  Instantiate array2D objects.
*
***************************************************************/
template<class T>
Row<T>::Row(const Array2D<T> &temp, int row) : m_row(row), m_array2D(temp)
{}

/**************************************************************
*   Entry:  Index entry to be checked
*
*    Exit:  Checks to see if the array index the user entered is
*			within bounds of the array.
*
* Purpose:  See if the array index the user entered is valid.
*
*Exceptions: If the index entered by the user is smaller than 0, or
*			if the index entered is larger than m_col
*			then an upperbound exception is thrown.
*
***************************************************************/
template<class T>
bool Row<T>::isValidColumn(const int idx) const
{
	if (idx < 0)
	{
		m_array2D.getException() = "Lowerbound exception";
		throw m_array2D.getException();
		return false;
	}
	else if (idx > m_array2D.getColumn())
	{
		m_array2D.getException() = "Upperbound Exception";
		throw m_array2D.getException();
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
*    Exit: Calls the isValid function to see if the column is within
*			the array. Then calls and returns the Select function.
*
* Purpose:  Access array elements.
*
***************************************************************/
template<class T>
T &Row<T>::operator[](const int col)
{
	if (isValidColumn(col))
	{
		return m_array2D.Select(m_row, col);
	}
		
}

/**************************************************************
*   Entry:  Array index entered by the user
*
*    Exit: Calls the isValid function to see if the row is within
*			the array. Then calls and returns the Select function.
*
* Purpose:  Access array elements for const array2D objects.
*
***************************************************************/
template<class T>
const T &Row<T>::operator[](const int col) const
{
	if (isValidColumn(col))
	{
		return m_array2D.Select(m_row, col);
	}
}