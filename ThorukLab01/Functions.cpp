#include<iostream>

using namespace std;

const double EPSILON = 0.01;
const double PI = 3.1415926;

long Fact(long num) {
	if (num == 0)
		return 1;
	if (num == 1)
		return 1;
	return Fact(num - 1) * num;
}

double Pov(double x, double n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	int w = n;			// whole 
	double f = n - w;	// fractional
	if (n < 0)
		return 1 / pow(x, -n);
	else
	{
		double s = 1;
		if (f != 0)
		{
			s = f * x;
			double t;
			do
			{
				t = s;
				s = (s + x / s) * f;
			} while ((abs(s - t) / s) > EPSILON);
		}
		return pow(x, w - 1) * x * s;
	}
}

double Sin(double x)
{
	while (x >= PI || x <= -PI)
	{
		if (x >= 2 * PI)
			x -= 2 * PI;
		if (x <= -2 * PI)
			x += 2 * PI;
		if (x >= PI && x <= 2*PI)
			x = -2 * PI + x;
		if (x <= -PI && x >= -2 * PI)
			x = 2 * PI - x;
	}
	double f, s = 0;
	int i = 0;
	do {
		f = s;
		f = s;
		double dop = 1;
		if (i % 2 == 1)
			dop *= -1;
		for (int j = 0; j < 2 * i+1; j++)
			dop *= x;
		double fac = 1;
		for (int j = 1; j <= 2 * i+1; j++)
			fac *= j;
		s += dop / fac;
		i++;
	} while (abs(s - f) > EPSILON);
	return s;
}

double Cos(double x)
{
	while (x >= PI || x <= -PI)
	{
		if (x >= 2 * PI)
			x -= 2 * PI;
		if (x <= -2 * PI)
			x += 2 * PI;
		if (x >= PI && x <= 2 * PI)
			x = -2 * PI + x;
		if (x <= -PI && x >= -2 * PI)
			x = 2 * PI - x;
	}
	double f, s = 0;
	int i = 0;
	do {
		f = s;
		double dop = 1;
		if (i % 2 == 1)
			dop *= -1;
		for (int j = 0; j < 2 * i; j++)
			dop *= x;
		double fac = 1;
		for (int j = 1; j <= 2 * i; j++)
			fac *= j;
		s += dop/fac;
		i++;
	} while (abs(s - f) > EPSILON);
	return s;
}