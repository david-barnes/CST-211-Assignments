/****************************************************************
* Author:				David Barnes
* Date Created:			10/2/15
* Last Modification Date:	10/3/15
* Lab Number:			CST 211 Assignment 1
* Filename:				Exception.h
*
* Overview: This is the source file for the dynamic Exception class.
*			This file contains the class definitions.
*
*
*    Input: The inputs to create the Exception objects are a character
*			string.
*
*   Output: To determine what the exception that was thrown.
*****************************************************************/

#include"Exception.h"
#include<iostream>
#include<cstring>
using namespace std;

/**************************************************************
*   Entry:  character string 
*
*    Exit:  sets the m_msg variable to the character string specified
*			by the program.
*
* Purpose:  Sets the m_msg variable
*
***************************************************************/
void Exception::setMessage(char *msg)
{
	strcpy(m_msg, msg);
}

/**************************************************************
*   Entry:  Character string
*
*    Exit:  Checks to see if memory allocation succeded and calls the
*			setMessage function.
*
* Purpose:  Create Exception objects
*
*Exceptions: If memory allocation fails a message pops up saying so and
*			aborts the program.
***************************************************************/
Exception::Exception(char* msg) : m_msg(new char[strlen(msg)+1])
{
	if (!m_msg)     /* Validate successful allocation*/
	{
		cout << "Memory Allocation failed" << endl << "Aborting program";
		abort();
	}
	setMessage(msg);
}

/**************************************************************
*   Entry:  Exception object
*
*    Exit:  Checks to see if memory allocation succeded and calls the
*			setMessage function.
*
* Purpose:  Copy exception objects
*
*Exceptions: If memory allocation fails a message pops up saying so and
*			aborts the program.
***************************************************************/
Exception::Exception(const Exception &rhs) : m_msg(new char[strlen(rhs.m_msg) + 1])
{
	if (!m_msg)     /* Validate successful allocation*/
	{
		cout << "Memory Allocation failed" << endl << "Aborting program";
		abort();
	}
	setMessage(rhs.m_msg);
}

/**************************************************************
*   Entry:  None
*
*    Exit:  Deletes the exception object
*
* Purpose:  Delete Exception objects
*
***************************************************************/
Exception::~Exception()
{
	delete[] m_msg;
}

/**************************************************************
*   Entry:  Exception object
*
*    Exit:  Deletes the characterstring and creates a new one.
*			Checks to see if memory allocation succeded and calls the
*			setMessage function.
*
* Purpose:  Assign exception objects
*
*Exceptions: If memory allocation fails a message pops up saying so and
*			aborts the program.
***************************************************************/
Exception &Exception::operator=(const Exception &rhs)
{
	delete[] m_msg;

	m_msg = new char[strlen(rhs.m_msg) + 1];

	if (!m_msg)     /* Validate successful allocation */
	{
		cout << "Memory Allocation failed" << endl << "Aborting program"; 
		abort();
	}

	setMessage(rhs.m_msg);

	return *this;
}

/**************************************************************
*   Entry:  Ostream and Exception object
*
*    Exit:  Displays the character string stored in m_msg
*
* Purpose:  Output exception objects.
*
***************************************************************/
ostream &operator<<(ostream &os, const Exception &rhs)
{
	return os << rhs.getMessage();
}