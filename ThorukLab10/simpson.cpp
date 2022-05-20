#include<cmath>

double Simpson(const double a, const double b, const double eps,
	double(*f)(double)) {
	int n = 2; 
	double h = (b - a) * 0.5; 
	double ss = 0; 
	double s1 = h * (f(a) + f(b));
	double s2 = 0; 
	double s4 = 4 * h * f(a + h); 
	double s = s1 + s2 + s4;
	do {
		ss = s; 
		n *= 2; 
		h /= 2; 
		s1 *= 0.5; 
		s2 = 0.5 * s2 + 0.25 * s4; 
		s4 = 0; 
		int i = 1;
		do {
			s4 = s4 + f(a + i * h); 
			i += 2;
		} while (i <= n);
		s4 = 4 * h * s4; 
		s = s1 + s2 + s4;
	} while (fabs(s - ss) > eps);
	return s / 3;
}