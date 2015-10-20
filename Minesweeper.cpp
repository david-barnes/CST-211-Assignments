/****************************************************************
* Author:				David Barnes
* Date Created:			10/19/15
* Last Modification Date:	10/19/15
* Lab Number:			CST 211 Lab 1
* Filename:				Minesweeper.h
*
* Overview: This is the header file for the Minesweeper class.
*			This file contains the class definitions.
*
*
*    Input: N/A
*
*   Output: N/A
*****************************************************************/
#include<iostream>
#include<string>
#include"Minesweeper.h"

using namespace std;
Minesweeper::Minesweeper()
{}

Minesweeper::Minesweeper(const Minesweeper &rhs)
{
	m_gameBoard = rhs.getBoard();
}

Minesweeper::~Minesweeper()
{
	delete m_gameBoard;
}

bool Minesweeper::operator==(const Minesweeper &rhs)
{
	return (*this).getBoard() == rhs.getBoard();
}

bool Minesweeper::operator!=(const Minesweeper &rhs)
{
	return !((*this) == rhs);
}

Minesweeper &Minesweeper::operator=(const Minesweeper &rhs)
{
	if (*this != rhs)
	{
		delete m_gameBoard;

		m_gameBoard = rhs.getBoard();
	}
	return *this;
}

void Minesweeper::run()
{
	bool play = true;
	char win = 0;
	int row, col;
	char dummy;
	char choice;
	char type;

	while (play == true)
	{
		cout << "b for Beginner" << endl << "i for Intermediate" << endl << "e for Expert" << endl;
		cout << "What size game would you like to play?" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 'b')
		{
			m_gameBoard = new Board(10, 10, 10);
		}
		else if (choice == 'i')
		{
			m_gameBoard = new Board(16, 16, 40);
		}
		else if (choice == 'e')
		{
			m_gameBoard = new Board(16, 30, 100);
		}

		while (win == 0)
		{
			(*m_gameBoard).draw();
			cout << "Would you like to click or flag." << endl << "Enter c for click and f for flag, or enter q to quit: ";
			cin >> type;
			if (type == '~')
			{
				win = 'w';
				break;
			}
			else if (type == 'q')
			{
				win = 'l';
				break;
			}
			cout << "Enter your choice in the form of: x, y" << endl;
			cout << "Rows are 1 - " << (*m_gameBoard).getRow() << " Columns are 1 - " << (*m_gameBoard).getCol() << endl;
			cout << "Enter the location you would like to try: ";
			cin >> row;
			cin >> dummy;
			cin >> col;

			row--;
			col--;

			if (type == 'f')
			{
				(*m_gameBoard).mark(row, col);
			}
			else if (type == 'c')
			{
				(*m_gameBoard).click(row, col);
			}

			win = (*m_gameBoard).gameWon();
		}

		(*m_gameBoard).draw();

		if (win == 'w')
		{
			cout << "Congratulations you won!" << endl;
		}
		else if (win == 'l')
		{
			cout << "Sorry you lost.";
		}

		cout << "Would you like to play again; y or n: ";
		cin >> choice;

		if (choice == 'y')
		{
			play = true;
			win = 0;
		}
		else
		{
			play = false;
		}
	}
}