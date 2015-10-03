//
// Assignment  :  #1
// Class       :  CST 211
//
// Author      :  David Barnes
//
// File        :  Exception.h
//
//

#include<iostream>
using namespace std;

#ifndef  Exception_H
#define  Exception_H


class Exception
{
	friend ostream &operator<<(ostream &os, const Exception &rhs);

	public:

		Exception();

		Exception(char *msg);

		Exception(const Exception &rhs);

		~Exception();

		Exception &operator=(const Exception &rhs);

		char* getMessage() const { return m_msg; }

		void setMessage(char *msg);

	private:

		char *m_msg;
};

#endif