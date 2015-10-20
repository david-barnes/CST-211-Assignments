/****************************************************************
* Author:				David Barnes
* Date Created:			10/17/15
* Last Modification Date:	10/19/15
* Lab Number:			CST 211 Lab 1
* Filename:				Minesweeper.h
*
* Overview: This is the header file for the Minesweeper class.
*			This file contains the class declarations.
*
*
*    Input: The size of the board and the number of mines.
*
*   Output: N/A
*****************************************************************/
#include"Board.h"

#ifndef Minesweeper_H
#define Minesweeper_H

class Minesweeper
{
	public:
		Minesweeper();
	
		Minesweeper(const Minesweeper &rhs);
	
		~Minesweeper();
	
		Minesweeper &operator=(const Minesweeper &rhs);

		bool operator==(const Minesweeper &rhs);

		bool operator!=(const Minesweeper &rhs);

		void run();

		Board* getBoard() const { return m_gameBoard; }
	
	private:

		Board *m_gameBoard;
};

#endif