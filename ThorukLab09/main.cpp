#include<iostream>
#include<cmath>
#include"Dichotomy.h"

using namespace std;

using FPtr = double(*)(double);
const double PI = 3.14159265358979;
const double EPS = 0.00001;

double f1(double x) {
	return sin(x) - x;
}
double f2(double x) {
	return sin(x);
}
double f3(double x) {
	return log(x) - 1;
}
double f4(double x) {
	return exp(x) - 2 + x;
}

void main() {
	FPtr f[] = { f1, f2, f3, f4 };
	try {
		cout << "Examples: " << endl;
		cout << "F1[-1, 1]: " << dichotomy(f1, -1, 1, EPS) << endl;
		cout << "F2[PI-1, PI]: " << dichotomy(f2, PI - 1, PI, EPS) << endl;
		cout << "F3[2, 3]: " << dichotomy(f3, 2, 3, EPS) << endl;
		cout << "F4[0, 2]: " << dichotomy(f4, 0, 2, EPS) << endl;
		while (true) {
			int fun, a, b;
			cout << "Function: ";
			cin >> fun;
			cout << "A: ";
			cin >> a;
			cout << "B: ";
			cin >> b;
			if (fun < 1 || fun > 4) {
				cout << "Function 1 - 4" << endl;
				continue;
			}
			cout << "F" << fun << "[" << a << ", " << b << "]: " << dichotomy(fun[f-1], a, b, EPS) << endl;
		}
	}
	catch (const char* exp) {
		cout << exp << endl;
	}
}