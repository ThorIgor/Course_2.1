#include<iostream>
#include<cmath>
#include <cassert>

using namespace std;

int recMng(const double& x, const double& y, const double& n) { // 2
	double result = 0;
	for (int i = 0; i <= n; i++) {
		double temp = x*y, dx = x, dy = y;
		for (int j = 0; j <= n; j++) {
			if (j < n - i)
				temp *= dx;
			if (j < i)
				temp *= dy;
			dx *= dx;
			dy *= dy;
		}
		result += temp;
	}
	return result;
}

unsigned int binaryInvert(unsigned int num) { // 3
	unsigned int start_num = num;
	num ^= UINT32_MAX;
	assert(num == ~start_num);
	return num;
}

void toHighRegister(char * word) { // 4
	for (int i = 0; *(word + i) != '\0'; i++) {
		if (*(word + i) > 96 && *(word + i) < 123)
			*(word + i) -= 32;
	}
}

void toLowerRegister(char* word) { // 4
	for (int i = 0; *(word + i) != '\0'; i++)
		if (*(word + i) > 64 && *(word + i) < 91)
			*(word + i) += 32;
}

typedef struct String { //5, 6, 9
	char* _w;
};

bool operator== (const String& a, const String& b) { // 5
	for (int i = 0; true; i++) {
		if (*(a._w + i) == '\0' && *(b._w + i) == '\0')
			return true;
		if (*(a._w + i) != *(b._w + i))
			return false;
	}
}

char toLowerCase(const char ch) { // 6
	if (ch > 64 && ch < 91)
		return ch + 32;
	else
		return ch;
}

bool operator< (const String &a, const String &b) { // 6
	for (int i = 0; *(a._w+i) != '\0' || *(b._w+i) != '\0'; i++) {
		char ch1 = toLowerCase(*(a._w + i));
		char ch2 = toLowerCase(*(b._w + i));
		if (ch1 == ch2)
			continue;
		if (ch1 == '\0')
			return true;
		if (ch2 == '\0')
			return false;
		return ch1 < ch2;
	}
	return false;
}

int countSym(const char* str) { // 7
	int count = 0;
	while (*(str + count) != '\0')
		count++;
	return count;
}

bool Less(const char* s1, const char* s2) { //8
	return countSym(s1) < countSym(s2);
}

void sortByLenth(String* str, size_t s) { // 9
	for (int i = 0; i < s; i++) {
		for (int j = i; j > 0; j--) {
			if (Less(str[j]._w, str[j - 1]._w))
				swap(str[j], str[j - 1]);
			else
				break;
		}
	}
}

void sortByLec(String* str, size_t s) { // 9
	for (int i = 0; i < s; i++) {
		for (int j = i; j > 0; j--) {
			if (str[j] < str[j - 1])
				swap(str[j], str[j - 1]);
			else
				break;
		}
	}
}

template<class T>
void Sort(T* arr, size_t s) { // 10
	for (int i = 0; i < s; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;
		}
	}
}

void main() {
	// 1 -------------------------------- 
	cout << "----------- 1 --------------" << endl;
	{int x = x = 0 ? 1 : 0; cout << x << endl; }
	{int x = 0; cout << x << endl; }

	// 2 --------------------------------
	cout << "----------- 2 --------------" << endl;
	cout << "recMng(2, 2, 3) = " << recMng(2, 2, 3) << endl;

	// 3 --------------------------------
	cout << "----------- 3 --------------" << endl;
	{unsigned int x = 0; 
	unsigned int nx =  binaryInvert(x);
	cout << x << " -> " << nx << endl;}

	// 4 --------------------------------
	cout << "----------- 4 --------------" << endl;
	{char* word = new char[] {"Hello __ World"};
	cout << word << endl;
	toLowerRegister(word);
	cout << word << endl;
	toHighRegister(word);
	cout << word << endl; }

	// 5 --------------------------------
	cout << "----------- 5 --------------" << endl;
	{String s1; s1._w = new char[] {"Hello"};
	String s2; s2._w = new char[] {"Hello"};
	if (s1 == s2)
		cout << "s1 == s2" << endl;
	else
		cout << "s1 != s2" << endl; }

	// 6 --------------------------------
	cout << "----------- 6 --------------" << endl;
	String a; a._w = new char[] {"afgD"};
	String b; b._w = new char[] {"aFg"};
	if (a < b)
		cout << a._w << " < " << b._w << endl;
	else
		cout << a._w << " > " << b._w << endl;

	// 7 --------------------------------
	cout << "----------- 7 --------------" << endl;
	cout << countSym(a._w) << endl;

	// 8 --------------------------------
	cout << "----------- 8 --------------" << endl;
	if (Less(a._w, b._w))
		cout << a._w << " less then " << b._w << endl;
	else
		cout << a._w << " not less then " << b._w << endl;

	// 9 --------------------------------
	cout << "----------- 9 --------------" << endl;
	String str[5];
	str[0] = b;
	str[1] = a;
	str[2]._w = new char[] {"Betman"};
	str[3]._w = new char[] {"bdSm"};
	str[4]._w = new char[] {"Hello"};
	sortByLenth(str, 5);
	cout << "By lenth: " << endl;
	for (String s : str)
		cout << s._w << " ";
	cout << endl;
	sortByLec(str, 5);
	cout << "By lecsic: " << endl;
	for (String s : str)
		cout << s._w << " ";
	cout << endl;

	// 10 -------------------------------
	cout << "----------- 10 -------------" << endl;
	int arr[5] = { 1,98, 45, 23, 67 };
	Sort(arr, 5);
	for (int i : arr)
		cout << i << " ";
	cout << endl;
}
