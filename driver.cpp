/****************************************************************
* Author:				David Barnes
* Date Created:			10/10/15
* Last Modification Date:	10/11/15
* Lab Number:			CST 211 Assignment 2
* Filename:				driver.cpp
*
* Overview: This is the test file to see if my Exception and Array objects work.
*
*    Input:
*
*   Output:
*****************************************************************/

#include"Array2D.h"
#include<iostream>

using namespace std;

int main()
{
	Array2D<int> A(3, 4);

	cout << "A's number of rows is " << A.getRow() << endl;

	cout << "A's number of columns is " << A.getColumn() << endl;

	A[2][3] = 5;

	cout << "A[2][3] = " << A[2][3] << endl;


	cout << "A[2][3] = " << A[2][3] << endl;

	Array2D<int> B = A;

	cout << "B's number of rows is " << B.getRow() << endl;

	cout << "B's number of columns is " << B.getColumn() << endl;

	cout << "B[2][3] = " << B[2][3] << endl;

	const Array2D<int> C = B;

	cout << "C's number of rows is " << C.getRow() << endl;

	cout << "C's number of columns is " << C.getColumn() << endl;

	cout << "C[2][3] = " << C[2][3] << endl;

	try
	{
		cout << "trying to set the value of 10 to A[4][2]" << endl;
		A[4][2] = 10;
	}
	catch (Exception)
	{
		cout << "An exception of type " << A.getException() << " was thrown." << endl;
	}

	try
	{
		cout << "trying to set the value of 10 to A[2][5]" << endl;
		A[2][5] = 10;
	}
	catch (Exception)
	{
		cout << "An exception of type " << A.getException() << " was thrown." << endl;
	}

	system("pause");

	return 0;
}