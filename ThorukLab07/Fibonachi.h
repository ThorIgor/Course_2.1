struct Matrix2x2 {
	int _11, _12, _21, _22;
};

struct Vector2 {
	int _1, _2;
};


Matrix2x2 matrixPow(const Matrix2x2& matrix, const int& n);
Vector2 multMV(const Matrix2x2& matrix, const Vector2& vector);