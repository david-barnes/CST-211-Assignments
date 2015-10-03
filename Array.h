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
#ifndef  Array_H
#define  Array_H

template<class T>
class Array
{
public:
	
	Array();

	Array(int length, int start_index = 0);

	Array(const Array &rhs);

	~Array();

	T &operator[](const int idx);

	const T &operator[](const int idx) const;

	T &operator=(const T &rhs);

	int getStartIndex() const { return m_start_index; }

	void setStartIndex(int start_index);

	int getLength() const { return m_length; }

	void setLength(int lentgh);

private:

	T *m_array;
	int m_start_index;
	int m_length;
	mutable Exception xcept = "";

	void copy(const Array &rhs);
	bool isValid(const int idx) const;

};

#endif



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

	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = 0;
	}
}

template<class T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

template<class T>
Array<T>::Array(int length, int start_index)
{
	setStartIndex(start_index);

	setLength(length);
}

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

template<class T>
Array<T>::Array(const Array &rhs)
{
	copy(rhs);
}

template<class T>
Array<T>::~Array()
{
	delete[] m_array;
}

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

template<class T>
T &Array<T>::operator[](const int idx)
{
	if (isValid(idx))
		return m_array[idx - m_start_index];
}

template<class T>
const T &Array<T>::operator[](const int idx) const
{
if (isValid(idx))
return m_array[idx - m_start_index];
}

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