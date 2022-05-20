#include<iostream>
#include<cmath>
#include"simpson.h"

using namespace std;

double f(double x) {
	double a = 5, b = 10;
	return 1 / sqrt((a * a * sin(x) * sin(x)) + (b * b * cos(x) * cos(x)));
};

void main() {
	const double PI = 3.14159265359;
	const double eps = 0.0000001;
	cout.precision(10);
	double a = 5, b = 10 , m;
	double sim = (2/PI)*Simpson(0, PI/2, eps, f);
	do {
		m = a;
		a = sqrt(a * b);
		b = (m + b) / 2;
	} while (a < b && a > 0 && m < a);
	cout << "Simpson(5, 10): " << sim << endl;
	cout << "M(5, 10): " << 1/m << endl;
}