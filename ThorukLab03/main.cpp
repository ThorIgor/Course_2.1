#include <iostream>

#include"Functions.h"

using namespace std;

void main()
{
	int base;
	cout << "Base: ";
	cin >> base;
	cout << "numbers_double: " << numbers_double(base) << endl;
	cout << "numbers_float: " << numbers_float(base) << endl;
	cout.precision(5);
	for (int i = 1; i <= 10; i++) 
		cout << i << "\t";
	cout << endl;
	for (int i = 1; i <= 10; i++)
		cout << gaus(i, 0.001) << "\t";
	cout << endl;
	for (int i = 1; i <= 10; i++)
		cout << eksp(i, 0.001) << "\t";
}