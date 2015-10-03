/****************************************************************
* Author:				David Barnes
* Date Created:			10/2/15
* Last Modification Date:	10/3/15
* Lab Number:			CST 211 Assignment 1
* Filename:				driver.cpp
*
* Overview: This is the test file to see if my Exception and Array objects work.
*
*    Input: 
*
*   Output: 
*****************************************************************/

#include"Array.h"
#include<iostream>

using namespace std;

int main()
{
	Array<int> A(10, 5);

	cout << "A start index is " << A.getStartIndex() << endl;

	cout << "A length is " << A.getLength() << endl;

	cout << "A[10] = " << A[10] << endl;

	A[10] = 5;

	cout << "A[10] = " << A[10] << endl;

	Array<int> B = A;

	cout << "B[10] = " << B[10] << endl;

	cout << "B start index is " << B.getStartIndex() << endl;

	cout << "B length is " << B.getLength() << endl;
	
	Exception xcept("Does this work");

	Exception yes("yes it does");

	cout << xcept << endl;

	xcept = yes;

	cout << xcept << endl;

	system("pause");

	return 0;
}