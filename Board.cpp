/****************************************************************
* Author:				David Barnes
* Date Created:			10/19/15
* Last Modification Date:	10/19/15
* Lab Number:			CST 211 Lab 1
* Filename:				Board.h
*
* Overview: This is the source file for the Board class.
*			This file contains the class definitions.
*
*
*    Input: The size of the board and the number of mines.
*
*   Output: N/A
*****************************************************************/

#include"Board.h"
#include"Cell.cpp"
#include<cstdlib>
#include<time.h>
#include<iostream>

using namespace std;

Board::Board()
{
	m_game = new Array2D<Cell>();
	m_mines = 0;
}

Board::~Board()
{}

bool Board::isEmpty(int row, int col)
{
	if ((*m_game)[row][col].isEmpty())
	{
		return true;
	}
	else
		return false;

}

void Board::fillBoard(int mines)
{
	srand(time(0));
	int row, col;

	while (mines != 0)
	{
		row = rand() % m_row;
		col = rand() % m_col;

		if (isEmpty(row, col))
		{
			(*m_game)[row][col].setData('*');

			mines--;
		}
	}

	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			char mine = '0';

			if ((*m_game)[i][j].isEmpty())
			{
				if (i > 0)
				{
					if ((*m_game)[i - 1][j].getData() == '*')
					{	mine++;	}
					if (j > 0)
					{
						if ((*m_game)[i - 1][j - 1].getData() == '*')
						{	mine++;	}
						if (j < m_col)
						{
							if ((*m_game)[i - 1][j + 1].getData() == '*')
							{	mine++;	}
						}
					}
				}
				if (j > 0)
				{
					if ((*m_game)[i][j - 1].getData() == '*')
					{	mine++;	}
				}
				if (j < m_col)
				{
					if ((*m_game)[i][j + 1].getData() == '*')
					{	mine++;	}
				}
				if (i < m_row - 1)
				{
					if ((*m_game)[i + 1][j].getData() == '*')
					{	mine++;	}
					if (j > 0)
					{
						if ((*m_game)[i + 1][j - 1].getData() == '*')
						{	mine++;	}
						if (j < m_col)
						{
							if ((*m_game)[i + 1][j + 1].getData() == '*')
							{	mine++;	}
						}
					}
				}
			}
			if (mine > '0')
			{
				(*m_game)[i][j].setData(mine);
			}
		}
	}
}

Board::Board(int row, int col, int mines)
{
	m_game = new Array2D<Cell>(row, col);
	m_mines = mines;
	m_row = row;
	m_col = col;
	fillBoard(mines);
}

void Board::copy(const Board &rhs)
{
	m_game = rhs.getBoard();
	m_mines = rhs.getMines();
	m_row = rhs.getRow();
	m_col = rhs.getCol();
}

Board::Board(const Board &rhs)
{
	copy(rhs);
}


void Board::click(int row, int col)
{
	bool click = false;
	(*m_game)[row][col].covered(click);
}

void Board::mark(int row, int col)
{
	(*m_game)[row][col].marked(true);
}

void Board::draw()
{
	system("CLS");
	char output = 0;
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			if ((*m_game)[i][j].isCovered())
			{
				output = '#';
				if ((*m_game)[i][j].isMarked())
				{
					output = '?';
				}
			}
			else
			{
				if ((*m_game)[i][j].isEmpty())
				{
					output = ' ';
				}
				else
				{
					output = (*m_game)[i][j].getData();
				}
			}
			cout << output;
		}
		cout << endl;
	}
	cout << "Legend: ? = flagged	* = mine	" << endl;
}

char Board::gameWon()
{
	int won = 0;

	for (int i = 0; i < getRow(); i++)
	{
		for (int j = 0; j < getCol(); j++)
		{
			if (!(*m_game)[i][j].isCovered())
			{
				if (!(*m_game)[i][j].isEmpty())
				{
					if ((*m_game)[i][j].getData() == '*')
					{
						return 'l';
					}
					else
					{
						won++;
					}
				}
			}
		}
	}

	if (won == (getRow() * getCol() - getMines()))
	{
		return 'w';
	}
	else
	{
		return 0;
	}
}