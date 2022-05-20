#include<iostream>
#include"Func.h"

using namespace std;

int zet(double& y, double& x, unsigned int& k)
{
	if (k > 0)
	{
		if (k % 2 == 1)
		{
			y *= x; k--;
		}
		else
		{
			x *= x; k /= 2;
		};
		return 1 + zet(y, x, k);
	}
	return 0;
}

double power(double x, unsigned int n)
{
	double y = 1;
	cout << "Count: " << zet(y, x, n) << endl;
	return y;
}

int fib(double& f1, double& f2, unsigned int n)
{
	if (n >= 2)
	{
		double f = f2; f2 += f1; f1 = f;
		return 1 + fib(f1, f2, n - 1);
	}
	return 0;
};

double Fibonaci(unsigned int n)
{
	double f0 = 0, f1 = 1;
	switch (n)
	{
	case 0:
		return f0; break;
	case 1:
		return f1; break;
	default:
		cout << "Count: " << fib(f0, f1, n) << endl;
		return f1;
	}
};

Matrix2x2 multM(const Matrix2x2& m1, const Matrix2x2& m2) {
	Matrix2x2 result;
	result._11 = m1._11 * m2._11 + m1._12 * m2._21;
	result._12 = m1._11 * m2._12 + m1._12 * m2._22;
	result._21 = m1._21 * m2._11 + m1._22 * m2._21;
	result._22 = m1._21 * m2._12 + m1._22 * m2._22;
	return result;
}

Matrix2x2 matrixPow(const Matrix2x2& matrix, const int& n) {
	if (n < 1)
		throw "Error";
	Matrix2x2 result = matrix;
	int count = 0;
	for (int i = 1; i < n; (i * 2 < n) ? i *= 2 : i++) {
		if (i * 2 < n)
			result = multM(result, result);
		else
			result = multM(result, matrix);
		count++;
	}
	cout << "Count: " << count << endl;
	return result;
}
Vector2 multMV(const Matrix2x2& matrix, const Vector2& vector) {
	Vector2 result;
	result._1 = matrix._11 * vector._1 + matrix._12 * vector._1;
	result._2 = matrix._21 * vector._2 + matrix._22 * vector._2;
	return result;
}

double matrixFibonaci(unsigned int n) {
	Vector2 vec;
	vec._1 = 1;
	vec._2 = 1;
	Matrix2x2 mat;
	mat._11 = 1;
	mat._12 = 1;
	mat._21 = 1;
	mat._22 = 0;
	Vector2 result = multMV(matrixPow(mat, n - 1), vec);
	return result._2;
}

