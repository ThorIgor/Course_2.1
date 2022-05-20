#include <iostream>

using namespace std;

const double E = 2.71828;

int numbers_double(int base) {
	double xx, x = 1;
	int count = 0;
	do {
		xx = x;
		x *= base;
		count++;
	} while (x != xx);
	return --count;
}

int numbers_float(int base) {
	float xx, x = 1;
	int count = 0;
	do {
		xx = x;
		x *= base;
		count++;
	} while (x != xx);
	return --count;
}

double gaus(double x, double eps) {
	double sum = 0, psum;
	int i = 1;
	do {
		psum = sum;
		double xx = 1, fac = 1;
		for (int j = 0; j < 2 * i + 1; j++)
			xx *= x;
		for (int j = 1; j <= 2 * i - 1; j++)
			fac *= j;
		sum += xx / ((2 * static_cast<double>(i) + 1) * fac);
		i++;
	} while (sum - psum > eps);
	return sum;
}

double eksp(double x, double eps) {
	if (x == 0)
		return 1;
	int wx = abs(x); //whole x
	double fx = abs(x) - wx; //fractional x
	double eksp = 1;
	for (int i = 0; i < wx; i++)
		eksp *= E;
	double feksp = 1;
	if (fx != 0)
	{
		feksp = fx * E;
		double t;
		do {
			t = feksp;
			feksp = (feksp + E / feksp) * fx;
		} while ((abs(feksp - t) / feksp) > eps);
	}
	if (x > 0)
		return eksp * feksp;
	else
		return 1 / (eksp * feksp);

}