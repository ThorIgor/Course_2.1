#include<iostream>
#include"Sort.h"

using namespace std;

void main() {
	double arr[] = { 2, 5, 7, 3, 5, 9, 0, 2, 5, 1};
	double arr1[] = { 2, 5, 7, 3, 5, 9, 0, 2, 5, 1 };
	double arr2[] = { 3, 5, 7, 3, 5, 9, 0, 2, 5, 1 };
	sort(arr, 10);
	for (double a : arr)
		cout << a << " ";
	cout << endl;
	if (sorted(arr1, arr, 10))
		cout << "Arr is sorted Arr1" << endl;
	if (sorted(arr2, arr, 10))
		cout << "Arr is sorted Arr2" << endl;
}