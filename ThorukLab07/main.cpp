#include<iostream>
#include"Fibonachi.h"

using namespace std;

void main() {
	int n;
	cout << "N(n > 2): ";
	cin >> n;
	if (n <= 2)
		return;
	Vector2 fib; 
	fib._1 = 1;
	fib._2 = 1;
	Matrix2x2 mat;
	mat._11 = 1;
	mat._12 = 1;
	mat._21 = 1;
	mat._22 = 0;
	Vector2 result = multMV(matrixPow(mat, n-1), fib);
	cout << "Result: (" << result._1 << ", " << result._2 << ")" << endl;

}