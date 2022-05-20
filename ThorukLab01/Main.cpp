#include<iostream>
#include"Functions.h"

using namespace std;

int main() {

	int f;
	cout << "Factorial:";
	cin >> f;
	cout << f << "!=" << Fact(f) << endl;

	double x, n;
	cout << "x^n:" << endl;
	cout << "x=";
	cin >> x;
	cout << "n=";
	cin >> n;
	cout << x << "^" << n << "=" << Pov(x, n) << endl;

	cout << "Sin:";
	cin >> x;
	cout << "sin(" << x << ")=" << Sin(x) << endl;

	cout << "Cos:";
	cin >> x;
	cout << "cos(" << x << ")=" << Cos(x) << endl;
	return 0;
}