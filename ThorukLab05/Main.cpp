#include<iostream>

#include"Horner.h"

using namespace std;

void main() {
	const int size = 10;
	double arr[size], x;
	fillArray(arr, size);
	cout << "x: ";
	cin >> x;
	cout << "sum: " << sum(arr, size, x) << endl;
	cout << "horner: " << Horner(arr, size, x) << endl;
}