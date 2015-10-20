/****************************************************************
* Author:				David Barnes
* Date Created:			10/17/15
* Last Modification Date:	10/19/15
* Lab Number:			CST 211 Lab 1
* Filename:				Cell.h
*
* Overview: This is the header file for the Cell class.
*			This file contains the class declarations.
*
*
*    Input: 
*
*   Output: N/A
*****************************************************************/

#ifndef Cell_H
#define Cell_H

class Cell
{
	public:

		Cell();

		Cell(char data);

		Cell(const Cell &rhs);

		Cell &operator=(const Cell &rhs);

		bool operator==(const Cell &rhs);

		bool operator!= (const Cell &rhs);

		void copyCell(const Cell &rhs);

		char getData() const { return m_data; }

		void setData(char data);

		bool isCovered() const { return m_covered; }

		void covered(bool t_f);

		bool isMarked() const { return m_marked; }

		void marked(bool t_f);

		bool isEmpty() const { return m_empty; }

		void empty(bool t_f);

	private:

		char m_data;
		bool m_covered;
		bool m_marked;
		bool m_empty;
};

#endif