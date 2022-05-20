#include<iostream>

using namespace std;

double dichotomy(double (*f)(double), double a, double b, double eps) {
	if (b < a) throw "a must be lower b";
	if ((f(a) < -eps && f(b) < -eps) || (f(a) > eps && f(b) > eps)) 
		throw "X do not exist";
	double mid, fmid;
	if (f(a) > f(b)) {
		do {
			mid = a + abs(a - b) / 2;
			fmid = f(mid);
			if (fmid < 0)
				b = mid;
			else
				a = mid;
		} while (!(abs(fmid) < eps));
	}
	else {
		do {
			mid = a + abs(a - b) / 2;
			fmid = f(mid);
			if (fmid > 0)
				b = mid;
			else
				a = mid;
		} while (!(abs(fmid) < eps));
	}
	return mid;
}