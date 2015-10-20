/****************************************************************
* Author:				David Barnes
* Date Created:			10/17/15
* Last Modification Date:	10/19/15
* Lab Number:			CST 211 Lab 1
* Filename:				Cell.inc
*
* Overview: This is the source file for the Cell class.
*			This file contains the class definitions.
*
*
*    Input:
*
*   Output: N/A
*****************************************************************/
#include"Minesweeper.h"

Cell::Cell()
{
	m_data = 0;
	m_empty = true;
	m_covered = true;
	m_marked = false;
}

Cell::Cell(char data)
{
	m_data = data;
	m_empty = false;
	m_covered = true;
	m_marked = false;
}

void Cell::setData(char data)
{
	m_data = data;
	m_empty = false;
}

void Cell::covered(bool t_f)
{
	m_covered = t_f;
}

void Cell::marked(bool t_f)
{
	m_marked = t_f;
}

void Cell::empty(bool t_f)
{
	m_empty = t_f;
}

void Cell::copyCell(const Cell &rhs)
{
	setData(rhs.getData());
	covered(rhs.isCovered());
	marked(rhs.isMarked());
	empty(rhs.isEmpty());
}

Cell::Cell(const Cell &rhs)
{
	copyCell(rhs);
}

bool Cell::operator==(const Cell &rhs)
{
	return (*this).getData() == rhs.getData() && (*this).isCovered() == rhs.isCovered() && (*this).isMarked() == rhs.isMarked()
		&& (*this).isEmpty() == rhs.isEmpty();
}

bool Cell::operator!=(const Cell &rhs)
{
	return !((*this) == rhs);
}

Cell &Cell::operator=(const Cell &rhs)
{
	if (*this != rhs)
	{
		copyCell(rhs);
	}
	return *this;
}