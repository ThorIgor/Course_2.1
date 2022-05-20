#include"Fibonachi.h"

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
	for (int i = 1; i < n; (i * 2 < n) ? i *= 2 : i++) {
		if (i * 2 < n)
			result = multM(result, result);
		else
			result = multM(result, matrix);
	}
	return result;
}
Vector2 multMV(const Matrix2x2& matrix, const Vector2& vector) {
	Vector2 result;
	result._1 = matrix._11 * vector._1 + matrix._12 * vector._1;
	result._2 = matrix._21 * vector._2 + matrix._22 * vector._2;
	return result;
}