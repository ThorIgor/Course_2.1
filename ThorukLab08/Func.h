int zet(double& y, double& x, unsigned int& k);
double power(double x, unsigned int n);
int fib(double& f1, double& f2, unsigned int n);
double Fibonaci(unsigned int n);

struct Matrix2x2 {
	int _11, _12, _21, _22;
};

struct Vector2 {
	int _1, _2;
};


Matrix2x2 matrixPow(const Matrix2x2& matrix, const int& n);
Vector2 multMV(const Matrix2x2& matrix, const Vector2& vector);
double matrixFibonaci(unsigned int n);