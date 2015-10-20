/****************************************************************
* Author:				David Barnes
* Date Created:			10/19/15
* Last Modification Date:	10/19/15
* Lab Number:			CST 211 Lab 1
* Filename:				Board.h
*
* Overview: This is the header file for the Board class.
*			This file contains the class declarations.
*
*
*    Input: The size of the board and the number of mines.
*
*   Output: N/A
*****************************************************************/
#include"Array2D.h"
#include"Cell.h"

#ifndef Board_H
#define Board_H

class Board
{
public:
	Board();

	Board(int row, int col, int mines);

	Board(const Board &rhs);

	~Board();

	void fillBoard(int mines);

	void copy(const Board &rhs);

	Board &operator=(const Board &rhs);

	void draw();

	void click(int row, int col);

	void mark(int row, int col);

	bool isEmpty(int row, int col);

	bool operator==(const Board &rhs);

	bool operator!=(const Board &rhs);

	char gameWon();

	Array2D<Cell>* getBoard() const { return m_game; }
	int getMines() const { return m_mines; }
	int getRow() const { return m_row; }
	int getCol() const { return m_col; }

private:

	Array2D<Cell> *m_game;
	int m_mines;
	int m_row;
	int m_col;
};

#endif