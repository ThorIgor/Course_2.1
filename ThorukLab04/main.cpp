#include<iostream>
#include"Avg.h"

using namespace std;

void main() {
	double a, b;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	if (a < 0 || a > b) {
		cout << "Error" << endl;
		return;
	}
	cout.precision(50);
	cout << "M: " << M(a, b) << endl;
}