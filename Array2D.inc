/****************************************************************
* Author:				David Barnes
* Date Created:			10/9/15
* Last Modification Date:	10/11/15
* Lab Number:			CST 211 Assignment 2
* Filename:				Array2D.inc
*
* Overview: This is the template file for the dynamic two dimensional array class.
*			This file contains the class definitions.
*			
*
*    Input: The inputs to create the array objects are a row, column,
*			and then what ever the user wants to fill the array with.
*
*   Output: N/A
*****************************************************************/

/**************************************************************
*   Entry:  row and column that are to be used to create a new 2D array
*
*    Exit:  Creates a new 2D array and maintains the contents of the
*			old array
*
* Purpose:  Create a new 2D array
*
*Exceptions: If memory allocation fails a bad memory allocation is thrown.
*
***************************************************************/
template<class T>
void Array2D<T>::memory(int row, int col)
{
	m_array = new T * [row];

	if (!m_array)     /* Validate successful allocation */
	{
		xcept = "Bad Memory Allocation";
		throw xcept;
	}

	for (int i = 0; i < m_row; i++)
	{
		m_array[i] = new T[col];
	}
}

/**************************************************************
*   Entry:  column that the user entered
*
*    Exit:  sets the m_col variable to the value specified
*			by the user and calls the memory function.
*
* Purpose:  Sets the m_col variable
*
***************************************************************/
template<class T>
void Array2D<T>::setColumn(int col) 
{
	m_col = col;

	memory(m_row, col);
}

/**************************************************************
*   Entry:  column that the user entered
*
*    Exit:  sets the m_col variable to the value specified
*			by the user and calls the memory function.
*
* Purpose:  Sets the m_col variable
*
***************************************************************/
template<class T>
void Array2D<T>::setRow(int row) 
{
	m_row = row;

	memory(row, m_col);
}

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
Array2D<T>::Array2D(int row, int col) : m_row(row), m_col(col)
{
	memory(m_row, m_col);
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
void Array2D<T>::copy(const Array2D &rhs)
{
	m_row = rhs.getRow();

	m_col = rhs.getColumn();

	memory(m_row, m_col);

	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_array[i][j] = rhs.m_array[i][j];
		}
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
Array2D<T>::Array2D(const Array2D &rhs)
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
Array2D<T>::~Array2D()
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
*Exceptions: If the index entered by the user is smaller than 0, or
*			if the index entered is larger than m_row
*			then an upperbound exception is thrown.
*
***************************************************************/
template<class T>
bool Array2D<T>::isValidRow(const int idx) const
{
	if (idx < 0)
	{
		xcept = "Lowerbound exception";
		throw xcept;
		return false;
	}
	else if (idx > m_row)
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
*    Exit: Calls the isValid function to see if the row is within
*			the array. Then creates and returns a Row object.
*
* Purpose:  Access array elements.
*
***************************************************************/
template<class T>
Row<T> Array2D<T>::operator[](const int idx)
{
	if (isValidRow(idx))
	{
		Row<T> rowObj(*this, idx);

		return rowObj;
	}
		
}

/**************************************************************
*   Entry:  Array index entered by the user
*
*    Exit: Calls the isValid function to see if the row is within
*			the array. Then creates and returns a Row object.
*
* Purpose:  Access array elements for const array2D objects.
*
***************************************************************/
template<class T>
const Row<T> Array2D<T>::operator[](const int idx) const
{
	if (isValidRow(idx))
	{
		Row<T> rowObj(*this, idx);

		return rowObj;
	}
}

/**************************************************************
*   Entry:  Array2D object
*
*    Exit: Checks to see if the array on the left is equal to the 
*			array on the right, then clears the array object and creates
*			a copy of the object on the right and assigns it to the object
*			on the left.
*
* Purpose:  Assign array2D objects to other array2D objects.
*
***************************************************************/
template<class T>
T &Array2D<T>::operator=(const T &rhs)
{
	if (this != &rhs)
	{
		delete[] m_array;

		copy(rhs);
	}
	return *this;
}

/**************************************************************
*   Entry:  row and column of cell to be accessed
*
*    Exit: returns the element at the specified row and column.
*
* Purpose:  Access array elements for const array2D objects.
*
***************************************************************/
template<class T>
T &Array2D<T>::Select(int row, int col) const
{
	return m_array[row][col];
}