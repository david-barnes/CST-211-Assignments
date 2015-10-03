//
// Assignment  :  #1
// Class       :  CST 211
//
// Author      :  David Barnes
//
// File        :  driver.cpp
//
//

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