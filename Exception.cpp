//
// Assignment  :  #1
// Class       :  CST 211
//
// Author      :  David Barnes
//
// File        :  Array.h
//
//

#include"Exception.h"
#include<iostream>
#include<cstring>
using namespace std;

void Exception::setMessage(char *msg)
{
	strcpy(m_msg, msg);
}

Exception::Exception(char* msg) : m_msg(new char[strlen(msg)+1])
{
	if (!m_msg)     /* Validate successful allocation*/
	{
		cout << "Memory Allocation failed" << endl << "Aborting program";
		abort();
	}
	setMessage(msg);
}

Exception::Exception(const Exception &rhs) : m_msg(new char[strlen(rhs.m_msg) + 1])
{
	if (!m_msg)     /* Validate successful allocation*/
	{
		cout << "Memory Allocation failed" << endl << "Aborting program";
		abort();
	}
	setMessage(rhs.m_msg);
}

Exception::~Exception()
{
	delete[] m_msg;
}

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

ostream &operator<<(ostream &os, const Exception &rhs)
{
	return os << rhs.getMessage();
}