#include "Horner.h"
#include<random>

void fillArray(double * coeff, size_t size)
{ 
	for (int i = 0; i < size; i++)
		*(coeff + i) = rand()%1000;
	return;
}

double Horner(double * coeff, size_t size, double x)
{
	if (size == 0)
		return 0;
	return (*coeff) + x * Horner(coeff + 1, size - 1, x);
}

double sum(double* coeff, size_t size, int sign)
{
	double result = 0, x = 1;
	for (int i = 0; i < size; i++) {
		result += (*(coeff + i)) * x;
		x *= sign;
	}
	return result;
}
