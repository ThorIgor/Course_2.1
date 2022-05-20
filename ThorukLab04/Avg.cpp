#include <iostream>
#include <math.h>

using namespace std;

double M(double a, double b) {
	double pa, pb;
	for (int i = 0; i < INT_MAX; i++) {
		pa = a; pb = b;
		a = sqrt(pa * pb);
		b = (pa + pb) / 2;
	}
	cout << "A = " << a << endl;
	cout << "B = " << b << endl;
	return a;
}