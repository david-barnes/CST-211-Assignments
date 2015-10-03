/****************************************************************
* Author:				David Barnes
* Date Created:			10/2/15
* Last Modification Date:	10/3/15
* Lab Number:			CST 211 Assignment 1
* Filename:				Exception.h
*
* Overview: This is the header file for the dynamic Exception class.
*			This file contains the class declarations.
*
*    Input: The inputs to create the Exception objects are a character
*			string.
*
*   Output: To determine what the exception that was thrown.
*****************************************************************/

#include<iostream>
using namespace std;

#ifndef  Exception_H
#define  Exception_H


class Exception
{
	// override for the operator<< 
	friend ostream &operator<<(ostream &os, const Exception &rhs);

	public:

		// Default Constructor
		Exception();

		// Constructor
		Exception(char *msg);

		// Copy Constructor
		Exception(const Exception &rhs);

		// Destructor
		~Exception();

		// override for operator=
		Exception &operator=(const Exception &rhs);

		// gets the m_msg variable
		char* getMessage() const { return m_msg; }

		// sets the m_msg variable
		void setMessage(char *msg);

	private:

		char *m_msg;
};

#endif