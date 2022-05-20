
template<class T>
void swap(T &a, T &b) {
	T pr = a;
	a = b;
	b = pr;
	return;
}
void sort(double* arr, const size_t size) {
	for (int i = 0; i < size; i++) {
		for (int j = i; j > 0; j--)
			if (*(arr + j) < *(arr + j - 1))
				swap(*(arr + j), *(arr + j - 1));
	}
}
bool sorted(const double* arr, const double* sarr, const size_t size) {
	bool *dopArr = new bool[size];
	bool find;
	for (int i = 1; i < size; i++) {
		find = false;
		for (int j = 0; j < size; j++) {
			if (arr[j] == sarr[i] && dopArr[j] != true)
			{
				dopArr[j] = true;
				find = true;
				break;
			}
		}
		if (!find)
			return false;
		if (*(sarr + i - 1) > * (sarr + i))
			return false;
	}
	return true;
}