/****************************************************************
* Author:				David Barnes
* Date Created:			10/18/15
* Last Modification Date:	10/18/15
* Lab Number:			CST 211 Assignment 3
* Filename:				driver.cpp
*
* Overview: This is the driver file for assignment 3.
*
*
*
*    Input:
*
*   Output: N/A
*****************************************************************/
#include"LinkedList.h"
#include<iostream>
using namespace std;

int main()
{
int a = 5;
int *b = new int;
*b = a;
int c = 7;
int *d = new int;
*d = c;
int f = 6;
int *g = new int;
*g = f;
int h = 4;
int *i = new int;
*i = h;
int e = 0;
LinkedList<int> *list = new LinkedList<int>(b);
(*list).append(d);
(*list).insertAfter(5, g);
(*list).insertBefore(5, i);

for (Iterator<int> i = (*list).begin(); i != 0; i++)
{
	e++;
}
cout << e << endl;

(*list).extract(5);

for (Iterator<int> i = (*list).begin(); i != 0; i++)
{
	e--;
}
cout << e << endl;

(*list).purge();
return 0;
}